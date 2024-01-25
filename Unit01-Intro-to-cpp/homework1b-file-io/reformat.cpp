#include <iostream>
#include <string>
#include <fstream>

using std::cerr, std::cout, std::endl;
using std::ifstream, std::ofstream;
using std::string;

int main(int argc, char const* argv[]) {
    ifstream inFile;
    ofstream outFile;
    string inputName = argv[1];
    string outName = argv[2];
    inFile.open(inputName);
    outFile.open(outName);

    if (!inFile.is_open()) {
        cerr << "File given could not open" << endl;
        exit(1);
    }

    while(!inFile.eof()) {
        string name;
        string lastName; 
        int points;
        double factor;
        inFile >> name >> lastName >> points >> factor; 

        if (name.empty() && lastName.empty()) {
            break;
        }

        outFile << lastName << ", " << name << ": " << points * factor << endl;
    }

    outFile.close();
    inFile.close();
    return 0;
}
