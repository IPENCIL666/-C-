#include <iostream>
#include <list> //C++ STL中的链表
#include "LinkList.h"
using namespace std;

int main()
{
	cout << "test" << endl;

	cout << "自定义的" << endl;
	List<int> intList;

	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	
	ListIterator<int> li(intList);
	if(li.NotNull())
	{
		cout << *li.First();
		while(li.NextNotNull())
			cout << "->" << *li.Next();
		cout << endl;
	}
	cout << "test toop" << endl;	
	ListIterator<int> iter(intList);
	cout << *iter.First() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;
	cout << *iter.Next() << endl;

	return 0;
}
