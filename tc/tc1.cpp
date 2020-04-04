#include <iostream>
#include <string>
using namespace std;

int char2i(const char c)
{
    if ('0' <= c && c <= '9')
    {
        return c - '0';
    }
    if ('A' <= c && c <= 'Z')
    {
        return 10 + (c - 'A');
    }

    return 0;
}

void func1(const string &num1, const string &num2, const string &num3)
{
    int max = 1;
    for (auto it = num1.begin(); it != num1.end(); it++)
    {
        int tmp = char2i(*it);
        if (tmp > max)
        {
            max = tmp;
        }
    }
    for (auto it = num2.begin(); it != num2.end(); it++)
    {
        int tmp = char2i(*it);
        if (tmp > max)
        {
            max = tmp;
        }
    }
    for (auto it = num3.begin(); it != num3.end(); it++)
    {
        int tmp = char2i(*it);
        if (tmp > max)
        {
            max = tmp;
        }
    }
    max += 1;

    for (int i = max; i <= 20; i++)
    {
        int sum1 = 0;
        for (auto it = num1.begin(); it != num1.end(); it++)
        {
            sum1 = i * sum1 + char2i(*it);
        }
        int sum2 = 0;
        for (auto it = num2.begin(); it != num2.end(); it++)
        {
            sum2 = i * sum2 + char2i(*it);
        }
        int sum3 = 0;
        for (auto it = num3.begin(); it != num3.end(); it++)
        {
            sum3 = i * sum3 + char2i(*it);
        }
        if (sum1 + sum2 == sum3)
        {
            cout << i << endl;
        }
    }
}

void func2(const string &num1, const string &num2, const string &num3)
{
    int i = 2;
    int length1 = num1.length() - 1;
    int length2 = num2.length() - 1;
    int length3 = num3.length() - 1;

    while (i <= 20)
    {
        int carry = 0;
        bool valid = true;
        for (int j = 0; j <= length3; j++)
        {
            int sum = carry;
            if (j <= length1)
            {
                int tmp = char2i(num1[length1 - j]);
                if (i <= tmp)
                {
                    i = tmp + 1;
                }
                sum += tmp;
            }
            if (j <= length2)
            {
                int tmp = char2i(num2[length2 - j]);
                if (i <= tmp)
                {
                    i = tmp + 1;
                }
                sum += tmp;
            }
            int tmp3 = char2i(num3[length3 - j]);
            if (i <= tmp3)
            {
                i = tmp3 + 1;
            }
            // cout << i << ' ' << tmp3 << ' ' << sum << endl;
            if (sum % i != tmp3)
            {
                valid = false;
                break;
            }
            carry = sum / i;
        }
        if (valid)
        {
            cout << i << endl;
        }
        i++;
    }
}

int main()
{
    string nums1[] = {"ABCD", "1"};
    string nums2[] = {"211", "1"};
    string nums3[] = {"B000", "2"};
    cout << "test func1" << endl;
    func1(nums1[0], nums2[0], nums3[0]);
    func1(nums1[1], nums2[1], nums3[1]);
    cout << "test func2" << endl;
    func2(nums1[0], nums2[0], nums3[0]);
    func2(nums1[1], nums2[1], nums3[1]);
}
