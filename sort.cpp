#include <iostream>
// #include <ctime>
#include <sys/time.h>
#include <malloc.h>

using namespace std;

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 冒泡排序(Bubble Sort)
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
                Swap(A,j,j+1);
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
                Swap(A,i,i+1);
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
                Swap(A,i,i-1);
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

// 选择排序(Selection Sort)
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
            Swap(A,i,min);
        }
    }
}

// 插入排序(Insertion Sort)
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
void MergeSortIteration(int A[], int len)   // 非递归(迭代)实现的归并排序(自底向上)
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

void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
    int left_child = 2 * i + 1;         // 左孩子索引
    int right_child = 2 * i + 2;        // 右孩子索引
    int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
    if (left_child < size && A[left_child] > A[max])
        max = left_child;
    if (right_child < size && A[right_child] > A[max])
        max = right_child;
    if (max != i)
    {
        Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
        Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
    }
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
        Heapify(A, i, heap_size);
    return heap_size;
}

// 堆排序(Heap Sort)
void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // 建立一个最大堆
    while (heap_size > 1)               // 堆（无序区）元素个数大于1，未完成排序
    {
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        Swap(A, 0, --heap_size);
        Heapify(A, 0, heap_size);       // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
}

int Partition(int A[], int left, int right)  // 划分函数
{
    int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

// 快速排序(Quick Sort)
void QuickSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(A, left, right); // 基准的索引
    QuickSort(A, left, pivot_index - 1);
    QuickSort(A, pivot_index + 1, right);
}

void QuickSort2(int A[], int n)
{
    QuickSort(A, 0, n-1);
}

const int k = 100;   // 基数为100，排序[0,99]内的整数
int C[k];            // 计数数组

// 计数排序(Counting Sort)
void CountingSort(int A[], int n)
{
    for (int i = 0; i < k; i++)   // 初始化，将数组C中的元素置0(此步骤可省略，整型数组元素默认值为0)
    {
        C[i] = 0;
    }
    for (int i = 0; i < n; i++)   // 使C[i]保存着等于i的元素个数
    {
        C[A[i]]++;
    }
    for (int i = 1; i < k; i++)   // 使C[i]保存着小于等于i的元素个数，排序后元素i就放在第C[i]个输出位置上
    {
        C[i] = C[i] + C[i - 1];
    }
    int *B = (int *)malloc((n) * sizeof(int));// 分配临时空间,长度为n，用来暂存中间数据
    for (int i = n - 1; i >= 0; i--)    // 从后向前扫描保证计数排序的稳定性(重复元素相对次序不变)
    {
        B[--C[A[i]]] = A[i];      // 把每个元素A[i]放到它在输出数组B中的正确位置上
                                  // 当再遇到重复元素时会被放在当前元素的前一个位置上保证计数排序的稳定性
    }
    for (int i = 0; i < n; i++)   // 把临时空间B中的数据拷贝回A
    {
        A[i] = B[i];
    }
    free(B);    // 释放临时空间
}

const int dn = 3;                // 待排序的元素为三位数及以下
const int k2 = 10;               // 基数为10，每一位的数字都是[0,9]内的整数
int C2[k2];

int GetDigit(int x, int d)          // 获得元素x的第d位数字
{
    int radix[] = { 1, 1, 10, 100 };// 最大为三位数，所以这里只要到百位就满足了
    return (x / radix[d]) % 10;
}

