#include <iostream>

#include "Queue.h"

using namespace std;

int main()
{
	cout << "test" << endl;

	Queue<char> q(9);

	q.Push('A');
	q.Push('B');
	q.Push('C');

	cout << q.Front() << "," << q.Rear() << endl;
	q.Push('D');
	q.Push('E');
	cout << q.Front() << "," << q.Rear() << endl;
	q.Pop();
	cout << q.Front() << "," << q.Rear() << endl;
	q.Push('F');
	cout << q.Front() << "," << q.Rear() << endl;
	q.Push('G');
	cout << q.Front() << "," << q.Rear() << endl;

	return 0;
}
