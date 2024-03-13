#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::vector, std::string, std::istream, std::cout, std::cin, std::endl, std::ifstream, std::cerr;


void readLines(vector<string> &v,istream& ins = cin) {
    string line;
    while (getline(ins, line)) {
        v.push_back(line);
    }
}

int main(int argc, char const* argv[]) {
    // Write your code here

    vector<string> v;

    if (argc >= 2) {
        string fileName = argv[1];
        ifstream file;
        file.open(fileName);

        if(!file.is_open()) {
            cerr << "File could not be open" << endl;
            return 1;
        }

        readLines(v, file);

        file.close();
    }

    else {
        readLines(v);
    }

    for (int i = 1; i < v.size(); i++) {
        string element = v.at(i);
        int j = i - 1;

        while (j >= 0 && v.at(j) > element) {
            v.at(j + 1) = v.at(j);
            j--;
        }

        v.at(j+1) = element;
    }

    for (string i : v) 
        cout << i << endl;

    
    return 0;
}
