#pragma once
struct Node {
	int data;
	Node* next;
};

class LinkedList {
	public:
	Node* head;
	void Insert(int a);
	void Print();
};

