#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
void Merge(T *initList, T *mergedList, const int l, const int m, const int n)
{
	/* 归并
	 * initList: 初始数组 
	 * mergedList: 归并后的数组
	 * l: 第一数组开始下标
	 * m: 第一个数组结束下标
	 * n: 数组中数的个数
	 */
	int i1, i2, iResult;
	for (i1 = l, i2 = m+1, iResult = l; i1 <= m && i2 <= n; iResult++)
	{
		if(initList[i1] <= initList[i2])
		{
			mergedList[iResult] = initList[i1];
			i1++;
		} else {
			mergedList[iResult] = initList[i2];
			i2++;
		}
	}
	// 将剩下没有排序的拷贝到mergedList数组中
	copy(initList+i1, initList+m+1, mergedList+iResult);
	copy(initList+i2, initList+n+1, mergedList+iResult);
}

template<class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{
	/* 归并排序
	 * initList: 初始数组 
	 * mergedList: 归并后的数组
	 * n: 数组中数的个数
	 * s: 当前数组的长度
	 */
	int i;
	for(i = 1; i <= n-2*s+1; i+=2*s)
		Merge(initList, resultList, i, i+s-1, i+2*s-1);
	if((i+s-1) < n)
		Merge(initList, resultList, i, i+s-1, n);
	else
		copy(initList+i, initList+n+1, resultList+i);
}

template<class T>
void MergeSort(T *a, const int n)
{
	/* 归并排序
	 * a: 初始数组
	 * n: 数组大小
	 */
	T *tempList = new int[n+1]; // tempList[0] 不用	
	for (int l = 1; l < n; l *= 2)
	{
		MergePass(a, tempList, n, l);
		l *= 2;
		MergePass(tempList, a, n, l);
	}
	delete[] tempList;
}

int main()
{
	// a[]初始化数组 a[0]不用
	int a[] = {0, 23, 47, 81, 96, 7, 14, 39, 55, 62, 75};
	// b[]归并数组
	int b[11] = {0};
	Merge(a, b, 1, 4, 10);
	for(int i = 1; i < 10; ++i)
		cout << b[i] << " ";
	cout << endl;

	int m[] = {0, 26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
	int n[] = {0};

	MergePass(m, n, 10, 1);
	for(int i=1; i<11; i++)
		cout << n[i] << " ";
	cout << endl;

	MergePass(n, m, 10, 2);
	for(int i=1; i<11; i++)
		cout << m[i] << " ";
	cout << endl;

	MergePass(m, n, 10, 4);
	for(int i=1; i<11; i++)
		cout << n[i] << " ";
	cout << endl;

	MergePass(n, m, 10, 8);
	for(int i=1; i<11; i++)
		cout << m[i] << " ";
	cout << endl;

	cout << "上面是测试代码" << endl;
	cout << "下面开始MergeSort" << endl;
	int x[] = {0, 26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
	MergeSort(x, 10);
	for(int i = 1; i < 11; i++)
		cout << x[i] << " ";
	cout << endl;

	cout << "OK" << endl;
	return 0;
}