void CountingSort2(int A[], int n, int d)    // 依据元素的第d位数字，对A数组进行计数排序
{
    for (int i = 0; i < k2; i++)
    {
        C2[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        C2[GetDigit(A[i], d)]++;
    }
    for (int i = 1; i < k2; i++)
    {
        C2[i] = C2[i] + C2[i - 1];
    }
    int *B = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = GetDigit(A[i], d);  // 元素A[i]当前位数字为digit
        B[--C2[digit]] = A[i];          // 根据当前位数字，把每个元素A[i]放到它在输出数组B中的正确位置上
        // 当再遇到当前位数字同为digit的元素时，会将其放在当前元素的前一个位置上保证计数排序的稳定性
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

// 基数排序(Radix Sort)
void LsdRadixSort(int A[], int n)     // 最低位优先基数排序
{
    for (int d = 1; d <= dn; d++)     // 从低位到高位
        CountingSort2(A, n, d);        // 依据第d位数字对A进行计数排序
}

/* 本程序用数组模拟桶 */
const int bn = 10;    // 这里排序[0,99]的元素，使用10个桶就够了，也可以根据输入动态确定桶的数量
int Cb[bn];          // 计数数组，存放桶的边界信息

void InsertionSort2(int A[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)  // 从第二张牌开始抓，直到最后一张牌
    {
        int get = A[i];
        int j = i - 1;
        while (j >= left && A[j] > get)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get;
    }
}

int MapToBucket(int x)
{
    return x / 10;    // 映射函数f(x)，作用相当于快排中的Partition，把大量数据分割成基本有序的数据块
}

void CountingSortb(int A[], int n)
{
    for (int i = 0; i < bn; i++)
    {
        Cb[i] = 0;
    }
    for (int i = 0; i < n; i++)     // 使C[x]保存着x号桶中元素的个数
    {
        Cb[MapToBucket(A[i])]++;
    }
    for (int i = 1; i < bn; i++)    // 定位桶边界：初始时，C[i]-1为i号桶最后一个元素的位置
    {
        Cb[i] = Cb[i] + Cb[i - 1];
    }
    int *B = (int *)malloc((n) * sizeof(int));
    for (int i = n - 1; i >= 0; i--)// 从后向前扫描保证计数排序的稳定性(重复元素相对次序不变)
    {
        int b = MapToBucket(A[i]);  // 元素A[i]位于b号桶
        B[--Cb[b]] = A[i];          // 把每个元素A[i]放到它在输出数组B中的正确位置上
                                    // 桶的边界被更新：C[b]为b号桶第一个元素的位置
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
    free(B);
}

// 桶排序(Bucket Sort)
void BucketSort(int A[], int n)
{
    CountingSortb(A, n);         // 利用计数排序确定各个桶的边界（分桶）
    for (int i = 0; i < bn; i++) // 对每一个桶中的元素应用插入排序
    {
        int left = Cb[i];         // C[i]为i号桶第一个元素的位置
        int right = (i == bn - 1 ? n - 1 : Cb[i + 1] - 1);// C[i+1]-1为i号桶最后一个元素的位置
        if (left < right)        // 对元素个数大于1的桶进行桶内插入排序
            InsertionSort2(A, left, right);
    }
}

typedef void (*pFunc)(int A[], int n);

int Arr[] = {   47, 40, 43, 35,  2, 51, 39, 11, 95, 20, 98, 19, 25, 64, 48, 75, 79, 13, 75, 75,
                33, 99, 13, 84, 35, 27, 59, 89, 21, 89, 61, 25, 60, 21, 52, 39,  0, 73, 21, 42,
                29, 29, 73, 51, 17, 23, 72, 28, 18, 85, 32,  3, 50, 21, 62, 35, 18, 92, 39, 23,
                29, 43, 93, 57,  3, 46, 57, 41, 44, 21, 48, 77, 48, 66, 69, 55, 67, 19, 38, 72,
                78,  5, 60, 78, 86,  1, 44, 73, 14, 67, 14, 19,  7, 35, 74, 90, 84, 51, 15, 19 };
int Arr2[] = { 20, 90, 64, 289, 998, 365, 852, 123, 789, 456 };

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

void testSort2(pFunc f)
{
    int n = sizeof(Arr2)/sizeof(int);
    f(Arr2, n);
    for (int i = 0; i < n; ++i)
    {
        cout << Arr2[i] << ' ';
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
    testSort(HeapSort);
    testSort(QuickSort2);
    testSort(CountingSort);
    testSort2(LsdRadixSort);
    testSort(BucketSort);

    testSortTime(BubbleSort);
    testSortTime(CocktailSort);
    testSortTime(SelectionSort);
    testSortTime(InsertionSort);
    testSortTime(InsertionSortDichotomy);
    testSortTime(ShellSort);
    testSortTime(MergeSortRecursion2);
    testSortTime(MergeSortIteration);
    testSortTime(HeapSort);
    testSortTime(QuickSort2);
    testSortTime(CountingSort);
    testSortTime(BucketSort);

    return 0;
}
