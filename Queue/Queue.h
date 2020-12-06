#ifndef _QUEUE_H
#define _QUEUE_H

template<class T>
class Queue
{
	public:
		Queue(int queueCapacity=10);
		bool IsEmpty() const;
		T& Front() const;
		T& Rear() const;
		void Push(const T& item);
		void Pop();
	private:
		T *queue;
		int front; //队首
		int rear; // 队尾
		int capacity; //容量
};

template<class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
	if(capacity<1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template<class T>
inline bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template<class T>
void Queue<T>::Push(const T &item)
{
//	if (rear == capacity-1)
//		rear = 0;
//	else
//		rear++;
	rear = (rear+1) % capacity; //同上
	queue[rear] = item;
}
// 21.08

#endif
