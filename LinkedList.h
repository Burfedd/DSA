#pragma once
#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
};

template <typename T>
class LinkedList {
	public:
	Node<T>* head;
	void Insert(T a);
	void Insert(T data, int position);
	void Delete(int position);
	void Reverse(bool recursive);
	void Print();
	void PrintRecursively(bool reverse);

	private:
	void PrintNode(Node<T>* node);
	void PrintNodeReverse(Node<T>* node);
	void ReverseRecursively(Node<T>* node);
};

template <typename T>
void LinkedList<T>::Insert(T a) {
	Node<T>* node = new Node<T>();
	node->data = a;
	node->next = head;
	head = node;
}

template <typename T>
void LinkedList<T>::Insert(T data, int position) {
	if (position == 0) {
		Insert(data);
		return;
	}

	int currentPos = 0;
	Node<T>* currentNode = head;

	Node<T>* newNode = new Node<T>();
	newNode->data = data;
	for (int i = 0; i < position - 1; i++) {
		currentNode = currentNode->next;
	}
	Node<T>* nextNode = currentNode->next;
	currentNode->next = newNode;
	newNode->next = nextNode;
}

template <typename T>
void LinkedList<T>::Delete(int position) {
	Node<T>* tempPrevious = head;
	// Position 0 - head
	if (position == 0) {
		head = head->next;
		delete tempPrevious;
		return;
	}


	// Nodes before and after position
	for (int i = 0; i < position - 1; i++) {
		tempPrevious = tempPrevious->next;
	}
	Node<T>* tempActual = tempPrevious->next;
	Node<T>* tempNext = tempActual->next;
	tempPrevious->next = tempNext;
	delete tempActual;
}

template <typename T>
void LinkedList<T>::Reverse(bool recursive) {
	if (recursive) {
		ReverseRecursively(head);
	} else {
		Node<T>* current = head;
		Node<T>* savedLink = current->next;
		current->next = nullptr;

		while (savedLink != nullptr) {
			Node<T>* previous = current;
			current = savedLink;
			savedLink = current->next;
			current->next = previous;
		}

		head = current;
	}
}

template <typename T>
void LinkedList<T>::ReverseRecursively(Node<T>* node) {
	if (node->next == nullptr) {
		head = node;
		return;
	}
	ReverseRecursively(node->next);
	Node<T>* previous = node->next;
	previous->next = node;
	node->next = nullptr;
}

template <typename T>
void LinkedList<T>::Print() {
	Node<T>* nodePtr = head;
	std::cout << "Linked list elements: ";
	while (nodePtr != nullptr) {
		std::cout << ' ' << nodePtr->data << ' ';
		nodePtr = nodePtr->next;
	}
	std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::PrintRecursively(bool reverse) {
	if (reverse) {
		std::cout << "Recursively printing the list is reverse order..." << std::endl;
		PrintNodeReverse(head);
		std::cout << std::endl;
	} else {
		std::cout << "Recursively printing the list..." << std::endl;
		PrintNode(head);
		std::cout << std::endl;
	}
}

template <typename T>
void LinkedList<T>::PrintNode(Node<T>* node) {
	std::cout << ' ' << node->data << ' ';
	if (node->next != nullptr) {
		PrintNode(node->next);
	}
}

template <typename T>
void LinkedList<T>::PrintNodeReverse(Node<T>* node) {
	if (node->next != nullptr) {
		PrintNodeReverse(node->next);
	}
	std::cout << ' ' << node->data << ' ';
}