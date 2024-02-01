#pragma once

template<class T>
class Stack {
    private:
        vector<T> m_data;
    public:
        size_t size() {
            return m_data.size();
        }

        bool empty() {
            return m_data.empty();
        }

        void push(const T& item) {
            m_data.push_back(item);
        }

        void pop() {
            m_data.pop_back();
        }
        const T& top() {
            return m_data.at(m_data.size()-1);
        }
};