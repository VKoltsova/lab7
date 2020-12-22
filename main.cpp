#include "list.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main() {
	LinkedList<char> list1;
	list1.addNode('1');
	list1.addNode('2');
	cout << list1;
	list1.removeNode();
	list1.addNode('3');

	LinkedList<int> list2;
	list2.addNode(1);
	list2.addNode(0);
	cout << list2;
	
	LinkedList<int> list3;
	cout << "Compare: " << ((list2 == list3) ? "True" : "False") << endl;
	list3.addNode(5);
	list3.addNode(10);
	cout << "Compare: " << ((list2 == list3) ? "True" : "False") << endl;
	system("pause");
}