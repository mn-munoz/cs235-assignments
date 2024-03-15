#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:
    class Iterator {
    T* m_pointer;
    public:

        Iterator(T* ptr) : m_pointer(ptr){}
        T& operator*() {
            // implement operator* here
            return *m_pointer;
        }

        Iterator& operator++() {
            // implement operator++ here
            m_pointer++;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            // implement operator== here
            return m_pointer == other.m_pointer;
        }

        bool operator!=(const Iterator& other) const {
            // implement operator!= here
            return !(*this == other);
        }

    };

    Iterator begin() {
        // implement begin here
        return Iterator(m_data);
    }

    Iterator end() {
        // implement end here
        return Iterator(m_data + m_size);
    }

    // paste in your methods from the vector assignment

    Vector() {
        m_size = 0;
        m_capacity = 8;
        m_data = new T[m_capacity];
    }

    ~Vector() {
        delete [] m_data;
    }

    void grow () {
        T* newArray = new T[m_capacity * 2];

        for (size_t i = 0; i < m_size; i++) {
            newArray[i] = m_data[i];
        }

        delete [] m_data;
        m_data = newArray;
        m_capacity = m_capacity * 2;
    } 

    void push_back(T item) {
        // implement push_back here
        if (m_size >= m_capacity) {
            grow();
        }
            m_data[m_size] = item;
            m_size++;
    }

    void insert(T item, int position) {
        // implement insert here

        if (position < 0 || position > m_size) {
            throw std::out_of_range("position out of bounds");
        }
        
        if (position == m_size) {
            push_back(item);
        } 
        else {
            if (m_size == m_capacity) {
                grow();
            }

            for (size_t i = m_size; i > position; i--) {
                m_data[i] = m_data[i-1];
            }
            m_data[position] = item;
            m_size++;
        }
    }

    void remove(int position) {
        // implement remove here

        if (position < 0 || position > m_size || m_size == 0) {
            throw std::out_of_range("position out of bounds");
        } 

        if (m_size <= 1) {
            clear();
        }
        else {
            for (size_t i = position; i < m_size - 1 ; i++) {
                m_data[i] = m_data[i + 1];
            }
            m_size--;
        }
    }

    T& operator[](int index) {
        // implement operator[] here
        if (index >= m_size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];

    }

    int size() const {
        // implement size here
        return m_size;
    }

    void clear() {
        // implement clear here
        m_size = 0;
    }

private:
    // paste in your data members from the vector assignment
    T * m_data;
    size_t m_size;
    size_t m_capacity;
};
