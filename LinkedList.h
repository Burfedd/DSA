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
	void PrintRecursively(bool reverse);

	private:
	void PrintNode(Node* node);
	void PrintNodeReverse(Node* node);
	void ReverseRecursively(Node* node);
};

