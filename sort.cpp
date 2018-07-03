#include <iostream>
// #include <ctime>
#include <sys/time.h>

using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 冒泡排序
void BubbleSort(int A[], int n)
{
    bool swapFlag = false;
    for (int i = 0; i < n-1; ++i)
    {
        swapFlag = false;
        for (int j = 0; j < n-1-i; ++j)
        {
            if (A[j] > A[j+1])
            {
                swap(A,j,j+1);
                swapFlag = true;
            }
        }
        if (swapFlag == false)
        {
            break;
        }
    }
}

// 冒泡排序的改进：鸡尾酒排序
void CocktailSort(int A[], int n)
{
    bool swapFlag = false;
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        swapFlag = false;
        for (int i = 0; i < right; ++i)
        {
            if (A[i] > A[i+1])
            {
                swap(A,i,i+1);
                swapFlag = true;
            }
        }
        if (swapFlag == false)
        {
            break;
        }
        right--;

        swapFlag = false;
        for (int i = right; i > left; --i)
        {
            if (A[i] < A[i-1])
            {
                swap(A,i,i-1);
                swapFlag = true;
            }
        }
        if (swapFlag == false)
        {
            break;
        }
        left++;
    }
}

// 选择排序
void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        int min = i;
        for (int j = i+1; j < n; ++j)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(A,i,min);
        }
    }
}

// 插入排序
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int get = A[i];
        int j = i-1;
        while ((j >= 0) && (get < A[j]))
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = get;
    }
}

// 插入排序的改进：二分插入排序
void InsertionSortDichotomy(int A[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int get = A[i];
        int left = 0;
        int right = i-1;
        while (left <= right)
        {
            int mid = (left+right)/2;
            if (get < A[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        for (int j = i-1; j >= left; --j)
        {
            A[j+1] = A[j];
        }
        A[left] = get;
    }
}

// 插入排序的更高效改进：希尔排序(Shell Sort)
void ShellSort(int A[], int n)
{
    int h = 0;
    while (h <= n/3)                       // 生成初始增量
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < n; ++i)
        {
            int get = A[i];
            int j = i-h;
            while ((j >= 0) && (get < A[j]))
            {
                A[j+h] = A[j];
                j = j-h;
            }
            A[j+h] = get;
        }
        h = (h - 1)/3;
    }
}

void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
    delete []temp;
}

// 归并排序(Merge Sort): 递归实现
void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}
void MergeSortRecursion2(int A[], int len)
{
    MergeSortRecursion(A, 0, len-1);
}

// 归并排序(Merge Sort): 非递归(迭代)实现
void MergeSortIteration(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
    int left, mid, right;                   // 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
    {
        left = 0;
        while (left + i < len)              // 后一个子数组存在(需要归并)
        {
            mid = left + i - 1;
            right = (mid + i) < len ? (mid + i) : (len - 1);    // 后一个子数组大小可能不够
            Merge(A, left, mid, right);
            left = right + 1;               // 前一个子数组索引向后移动
        }
    }
}

// 归并排序(Merge Sort): 非递归(迭代)实现

typedef void (*pFunc)(int A[], int n);

int Arr[] = {   47, 40, 43, 35,  2, 51, 39, 11, 95, 20, 98, 19, 25, 64, 48, 75, 79, 13, 75, 75,
                33, 99, 13, 84, 35, 27, 59, 89, 21, 89, 61, 25, 60, 21, 52, 39,  0, 73, 21, 42,
                29, 29, 73, 51, 17, 23, 72, 28, 18, 85, 32,  3, 50, 21, 62, 35, 18, 92, 39, 23,
                29, 43, 93, 57,  3, 46, 57, 41, 44, 21, 48, 77, 48, 66, 69, 55, 67, 19, 38, 72,
                78,  5, 60, 78, 86,  1, 44, 73, 14, 67, 14, 19,  7, 35, 74, 90, 84, 51, 15, 19 };

void testSort(pFunc f)
{
    int n = sizeof(Arr)/sizeof(int);
    f(Arr, n);
    for (int i = 0; i < n; ++i)
    {
        cout << Arr[i] << ' ';
    }
    cout << endl;
}

void testSortTime(pFunc f)
{
    int n = sizeof(Arr)/sizeof(int);
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    long count = 1000000;
    for (int i = 0; i < count; ++i)
    {
        f(Arr, n);
    }
    gettimeofday(&tv_end, NULL);
    long tsBegin = tv_begin.tv_sec*1000000 + tv_begin.tv_usec;
    long tsEnd = tv_end.tv_sec*1000000 + tv_end.tv_usec;
    double timeSpan = double(tsEnd-tsBegin) / 1000000;
    cout << count << ':' << timeSpan << endl;
}

int main ()
{
    testSort(BubbleSort);
    testSort(CocktailSort);
    testSort(SelectionSort);
    testSort(InsertionSort);
    testSort(InsertionSortDichotomy);
    testSort(ShellSort);
    testSort(MergeSortRecursion2);
    testSort(MergeSortIteration);

    testSortTime(BubbleSort);
    testSortTime(CocktailSort);
    testSortTime(SelectionSort);
    testSortTime(InsertionSort);
    testSortTime(InsertionSortDichotomy);
    testSortTime(ShellSort);
    testSortTime(MergeSortRecursion2);
    testSortTime(MergeSortIteration);

    return 0;
}
