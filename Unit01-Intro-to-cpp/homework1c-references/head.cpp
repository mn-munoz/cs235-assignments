#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std:: cout, std::cin, std::endl, std::cerr;
using std::ifstream, std::istream;



// void heads(istream& ins = cin, int c = 10) {
//     string line;
//     int count = 0;

//     while (!ins.eof() && count < c) {
//         getline(ins, line);
//         cout << line << endl;
//         count++;
//     }
// }
void heads(istream& ins = cin, int c = 10) {
    string line;
    int count = 0;

    while (getline(ins, line) && count < c) {
        cout << line << endl;
        count++;
    }
}

void heads(const string& filename, int c = 10) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "The given file could not be open" << endl;
        exit(2);
    }

    heads(file, c);

    file.close();
}

int main(int argc, char const* argv[]) {

    if (argc == 1 ) {
        heads();
    }

    if (argc == 2) {
        string arg = argv[1];
        if (arg.at(0) == '-') {
            int c = stoi(arg.substr(1));
            heads(cin, c);
        }
        else {
            string fileName = argv[1];
            heads(fileName);
        }
    }

    if (argc == 3) {
        string num = argv[1];
        string fileName = argv[2];
        int c = stoi(num.substr(1));
        heads(fileName, c);
    }

    return 0;
}
