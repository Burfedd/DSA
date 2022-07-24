#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "StackList.h"

void LinkedListRoutine();
void DoublyLinkedListRoutine();
void StackRoutine();
void StackListRoutine();

int main()
{
    //LinkedListRoutine();
    //DoublyLinkedListRoutine();
    //StackRoutine();
    StackListRoutine();
}

void LinkedListRoutine() {
    LinkedList<double>* list = new LinkedList<double>();
    std::cout << "How many numbers would you like to insert?" << std::endl;
    int n;
    double x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a number: ";
        std::cin >> x;
        list->Insert(x);
        list->Print();
    }

    std::cout << "Which number and where do you want no insert?" << std::endl;
    int pos;
    double num;
    std::cin >> num;
    std::cin >> pos;
    list->Insert(num, pos);
    list->Print();

    std::cout << "Number at which position would you like to delete?" << std::endl;
    int deletePos;
    std::cin >> deletePos;
    list->Delete(deletePos);
    list->Print();

    std::cout << "Reversing a linked list iteratively..." << std::endl;
    list->Reverse(false);
    list->Print();

    std::cout << "Printing with recursion in both orders..." << std::endl;
    list->PrintRecursively(false);
    list->PrintRecursively(true);

    std::cout << "Reversing the list with recursion..." << std::endl;
    list->Reverse(true);
    list->Print();
}

void DoublyLinkedListRoutine() {
    DoublyLinkedList* list = new DoublyLinkedList();
    std::cout << "How many numbers would you like to insert at head?" << std::endl;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a number: ";
        std::cin >> x;
        list->InsertAtHead(x);
        list->Print();
    }

    std::cout << "How many numbers would you like to insert at tail?" << std::endl;
    int m, y;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cout << "Enter a number: ";
        std::cin >> y;
        list->InsertAtTail(y);
        list->Print();
    }

    std::cout << "Printing the list in reverse order...";
    list->ReversePrint();
}

void StackRoutine() {
    std::cout << "How big would you like stack to be?" << std::endl;
    int s;
    std::cin >> s;
    Stack* stack = new Stack(s);

    std::cout << "How many numbers would you like to push?" << std::endl;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a number: ";
        std::cin >> x;
        stack->Push(x);
        stack->Print();
    }

    std::cout << "How many numbers would you like to pop?" << std::endl;
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        stack->Pop();
        stack->Print();
    }
}

void StackListRoutine() {
    StackList<double>* stackList = new StackList<double>();
    std::cout << "How many numbers would you like to push onto the stack?" << std::endl;
    int n;
    double x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a number: ";
        std::cin >> x;
        stackList->Push(x);
        stackList->Print();
    }

    std::cout << "How many numbers would you like to pop from the stack?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Popping element... Value: " << *(stackList->Pop()) << std::endl;
        stackList->Print();
    }
}