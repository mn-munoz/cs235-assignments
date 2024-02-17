#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std:: cout, std::cin, std::endl, std::cerr;
using std::ifstream, std::istream;



void printLines(istream& ins, int c = 10) {
    string line;
    int count = 0;

    while (!ins.eof() && count < c) {
        getline(ins, line);
        cout << line << endl;
        count++;
    }
}

void heads(const string& filename) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "The given file could not be open" << endl;
        exit(2);
    }

    printLines(file, 15);

    file.close();
}

int main(int argc, char const* argv[]) {

    if (argc < 2) {
        cerr << "Minimum of 1 argument required" << endl;
        return 1;
    }

    if (argc == 2) {
        heads(argv[1]);
    }



    cout << "done" << endl;


    return 0;
}
