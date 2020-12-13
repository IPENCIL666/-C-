#include <iostream>

#include "LinkList.h"

using namespace std;

int main()
{

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
