#include <iostream>
#include <string>

using namespace std;

/* 字符串下标始于 0 */
int NaiveStringSearch(string S, string P)
{
    int i = 0;    // S 的下标
    int j = 0;    // P 的下标
    int s_len = S.size();
    int p_len = P.size();

    while (i < s_len && j < p_len)
    {
        if (S[i] == P[j])  // 若相等，都前进一步
        {
            i++;
            j++;
        }
        else               // 不相等
        {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == p_len)        // 匹配成功
        return i - j;

    return -1;
}

/* P 为模式串，下标从 0 开始 */
void GetNext(string P, int next[])
{
    int p_len = P.size();
    int i = 0;   // P 的下标
    int j = -1;
    next[0] = -1;

    while (i < p_len - 1)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

/* P 为模式串，下标从 0 开始 */
void GetNextval(string P, int nextval[])
{
    int p_len = P.size();
    int i = 0;   // P 的下标
    int j = -1;
    nextval[0] = -1;

    while (i < p_len - 1)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;

            if (P[i] != P[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];  // 既然相同就继续往前找真前缀
        }
        else
            j = nextval[j];
    }
}

/* 在 S 中找到 P 第一次出现的位置 */
int KMP(string S, string P, int next[])
{
    // GetNext(P, next);
    GetNextval(P, next);

    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = S.size();
    int p_len = P.size();

    while (i < s_len && j < p_len)
    {
        if (j == -1 || S[i] == P[j])  // P 的第一个字符不匹配或 S[i] == P[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];  // 当前字符匹配失败，进行跳转
    }

    if (j == p_len)  // 匹配成功
        return i - j;

    return -1;
}


int main()
{
    string S = "bbc abcdab abcdabcdabde";
    string P = "abcdabd";
    int next[P.size()] = { 0 };

    for (int i = 0; i < S.size(); ++i)
    {
        cout << i%10;
    }
    cout << endl;

    cout << S << endl;
    cout << P << endl;

    cout << "NaiveStringSearch:" << NaiveStringSearch(S, P) << endl;
    cout << "KMP:" << KMP(S, P, next) << endl;

    return 0;
}
