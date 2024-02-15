#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

using std::cout, std::endl;

using std::string, std::stringstream, std::ifstream;

int countWords(const string &line) {
    int count = 0;
    string word;
    stringstream ss(line);
    while (ss >> word) {
        count++;
    }
    
    return count;
}


string countLines(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        
        throw std::invalid_argument("Unable to open " + filename);
    }
    
    string line;
    string longest_line;
    int longest_count = 0;
    int current_cout = 0;
    while(getline(file,line)) {
        current_cout = countWords(line);

        if (current_cout > longest_count) {
            longest_line = line;
            longest_count = current_cout;
        }
    }

    return longest_line;
}

int main(int argc, char const* argv[]) {
    // Write your code here

    if (argc < 2) {
        cout << "Minimum of two argumetns" << endl;

        return 1;
    }

    cout << countLines(argv[1]) << endl;



    return 0;
}
