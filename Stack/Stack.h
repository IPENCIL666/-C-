#ifndef _MYSTACK_H
#define _MYSTACK_H

#include <iostream>

// MyStack可以避免和C++已经做的Stack类重名
template<class T>
class MyStack
{
public:
	MyStack(int stackCapacity = 10);
	~MyStack();
	bool IsEmpty() const; // 判断栈是否为空
	T& Top() const; // 返回栈顶元素(并不删除)
	void Push(const T& item); // 入栈操作
	void Pop(); // 删除栈顶元素
private:
	T *stack;
	int top; // 栈顶索引
	int capacity; // 容量

};

template<class T>
MyStack<T>::MyStack(int stackCapacity):capacity(stackCapacity)
{
	if (capacity < 1) throw "stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template<class T>
MyStack<T>::~MyStack()
{
	delete[] stack;
}

template<class T>
void MyStack<T>::Push(const T& item) // 入栈操作
{
	if (top == capacity-1)
	{
		ChangeSize1D(stack, capacity, 2*capacity);
	}
	stack[++top] = item;
}

template<class T>
inline bool MyStack<T>::IsEmpty() const
{
	return top == -1;
}

template<class T>
inline T& MyStack<T>::Top() const
{
	if (IsEmpty()) throw "Stack is empty";
	return stack[top];
}

template<class T>
void MyStack<T>::Pop()
{
	if (IsEmpty()) 
		throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}
#endif 
