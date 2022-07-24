#pragma once
#include <iostream>

template <typename T>
struct StackNode {
	T data;
	StackNode<T>* next;
};

template <typename T>
class StackList {
public:
	StackList<T>();
	void Push(T data);
	T* Pop();
	T* Peek();
	bool IsEmpty();
	void Print();

private:
	StackNode<T>* top;
};

template <typename T>
StackList<T>::StackList<T>() {
	top = nullptr;
}

template <typename T>
void StackList<T>::Push(T data) {
	StackNode<T>* node = new StackNode<T>();
	node->data = data;
	node->next = top;
	top = node;
}

template <typename T>
T* StackList<T>::Pop() {
	if (top == nullptr) {
		return nullptr;
	}
	StackNode<T>* node;
	node = top;
	top = top->next;
	return &(node->data);
}

template <typename T>
T* StackList<T>::Peek() {
	return &(top->data);
}

template <typename T>
bool StackList<T>::IsEmpty() {
	return top == nullptr;
}

template <typename T>
void StackList<T>::Print() {
	StackNode<T>* node = top;
	std::cout << "StackList elements: ";
	while (node != nullptr) {
		std::cout << ' ' << node->data << ' ';
		node = node->next;
	}
	std::cout << std::endl;
}