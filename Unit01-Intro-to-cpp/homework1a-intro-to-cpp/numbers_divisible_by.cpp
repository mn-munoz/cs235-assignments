#include <iostream>
#include <string>

using std::cout, std::endl;

int main(int argc, char const* argv[]) {
    // Write your code here
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    if (start < end) {
        for (int i = start; i <= end; i++) {
            if (i % divisor == 0) {
                cout << i << endl;
            } 
        }
    }
    else if (start > end) {
        for (int i = start; i >= end; i--) {
            if (i % divisor == 0) {
                cout << i << endl;
            }
        }
    }
    

    return 0;
}
