#include "Node.h"

template <class T>
class DoubleLinkedList {
	Node<T> *Head, *Tail;
	int size;

public:

	DoubleLinkedList();

	Node<T>* getHead();
	void setHead(Node<T> node);

	Node<T>* getTail();
	void setTail(Node<T> node);

	//returns the size of linked list
	int Size();

	//adds an item to end of the list
	void add(T info);

	//adds item to head of the list
	void push(T info);

	//removes item from end of list
	void pop();

	//returns item at end of list
	Node<T>* peek();
	//returns the node at specified position
	Node<T>* getNode(int position);
	
	T getData(int position);
	void setData(int position, T data);


	//removes the node at set position
	void removeNode(int position);



	void clear();


};



template<class T>
Node<T>* DoubleLinkedList<T>::getHead() {
	return this->Head;
}

template<class T>
void DoubleLinkedList<T>::setHead(Node<T> node) {
	Head = node;
}

template<class T>
Node<T>* DoubleLinkedList<T>::getTail() {
	return Tail;
}

template<class T>
void DoubleLinkedList<T>::setTail(Node<T> node) {
	Tail = node;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
	this->Head = NULL;
	this->Tail = NULL;
	this->size = 0;
}
template<class T>
int DoubleLinkedList<T>::Size() {
	return this->size;
}

template<class T>
void DoubleLinkedList<T>::add(T info) {
	Node<T>* temp = new Node<T>(info);

	if (this->Head == NULL) {
		this->Head = temp;
		this->Tail = Head;
		this->size++;
	}
	else {
		this->Tail->setNext(temp);
		temp->setPre(Tail);
		Tail = temp;
		size++;
	}
}


template<class T>
void DoubleLinkedList<T>::push(T info) {
	Node<T>* temp = new Node<T>(info);

	if (this->Head == NULL) {
		this->Head = temp;
		this->Tail = Head;
		this->size++;
	}
	else {

		this->Head->setPre(temp);
		temp->setNext(this->Head);
		Head = temp;
		
		size++;
	}
}


template<class T>
void DoubleLinkedList<T>::pop() {
	if (this->size > 0) {
		Node<T>* temp = this->Tail;
		this->Tail = this->Tail->getPre();
		this->Tail->setNext(NULL);

		if (this->Tail == NULL) {
			this->Head == NULL;
		}
		free(temp);
	}
}


//returns item at end of list
template<class T>
Node<T>* DoubleLinkedList<T>::peek() {
	return this->Tail;
}

//returns the node at specified position
template<class T>
Node<T>* DoubleLinkedList<T>::getNode(int position) {
	if (position < this->size) {
		Node<T>*temp = Head;
		for (int i = 0; i < position; i++) {
			temp = temp->getNext();

		}
		return temp;
	}
	return NULL;
}

//removes the node at set position
template<class T>
void DoubleLinkedList<T>::removeNode(int position) {
	if (position <=this->size && position>0) {
		Node<T>*temp = Head;
		if (position == 1) {
			
			this->Head = this->Head->getNext();
			free(temp);
			if (this->Head == NULL) {
				this->Tail == NULL;
			}
		}
		else if (position == size) {
			this->pop();
		
		}
		else {
			for (int i = 0; i < position - 1; i++) {
				temp = temp->getNext();

			}

			temp->getPre()->setNext(temp->getNext());
			temp->getNext()->setPre(temp->getPre());
			free(temp);
		}
		

		this->size--;
	}

}
template<class T>
T DoubleLinkedList<T>::getData(int position) {
	if (position < this->size) {
		Node<T>*temp = Head;
		for (int i = 0; i < position; i++) {
			temp = temp->getNext();

		}
		return temp->getData();
	}
	//return NULL;
}

template<class T>
void DoubleLinkedList<T>::setData(int position, T data) {
	if (position < this->size) {
		Node<T>*temp = Head;
		for (int i = 0; i < position; i++) {
			temp = temp->getNext();

		}
		temp->Data = data;
	}
	
}