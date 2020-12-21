#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

template<class T>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty() const;
	const T & getFront() const;  // 查看队头
	void enqueue(const T & x); // 入队
	T dequeue(); // 出队
	void makeEmpty(); // 把队列清除
private:
	struct ListNode
	{
		T element;
		ListNode *next;

		ListNode(const T & theElement, ListNode *n = 0)
			:element(theElement),next(n){}
	};

	ListNode *front; // 头
	ListNode *back; // 尾
};

template<class T>
Queue<T>::Queue()
{
	front = back = 0;
}

template<class T>
Queue<T>::~Queue()
{
	makeEmpty();
}

template<class T>
void Queue<T>::makeEmpty()
{
	while(!isEmpty())
		dequeue();
}

template<class T>
bool Queue<T>::isEmpty() const 
{
	return front == 0;	
}

template<class T>
const T & Queue<T>::getFront() const
{
	if(isEmpty())
		throw "Queue is empty.";
	return front->element;
}

template<class T>
void Queue<T>::enqueue(const T &x)
{
	if (isEmpty())
		back = front = new ListNode(x);
	else
		back = back->next = new ListNode(x);
}

template<class T>
T Queue<T>::dequeue()
{
	T frontItem = getFront();
	ListNode *old = front;
	front = front->next;
	delete old;

	return frontItem;
}

#endif
