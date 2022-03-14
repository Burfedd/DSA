#include "LinkedList.h"
#include <iostream>

void LinkedList::Insert(int a) {
	Node* node = new Node();
	node->data = a;
	node->next = head;
	head = node;
}

void LinkedList::Insert(int data, int position) {
	int currentPos = 0;
	Node* currentNode = head;

	Node* newNode = new Node();
	newNode->data = data;
	for (int i = 0; i < position - 1; i++) {
		currentNode = currentNode->next;
	}
	Node* nextNode = currentNode->next;
	currentNode->next = newNode;
	newNode->next = nextNode;
}

void LinkedList::Print() {
	Node* nodePtr = head;
	std::cout << "Linked list elements: ";
	while (nodePtr != nullptr) {
		std::cout << ' ' << nodePtr->data << ' ';
		nodePtr = nodePtr->next;
	}
	std::cout << std::endl;
}
