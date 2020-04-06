/*
bb 2015/6/15 19:11:45
1、a[n]为n个互不相同的整数组成的数组,要求输出同时满足下面两个条件的整数，要求时间复杂度O(n)，不能用递归
（1）比前面所有的整数都大
（2）比后面所有的整数都小
*/
int findN0(int *arr, int n)
{
	if (arr == NULL) return 0;
	int *arr2 = new int[n];
	int id = 0;
	arr2[id++] = arr[0];
	
	int max = arr[0];
	int i;
	
	for (i = 1; i <=n; i++)
	{
		if (arr[i] > max)
		{
			arr2[id++] = arr[i];
			max = arr[i];
		}
		else
		{
			while (id>0 && arr2[id-1] >= arr[i])
			{
				id--;
			}
		}
		
	}
	
	for (i = 0; i<id; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	
	delete []arr2;
	return id;
}
/*
2、c语言编码：不借助其他库，在c语言里，将一个正整数转化为对应的二进制字符串
*/

void int2str(unsigned int a, char *str)
{
	int num = a;
	int len = 0, mid = 0;
	int i = 0, j = 0;
	char temp;
	do
	{
		*str++ = num%10 + '0';
		num /= 10;
		i++;
	}while (num)
	*str = '\0';
	len = i+1;
	mid = i/2;
	while (i>=mid && j<mid)
	{
		temp = str[i]
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	str[len] = '\0';
}


/*
3、c语言编码：我现在有一段明文和它对应的TEA对称密钥算法加密后的密文，但我不知道密钥是什么。已知TEA对称密钥加密算法的密钥是128 bits的，我希望遍历所有密钥的可能值，尝试对这段明文加密后是否等于密文，来达到找出密钥的目的（暴力破解）。请写出遍历所有密钥的可能值的代码。不能用递归
*/

#define MAXLONGLONG 0xFFFFFFFFFFFFFFFF
int deKey()
{
	str *strMing = g_sMing;
	str *strMiwen = g_sMiwen;
	unsigned long long arrMiyue[2] = {0};
	while (arrMiyue[0] <= MAXLONGLONG && arrMiyue[1] <= MAXLONGLONG)
	{
		if (strcmp(decode(strMiwen, arrMiyue), strMing) == 0)
		{
			printf("%ull %ull\n", arrMiyue[0], arrMiyue[1]);
		}
		
		arrMiyue[0]++;
		if ( arrMiyue[0] == 0)
		{
			arrMiyue[1]++;
		}
	}
}
