#include "Util.h"

template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	std::copy(a, a+number, temp);
	delete[] a;
}
