// 测试
#include <iostream>
#include "Util.h"
#include "Stack.h"

using namespace std;

int main()
{
	MyStack<int> st(200);

	st.Push(99);
	st.Push(22);
	st.Push(18);
	st.Push(67);

	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;
	st.Pop();
	cout << st.Top() << endl;

	cout << "TEST!" << endl;
	return 0;
}
