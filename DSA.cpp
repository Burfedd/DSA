#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"

void LinkedListRoutine();
void DoublyLinkedListRoutine();

int main()
{
    //LinkedListRoutine();
    DoublyLinkedListRoutine();
}

void LinkedListRoutine() {
    LinkedList* list = new LinkedList();
    std::cout << "How many numbers would you like to insert?" << std::endl;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter a number: ";
        std::cin >> x;
        list->Insert(x);
        list->Print();
    }

    std::cout << "Which number and where do you want no insert?" << std::endl;
    int num, pos;
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

