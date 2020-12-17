#ifndef LINKSTACK_H
#define LINKSTACK_H

template<class T> class LinkStack;

template<class T>
class ChainNode
{
public:
	friend class LinkStack<T>;
private:
	ChainNode(const T& theData, ChainNode *n = 0):data(theData),link(n){};
	T data;
	ChainNode<T> *link;
};

template<class T>
class LinkStack
{
public:
	LinkStack():top(0){};
	//~LinkStack(){ MakeEmpty(); };

	T& Top() const;
	void Push(const T& e);
	void Pop();
	bool IsEmpty() const;
	void MakeEmpty();
private:
	ChainNode<T> *top;
};

template<class T>
bool LinkStack<T>::IsEmpty() const
{
	return top == 0;
}

template<class T>
void LinkStack<T>::Push(const T &e)
{
	top = new ChainNode<T>(e, top);
}

template<class T>
T& LinkStack<T>::Top() const
{
	if (this->IsEmpty())
		throw "Stack is empty";
	return top->data;
}

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
