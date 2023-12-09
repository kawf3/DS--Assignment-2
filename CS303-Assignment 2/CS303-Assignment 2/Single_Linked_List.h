#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cstddef>


using namespace std;
//Maybe could use this list to store names eventually but for now integers only
template <typename T>
class Single_Linked_List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}
    ~Single_Linked_List();


    size_t size() const;
    void push_front(const T& item);
    void push_back(const T& item);
    void pop_front();
    void pop_back();
    T& front();
    T& back();
    bool empty() const;
    void insert(size_t index, const T& item);
    bool remove(size_t index);
    size_t find(const T& item) const;
};
