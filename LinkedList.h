#pragma once
struct Node {
	int data;
	Node* next;
};

class LinkedList {
	public:
	Node* head;
	void Insert(int a);
	void Insert(int data, int position);
	void Delete(int position);
	void Reverse(bool recursive);
	void Print();
};

