#pragma once
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

template<class T>
struct Node {
	Node* next;		// ��������� �� ��������� ������� ������
	Node* prev;		// ��������� �� ���������� ������� ������
	T data;			// ������ ��������
};

//����������� ������
template<class T>
class LinkedList {
	Node<T>* first;
	Node<T>* last;
	int size;
public:
	LinkedList() {
		first = NULL;
		last = NULL;
		size = 0;
	}
	void addNode(T);
	T removeNode();
	void print();
	template<class U>
	friend ostream& operator<<(ostream& os, const LinkedList<U>& list);
	bool operator==(const LinkedList<T>& list);
};



template<class T>
void LinkedList<T>::addNode(T data) {
	Node<T>* tmp = new Node<T>;
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (size == 0) {
		first = last = tmp;
		first->next = first->prev = NULL;
		size = 1;
	}
	else {
		last->next = tmp;
		last->next->prev = last;
		last = last->next;
		last->next = NULL;
		size++;
	}
}

template<class T>
T LinkedList<T>::removeNode() {
	T result;
	if (size == 0) {
		result = NULL;
	}
	else {
		size--;
		result = last->data;
		last = last->prev;
		delete last->next;
	}
	return result;
}

template<class T>
void LinkedList<T>::print() {
	if (size == 0) {
		cout << "List is empty :(" << endl;
	}
	else {
		Node<T>* tmp = first;
		cout << "List elements:" << endl;
		while (tmp) {
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
}

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
	if (list.size == 0) {
		os << "List is empty :(" << endl;
	}
	else {
		Node<T>* tmp = list.first;
		os << "List elements:" << endl;
		while (tmp) {
			os << tmp->data << endl;
			tmp = tmp->next;
		}
	}
	return os;
}

template<class T>
bool LinkedList<T>::operator==(const LinkedList<T>& list) {
	return this->size == list.size;
}