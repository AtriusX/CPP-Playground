#include "list.hpp"
#include <iostream>

int main() {
    auto list = new collections::List<int>(2);

    std::cout << "Add element 1" << std::endl;
    list->add(1);
    std::cout << "Add element 3" << std::endl;
    list->add(3);

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Add element 5" << std::endl;
    list->add(5);
    std::cout << "Add element 7" << std::endl;
    list->add(7);

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Deleting element 3" << std::endl;
    list->removeElement(3);

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Deleting elements 1, 5, 7" << std::endl;
    list->removeElement(1);
    list->removeElement(5);
    list->removeElement(7);

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Adding 0 to 6" << std::endl;
    for (int i = 0; i <= 6; i++) {
        list->add(i);
    }

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Removing first 3 items" << std::endl;
    for (int i = 0; i < 3; i++) {
        list->remove(0);
    }

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Attempt clearing remaining items" << std::endl;
    list->clear();

    
    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Adding 0 to 6" << std::endl;
    for (int i = 0; i <= 6; i++) {
        list->add(i);
    }

    std::cout << "Reversing the list" << std::endl;
    list->reverse();

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Clearing the list" << std::endl;
    list->clear();

    std::cout << "Current list size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); i++) {
        std::cout << "Element " << i << ": " << list->get(i) << std::endl;
    }

    std::cout << "Exiting..." << std::endl;
    delete list;
}
