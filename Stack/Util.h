#ifndef _MYUTIL_H
#define _MYUTIL_H

#include <iostream>

// 放大数组
template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize);

template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int number = oldSize < newSize ? oldSize : newSize;
	std::copy(a, a+number, temp);
	delete[] a;
	a = temp;
}
#endif
