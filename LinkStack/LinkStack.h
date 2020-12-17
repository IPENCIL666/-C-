#ifndef LINKSTACK_H
#define LINKSTACK_H

template<class T> class LinkStack;

template<class T>
class ChainNode
{
public:
	friend class LinkStack<T>;
private:
	ChainNode(const T& theData, ChainNode *n = 0):data(theData),link(n){};  // 构造函数 初始化列表
	T data;  
	ChainNode<T> *link;
};

template<class T>
class LinkStack
{
public:
	LinkStack():top(0){};  // 构造函数 初始化列表
	~LinkStack(){ MakeEmpty(); };  // 析构函数

	T& Top() const;  // 获取栈顶元素
	void Push(const T& e);  // 入栈
	void Pop();  // 出栈
	bool IsEmpty() const;  // 判断栈是否为空
	void MakeEmpty();  // 析构
private:
	ChainNode<T> *top;  // 栈顶索引
};

/* 判空 */
template<class T>
bool LinkStack<T>::IsEmpty() const
{
	return top == 0;
}

/* 入栈 */
template<class T>
void LinkStack<T>::Push(const T &e)
{
	top = new ChainNode<T>(e, top);
}

/* 查看栈顶元素 */
template<class T>
T& LinkStack<T>::Top() const
{
	if (this->IsEmpty())
		throw "Stack is empty";
	return top->data;
}

/* 出栈 */
template<class T>
void LinkStack<T>::Pop()
{
	if(this->IsEmpty())
		throw "Stack is empty. Cannot delete.";
	ChainNode<T> *delNode = top;
	top = top->link;
	delete delNode;
}

template<class T>
void LinkStack<T>::MakeEmpty()
{
	while(!IsEmpty())
		Pop();
}
#endif
