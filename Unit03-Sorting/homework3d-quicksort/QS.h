#pragma once

#include <vector>

using std::vector, std::swap;

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here

    int middle = (left + right) / 2;

    // case where left is the median

    if (array.at(left) > array.at(middle) ) {
        swap(array.at(left), array.at(middle));
    }

    if (array.at(middle) > array.at(right) ) {
        swap(array.at(right), array.at(middle)); 

        if (array.at(left) > array.at(middle)) {
            swap(array.at(left), array.at(middle));
        }
    }

    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here

    int middle = medianOfThree(array, left, right);

    swap(array.at(left), array.at(middle));

    int up = left + 1;
    int down = right;

    do {
        while (array.at(up) <= array.at(left) && up < right) {
            up++;
        }

        while(array.at(down) > array.at(left) && down > left) {
            down--;
        }

        if (up < down) {
            swap(array.at(up), array.at(down));
        }
    } while (up < down);

    swap(array.at(left), array.at(down));

    return down;

}

template<class T>
void quicksort(std::vector<T> array, int left, int right) {
        if (right <= left) {
            return;
        }
        int pivot = partition(array, left, right);

        quicksort(array ,left, pivot - 1);
        quicksort(array,pivot + 1, right);
}


template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    quicksort(array, 0, array.size() - 1);
    
}


