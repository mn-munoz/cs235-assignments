#include <iostream>
#include <string>
#include <queue>

#include "input.h"

using std::string, std::cout, std::endl;
using std::priority_queue, std::pair;

string formatNum(int num) {
    if (num < 10) {
        return "0" + std::to_string(num);
    }
    return std::to_string(num);
}

int main(int argc, char const* argv[]) {
    // Write your code here
    string command;
    priority_queue<pair<int, string>> pq;   

    while (input("What do you want to do? ", command)) {
        if (command == "add") {
            string name, priority;
            int intPrior;
            input("Name: ", name);
            input("Priority: ", priority);
            intPrior = stoi(priority);

            pq.push({intPrior, name});
        }

        else if (command == "take") { 
            if (pq.empty()) {
                cout << "There are no more people in line" << endl;
            }
            else {
                pair<int,string> topPerson = pq.top();
                pq.pop();

                cout << formatNum(topPerson.first) << " - " << topPerson.second << endl;
            }
        }
        else {
            cout << command << " isn't a valid operation" << endl;
        }
    }
    return 0;
}
