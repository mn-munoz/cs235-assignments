#include <iostream>
#include <list>
#include <functional>
using namespace std;

const size_t INITIAL_CAPACITY = 11;
const double MAX_LOAD = 0.8;

template<class T>
class HashSet {
public:
    HashSet() {
        m_capacity = INITIAL_CAPACITY;
        m_data = new list<T>[m_capacity];
        m_size = 0;
    }

    ~HashSet() {
        delete [] m_data;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        if (getLoadFacotr() > MAX_LOAD) {
            grow();
        }
        size_t index = getIndex(item);

        for (auto value : m_data[index]) {
            if (item == value) {
                return false;
            }
        }

        m_data[index].push_back(item);
        m_size++;
        return true;

    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        auto index = getIndex(item);

        for (auto value : m_data[index]) {
            if (value == item) {
                m_data[index].remove(item);
                m_size--;
                return true;
            }
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        size_t index = getIndex(item);

        for (auto value : m_data[index]) {
            if (value == item) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        delete [] m_data;
        m_size = 0;
        m_capacity = INITIAL_CAPACITY;
        m_data = new list<T>[m_capacity];

    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return m_size;
    }

    friend std::ostream& operator << (std::ostream& out, HashSet const& set) {
        for (size_t i = 0; i < set.m_capacity; i++) {
            cout << "bucket " << i << ": ";
            for (auto item : set.m_data[i]) {
                cout << item << " ";
            }
            cout << endl;
        }
        return out;
    }

    private:

    list<T>* m_data;
    size_t m_capacity;
    size_t m_size;

    double getLoadFacotr() const {
        return static_cast<double> (m_size) / m_capacity;
    }

    void grow() {
        size_t oldCapacity = m_capacity;
        m_capacity *= 2 + 1;
        auto oldArray = m_data;
        m_data = new list<T>[m_capacity];
        for (size_t i = 0; i < oldCapacity; i++) {
            for (auto item : oldArray[i]) {
                insert(item);
            }
        }
    }

    size_t getIndex(T& item) const {
        return hash<T>{}(item) % m_capacity;
    }
};

int main() {
    HashSet<string> mySet;
    mySet.insert("Tom");
    mySet.insert("Denise");
    cout << mySet << endl;
    mySet.insert("Danae");
    mySet.insert("Thomas");

    cout << mySet << endl;

    cout << boolalpha << mySet.contains("Danae") << endl;
    cout << mySet.contains("Debra") << endl;
    return 0;
}
