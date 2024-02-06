#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

#include "input.h"

int main() {
    map<char, set<string>> fruit_bowl;
    string fruit;
    while(input("Fruit?: ", fruit)) {
        fruit_bowl[fruit.at(0)].insert(fruit);
    }

    cout << "FRUIT:" << endl;
    for(auto const& item: fruit_bowl) {
        cout << "Fruit that starts with " << item.first << ": ";
        for(auto const& fruit: item.second) {
            cout << " " << fruit;
        }
        cout << endl;
    }

    return 0;
}