#include "Stack.h"
#include "Util.h"

template<class T>
MyStack<T>::MyStack(int stackCapacity):capacity(stackCapacity)
{
	if (capacitity < 1) throw "stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}
