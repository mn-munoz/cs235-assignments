#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() : m_head(nullptr), m_size(0) {}

    ~SLList() { clear();}

    const Node* get_head() const {
        // implement get_head here
        return m_head;
    }

    void push_back(T item) {
        // implement push_back here

        if (m_size == 0) {
            m_head = new Node(item);
        } 
        else {
            Node* nodePtr = m_head;
            while (nodePtr->next != NULL) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = new Node(item);
        }
        m_size++;
    }

    void pop_back() {
        // implement pop_back here
        if (m_size == 1) {
            m_head = nullptr;
        }
        else {
            Node* nodePtr = m_head;
            while (nodePtr->next->next != nullptr) {
                nodePtr = nodePtr->next;
            }
            delete nodePtr->next;
            nodePtr->next = nullptr;
        }
        m_size--;
    }

    const T& front() const {
        // implement front here

        return m_head->value;
    }

    int size() const {
        // implement size here
        return m_size;
    }

    void clear() {
        // implement clear here
        if (m_size <= 1) {
            delete m_head;
            m_head = nullptr;
        }
        else {
            Node* nodePtr = m_head;
            while (nodePtr->next != NULL) {
                Node * next = nodePtr->next;
                delete nodePtr;
                nodePtr = next;
            }
        }
        m_size = 0;
    }

    private:

    Node* m_head;
    int m_size;
};
