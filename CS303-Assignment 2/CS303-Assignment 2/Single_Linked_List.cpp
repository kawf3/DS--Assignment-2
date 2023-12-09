#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cmath>
#include <stdexcept>

#include <cstddef>
#include "Single_Linked_List.h"
using namespace std;


template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}


template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

template <typename T>
void Single_Linked_List<T>::push_front(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        tail = new_node;
    }
    new_node->next = head;
    head = new_node;
    ++num_items;
}

template <typename T>
void Single_Linked_List<T>::push_back(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = new_node;
    }
    else {
        tail->next = new_node;
    }
    tail = new_node;
    ++num_items;
}

template <typename T>
void Single_Linked_List<T>::pop_front() {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        --num_items;
        if (empty()) {
            tail = nullptr;
        }
    }
}

template <typename T>
void Single_Linked_List<T>::pop_back() {
    if (!empty()) {
        if (num_items == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            num_items = 0;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
            --num_items;
        }
    }
}

template <typename T>
T& Single_Linked_List<T>::front() {
    return head->data;
}

template <typename T>
T& Single_Linked_List<T>::back() {
    return tail->data;
}

template <typename T>
bool Single_Linked_List<T>::empty() const {
    return num_items == 0;
}

template <typename T>
void Single_Linked_List<T>::insert(size_t index, const T& item) {
    if (index == 0) {
        push_front(item);
    }
    else if (index >= num_items) {
        push_back(item);
    }
    else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* new_node = new Node(item);
        //new

    }
}

template <typename T>
bool Single_Linked_List<T>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    Node* temp;
    if (index == 0) {
        temp = head;
        head = head->next;
    }
    else {
        Node* prev = head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
    }
    delete temp;
    num_items--;
    return true;
}

template <typename T>
size_t Single_Linked_List<T>::find(const T& item) const {
    Node* current = head;
    for (size_t i = 0; i < num_items; i++) {
        if (current->data == item) {
            return i;
        }
        current = current->next;
    }
    return num_items;
}

