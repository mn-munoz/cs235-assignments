#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList(): m_head(nullptr), m_tail(nullptr), m_size(0) {}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return m_head;
    }

    void push_front(T item) {
        // implement push_front here

        Node * ptr = new Node(item);
        if (m_head != nullptr ) {
            m_head ->prev = ptr;
            ptr -> next = m_head;
        }
        else {
            m_tail = ptr;
        }
        
        m_head = ptr;
        m_size++;
    }
    void push_back(T item) {
        Node* ptr = new Node(item);
        if (m_tail != nullptr) {
            m_tail->next = ptr;
            ptr->prev = m_tail;
        }
        else {
            m_head = ptr;
        }

        m_tail = ptr;
        m_size++;

    }
    void insert(T item, int position) {
        // implement insert here
        if (position < 0 || (position > m_size)) {
            throw std::out_of_range("Position is out of range");
        }

        if (position == 0) {
            push_front(item);
            return;
        }
        else if (position == m_size){
            push_back(item);
            return;
        }
        Node* current;
        current = m_head;

        for(size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }
    
        Node* ptr = new Node(item);
        ptr->prev = current;
        current->next->prev = ptr;
        ptr->next = current->next;
        current->next = ptr;
        m_size++;
    }

    void pop_front() {
        if (m_size == 0) {
            throw std::length_error("List is empty");
        }

        // implement pop_front here
        if (m_size == 1) {
            delete m_head;
            m_head = nullptr; m_tail = nullptr;
        }
        else {
            Node* newHead = m_head-> next;
            delete m_head;
            newHead->prev = nullptr;
            m_head = newHead;

        }

        m_size--;
    }
    void pop_back() {
        if (m_size == 0) {
            throw std::length_error("List is empty");
        }

        // implement pop_back here
        if (m_size == 1) {
            delete m_tail;
            m_head = nullptr; m_tail = nullptr;
        }
        else {
            Node* newTail = m_tail->prev;
            delete m_tail;
            newTail->next = nullptr;
            m_tail = newTail;
        }

        m_size--;
    }
    void remove(int position) {
        // implement remove here

        if (position < 0 || (position >= m_size)) {
            throw std::out_of_range("Position is out of range");
        }

        if (position == 0) {
            pop_front();
            return;
        }
        else if (position == m_size - 1){
            pop_back();
            return;
        }

        Node* current;
        current = m_head;

        for(size_t i = 0; i < position; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;

        m_size--;
    }

    const T& front() const {
        // implement front here
        if (m_size == 0) {
            throw std::length_error("List is empty");
        }
        return m_head->value;

    }
    const T& back() const {
        // implement back here
        if (m_size == 0) {
            throw std::length_error("List is empty");
        }
        return m_tail->value;
    }
    const T& at(int index) const {
        // implement at here
        if (index < 0 || (index >= m_size)) {
            throw std::out_of_range("Position is out of range");
        }

        if (index == 0) {
            return front();
        }
        if (index == m_size - 1) {
            return back();
        }

        Node* current = m_head; 

        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }

    bool contains(const T& item) const {
        // implement contains here
        Node* current = m_head; 

        while (current != NULL) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }   
        return false;
    }

    int size() const {
        // implement size here
        return m_size;
    }

    void clear() {
        // implement clear here
        while ((m_head != NULL)) {
            Node *temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
        
        m_tail = nullptr;
        m_size = 0;
    }

    private:
        Node* m_head;
        Node* m_tail;
        int m_size;
};
