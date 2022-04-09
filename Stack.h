#pragma once
class Stack {
	public:
	Stack(int size);
	void Push(int data);
	int Pop();
	int Peek();
	bool IsEmpty();
	void Print();

	private:
	int top;
	int* storage;
};

