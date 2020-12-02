#ifndef _MYSTACK_H
#define _MYSTACK_H

// MyStack可以避免和C++已经做的Stack类重名
template<class T>
class MyStack
{
public:
	MyStack(int stackCapacity = 10);
	bool IsEmpty() const; // 判断栈是否为空
	T& Top() const; // 返回栈顶元素(并不删除)
	void Push(const T& item); // 入栈操作
	void Pop(); // 删除栈顶元素
private:
	T *stack;
	int top; // 栈顶索引
	int capacity; // 容量

};

#endif 
