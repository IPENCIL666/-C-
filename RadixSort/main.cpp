#include <iostream>
#include <list>

using namespace std;

int maxdigit(int data[], int n)
{
	int d = 1;  // 计位器: 1 1位数 2 两位数
	int p = 10; // 倍数
	// 求数组中最高位的的位数
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}		
	cout << "maxdigit:" << d << endl;
	// 返回最高位的位数
	return d;
}

void radixsort(int data[], int n)
{
	// 获取最高位的位数
	int digits = maxdigit(data, n);	
	list<int> lists[10];
	int d, j, k, factor; 
	for(d = 1, factor=1; d<= digits; factor*=10, d++)
	{
		for(j = 0; j < n; j++)
		{
			lists[(data[j]/factor) %10].push_back(data[j]);
		}
		for(j = k = 0; j < 10; j++)
		{
			while(!lists[j].empty())
			{
				data[k++] = lists[j].front();
				lists[j].pop_front();
			}
		}
	//	cout << "中间结果:" << endl;
	//	for(int m = 0; m < n; m++)
	//		cout << data[m] << " ";
	//	cout << endl;
	}
}

int main()
{
	int data[10] = {179, 208, 306, 93, 859, 984, 55, 9, 271, 33};
	radixsort(data, 10);

	cout << "排序后结果:" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;

	cout << "test" << endl;
	return 0;
}

