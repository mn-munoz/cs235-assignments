#include <iostream>
#include <string>
#include <queue>
#include <set>

#include "input.h"

using std::string, std::cout, std::endl;
using std::priority_queue, std::set;


int main(int argc, char const* argv[]) {
    // Write your code here

    string command;
    priority_queue<string, std::greater<string>> pq;   

    while (input("What do you want to do? ", command)) {
        if (command == "add") {
            string name;
            string priority;
            input("Name: ", name);
            input("Priority: ", priority);

        }

        else if (command == "take") { 
        }

        else {
            cout << command << " isn't a valid operation" << endl;
        }
    }
    return 0;
}
