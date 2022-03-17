#include "DoublyLinkedList.h"
#include <iostream>

Node_dll* DoublyLinkedList::CreateNewNode(int data) {
	Node_dll* node = new Node_dll();
	node->next = nullptr;
	node->prev = nullptr;
	node->data = data;
	return node;
}

void DoublyLinkedList::InsertAtHead(int data) {
	Node_dll* node = CreateNewNode(data);
	if (head == nullptr) {
		head = node;
	} else {
		head->prev = node;
		node->next = head;
		head = node;
	}
}

void DoublyLinkedList::InsertAtTail(int data) {
	Node_dll* node = CreateNewNode(data);
	if (head == nullptr) {
		head = node;
	} else {
		Node_dll* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = node;
		node->prev = temp;
	}
}

void DoublyLinkedList::Print() {
	Node_dll* temp = head;
	std::cout << "Doubly linked list elements:";
	while (temp != nullptr) {
		std::cout << ' ' << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}

void DoublyLinkedList::ReversePrint() {
	Node_dll* temp = head;
	if (temp == nullptr) {
		return;
	}

	while (temp->next != nullptr) {
		temp = temp->next;
	}

	std::cout << "\nDoubly linked list elements (reverse order):";
	while (temp != nullptr) {
		std::cout << ' ' << temp->data << ' ';
		temp = temp->prev;
	}
	std::cout << std::endl;
}