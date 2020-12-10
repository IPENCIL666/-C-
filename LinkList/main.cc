#include <iostream>

#include "LinkList.h"

using namespace std;

int main()
{
	cout << "test" << endl;

	List<int> intList;

	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	
	intList.Show();
	intList.Invert();
	intList.Show();
	intList.Delete(15);
	intList.Show();

	List<char> charList;
	charList.Insert('a');
	charList.Insert('b');
	charList.Insert('c');
	charList.Insert('d');
	charList.Invert();
	charList.Show();

	List<char> char2List;
	char2List.Insert('e');
	char2List.Insert('f');
	char2List.Invert();
	char2List.Show();

	charList.Concatenate(char2List);
	charList.Show();

	return 0;
}
