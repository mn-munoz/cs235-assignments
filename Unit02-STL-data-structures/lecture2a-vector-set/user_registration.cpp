#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
    set<string> IDs;
    cout << "Enter an ID: ";
    string id;
    
    while (getline(cin, id)) {
        if (id.empty()) { break; }
        if (IDs.find(id) == IDs.end()) {
            IDs.insert(id);
            // More to do
        } else {
            cout << "ID already in use" << endl;
        }
    }
    return 0;
}