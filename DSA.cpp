#include <iostream>
#include "LinkedList.h"

int main()
{
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
}

