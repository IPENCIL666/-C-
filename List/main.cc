#include <iostream>
#include "ThreeLetterList.h"

using namespace std;

class List;

class Node
{
friend class List;  // 友元类
private:
	int data; // 结点里面的数据
	Node* link; // 指向下一个节点的指针
};

class List // 链表
{
public:
	void test();
	void show();
private:
	Node* first; // 指向第一个节点的指针
};

void List::show()
{
	cout << first->data << endl;
	cout << first->link->data << endl;
	cout << first->link->link->data << endl;
}

void List::test()
{
	Node *f = new Node();
	f->data = 44;
	f->link = 0;
	first = f;

	f = new Node();
	f->data = 72;
	f->link = 0;

	first->link = f;

	f = new Node();
	f->data = 210;
	f->link = 0;

	first->link->link = f; 
}

int main()
{
	List a;
	a.test(); // 创建了3个结点
	a.show(); // 显示3个结点
	
	ThreeLetterList l;
	l.test();
	l.show();

	cout << "OK" << endl;
	return 0;
}
