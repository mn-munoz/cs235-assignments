#include <iostream>
#include <string>
#include <fstream>
#include <set>

using std::string, std::cerr, std::cout, std::endl, std::cin;
using std::ifstream, std::istream;
using std::set;

void readInput(set<string>& data, istream& ins = cin) {
    string line;
    while(getline(ins,line)) {
        if (!(data.find(line) != data.end())) {
            cout << line << endl;
            data.insert(line);
        }
    }
}

 
int main(int argc, char const* argv[]) {
    set<string> data;
    if (argc == 2) {
        string fileName = argv[1];
        ifstream file;
        file.open(fileName);

        if (!file.is_open()) {
            cerr << "File could not be open" << endl;
            exit(2);
        }

        readInput(data, file);
        file.close();
    }
    else {
        readInput(data);
    }
    return 0;
}
