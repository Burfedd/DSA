#include "Stack.h"
#include <iostream>

Stack::Stack(int size) {
	storage = new int[size];
	top = -1;
}

bool Stack::IsEmpty() {
	return top == -1;
}

void Stack::Push(int data) {
	top++;
	storage[top] = data;
}

int Stack::Pop() {
	int temp = storage[top];
	storage[top] = 0;
	top--;
	return temp;
}

int Stack::Peek() {
	if (top == -1) {
		return 0;
	} else {
		return storage[top];
	}
}

void Stack::Print() {
	if (top != -1) {
		int pos = top;
		std::cout << "Stack elements: ";
		while (pos != -1) {
			std::cout << storage[pos] << ' ';
			pos--;
		}
		std::cout << std::endl;
	}
}