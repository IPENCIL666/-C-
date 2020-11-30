#include <iostream>

using namespace std;

void merge(int arr[], int L, int M, int R)
{
	/* 归并
	 * arr[]:归并数组
	 * L: 开始元素的索引
	 * M: 中间元素的索引
	 * R: 结束元素的索引
	 */

	int LEFT_SIZE = M - L;  			//左边数组大小	
	int RIGHT_SIZE = R - M + 1; 		//右边数组大小
	int left[LEFT_SIZE];				// 定义左边数组
	int right[RIGHT_SIZE];				// 定义右边数组
	int i, j, k;
	
	// 1.填上左边的数组
	for(int i = 0; i < M; i++)
	{
		left[i-L] = arr[i];
	}
	// 2.填上右边的数组
	for(int i = M; i <= R; i++)
	{
		right[i-M] = arr[i];
	}

//	for (int i = 0; i < LEFT_SIZE; i++)
//		cout << right[i] << " ";
//	cout << endl;
	
	// 3.归并
	i = 0; // left[]数组的索引
	j = 0; // right[]数组的索引
	k = L; // arr[]数组的索引
	while (i < LEFT_SIZE && j < RIGHT_SIZE)
	{
		if (left[i] < right[j]){
			arr[k] = left[i];
			i++;
			k++;
		} else {
			arr[k] = right[j];
			j++;
			k++;
		}
	}

	// 4.一个数组为空，另一个不为空时,把还有剩余的那个数组的剩余部分加入arr[]
	while (i < LEFT_SIZE) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < RIGHT_SIZE) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int L, int R)
{
	/* 归并排序
	 * arr[]:归并数组
	 * L: 开始元素的索引
	 * R: 结束元素的索引
	 */
	if (L == R){
		return;
	} else {
		int M = (L + R)/2;	
		mergeSort(arr, L, M);
		mergeSort(arr, M+1, R);
		merge(arr, L, M+1, R);
	}		
}

int main()
{
	int arr[] = {6, 8, 10, 9, 4, 5, 2, 7};
	int L = 0; // 开始下标
	int R = 7; // 结束下标

	mergeSort(arr, L, R);

	for (int i = 0; i <= R; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
