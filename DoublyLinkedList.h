#pragma once
struct Node_dll {
	int data;
	Node_dll* next;
	Node_dll* prev;
};

class DoublyLinkedList {
	public:
	Node_dll* head;
	void InsertAtHead(int data);
	void InsertAtTail(int data);
	void Print();
	void ReversePrint();

	private:
	Node_dll* CreateNewNode(int data);
};

