#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Get the list
    vector<string> groceries;
    cout << "Enter item: ";
    string item;
    while(getline(cin, item)) {
        if (item == "") {
            cout << "Ending the list" << endl;
            break;
        }
        groceries.push_back(item);
        cout << "Enter item: ";
    }
    // print the list
    cout << "GROCERY LIST:" << endl;

    for (auto item: groceries) {
        cout << item << endl;
    }

    // for (size_t i = 0; i < groceries.size(); i++) {
    //     cout << groceries.at(i) << endl;
    // }
    return 0;
}