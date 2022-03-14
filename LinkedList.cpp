#include "LinkedList.h"
#include <iostream>

void LinkedList::Insert(int a) {
	Node* node = new Node();
	node->data = a;
	node->next = head;
	head = node;
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
