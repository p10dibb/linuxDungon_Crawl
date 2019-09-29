#include <iostream>
#include <set>

using namespace std;

template<class T>
class Node
{

	
	Node* Next;
	Node* Pre;

public:
	T Data;
	Node();
	Node(T data);
	void setData(T data);
	T getData();
	void setNext(Node<T>* data);
	Node<T>*getNext();
	void setPre(Node<T>* data);
	Node<T>*getPre();


};


template <class T>
Node<T>::Node(T data) {
	Next = NULL;
	Pre = NULL;
	Data = data;
}

template <class T>
void Node<T>::setData(T data) {
	Data = data;
	//return true;
}

template <class T>
T Node<T>::getData() {
	return Data;
}

template <class T>
void Node<T>::setNext(Node<T>* node) {
	Next = node;
}
template <class T>
Node<T>* Node<T>::getNext() {
	return Next;
}
template <class T>
void Node<T>::setPre(Node<T>* node) {
	Pre = node;
}
template <class T>
Node<T>* Node<T>::getPre() {
	return Pre;
}
