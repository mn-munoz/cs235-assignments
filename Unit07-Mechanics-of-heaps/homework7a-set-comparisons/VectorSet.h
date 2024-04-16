#pragma once

#include <vector>
#include <algorithm> 
// #include <string>
// #include <iostream>


template<class T>
class VectorSet {
    std::vector<T> v;
public:
    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set and false if not

        if (std::count(v.begin(), v.end(), item)) {
            return true;
        }
            return false;
    }

    bool insert(T item) {
        // implement insert here

        // return true if item is inserted and false if item is already in the
        // set

        if (std::count(v.begin(), v.end(), item)) {
            return false;
        }
        else {
            v.push_back(item);
            return true;
        }
    }

    bool remove(T item) {
        // implement remove here

        // return true if item is removed and false if item wasn't in the set

        if (!(std::count(v.begin(), v.end(), item))) {
            return false;
        }
        else {
            // v.erase(std::remove(v.begin(), v.end(), 8), v.end());
            v.erase(std::remove(v.begin(), v.end(), item), v.end());
            return true;
        }
    }

    int size() const {
        // implement size here

        // return the number of items in the set

        return v.size();
    }

    bool empty() const {
        // implement empty here

        // return true if the set is empty and return false otherwise
        if(v.empty()) {
            return true;
        }
        return false;
    }

    void clear() {
        // implement clear here

        // remove all items from the set

        v.clear();
    }
};
