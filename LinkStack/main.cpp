#include <iostream>
#include "LinkStack.h"

using namespace std;

int main()
{
	cout << "test" << endl;

	LinkStack<int> s;
	s.Push(10);
	cout << s.Top() << endl;
	s.Push(20);
	s.Push(30);
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;

	return 0;
}
