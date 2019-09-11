#include <iostream>
// #include <ctime>
#include <sys/time.h>

using namespace std;

// 二分查找，找到该值在数组中的下标，否则为-1
int binarySerach(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

// 查找第一个相等的元素
int findFirstEqual(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] >= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if ((left < n) && (A[left] == key))
    {
        return left;
    }

    return -1;
}

// 查找最后一个相等的元素
int findLastEqual(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] <= key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if ((right >= 0) && (A[right] == key))
    {
        return right;
    }

    return -1;
}

// 查找最后一个等于或者小于key的元素
int findLastEqualSmaller(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return right;
}

// 查找最后一个小于key的元素
int findLastSmaller(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] >= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return right;
}

// 查找第一个等于或者大于key的元素
int findFirstEqualLarger(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] >= key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

// 查找第一个大于key的元素
int findFirstLarger(int A[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

typedef int (*pFunc)(int A[], int n, int key);

int Arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void testFind(pFunc f, int A[], int n)
{
    for (int i = -1; i < n + 1; ++i)
    {
        cout << i << ':' << f(A, n, i) << "; ";
    }
    cout << endl;
}

void testFindTime(pFunc f, int A[], int n)
{
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    long count = 1000000;
    for (int i = 0; i < count; ++i)
    {
        for (int i = -1; i < n + 1; ++i)
        {
            f(A, n, i);
        }
    }
    gettimeofday(&tv_end, NULL);
    long tsBegin = tv_begin.tv_sec * 1000000 + tv_begin.tv_usec;
    long tsEnd = tv_end.tv_sec * 1000000 + tv_end.tv_usec;
    double timeSpan = double(tsEnd - tsBegin) / 1000000;
    cout << count << ':' << timeSpan << endl;
}

int main()
{
    int n = sizeof(Arr) / sizeof(int);
    testFind(binarySerach, Arr, n);

    int A2[] = {0, 1, 1, 3, 3, 3, 6, 7, 8, 9};
    int n2 = sizeof(A2) / sizeof(int);
    testFind(findFirstEqual, A2, n2);
    testFind(findLastEqual, A2, n2);
    testFind(findLastEqualSmaller, A2, n2);
    testFind(findLastSmaller, A2, n2);
    testFind(findFirstEqualLarger, A2, n2);
    testFind(findFirstLarger, A2, n2);

    testFindTime(binarySerach, Arr, n);

    return 0;
}
