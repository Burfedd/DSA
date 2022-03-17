#include "LinkedList.h"
#include <iostream>

void LinkedList::Insert(int a) {
	Node* node = new Node();
	node->data = a;
	node->next = head;
	head = node;
}

void LinkedList::Insert(int data, int position) {
	if (position == 0) {
		LinkedList::Insert(data);
		return;
	}

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

void LinkedList::Delete(int position) {
	Node* tempPrevious = head;
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
	Node* tempActual = tempPrevious->next;
	Node* tempNext = tempActual->next;
	tempPrevious->next = tempNext;
	delete tempActual;
}


void LinkedList::Reverse(bool recursive) {
	if (recursive) {
		ReverseRecursively(head);
	} else {
		Node* current = head;
		Node* savedLink = current->next;
		current->next = nullptr;

		while (savedLink != nullptr) {
			Node* previous = current;
			current = savedLink;
			savedLink = current->next;
			current->next = previous;
		}

		head = current;
	}
}

void LinkedList::ReverseRecursively(Node* node) {
	if (node->next == nullptr) {
		head = node;
		return;
	}
	ReverseRecursively(node->next);
	Node* previous = node->next;
	previous->next = node;
	node->next = nullptr;
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

void LinkedList::PrintRecursively(bool reverse) {
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

void LinkedList::PrintNode(Node* node) {
	std::cout << ' ' << node->data << ' ';
	if (node->next != nullptr) {
		PrintNode(node->next);
	}
}

void LinkedList::PrintNodeReverse(Node* node) {
	if (node->next != nullptr) {
		PrintNodeReverse(node->next);
	}
	std::cout << ' ' << node->data << ' ';
}
