#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int main(int argc, char* argv[]) {
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string fileName = argv[1];
    ifstream in(fileName);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    ofstream setFile(fileName + "_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
        cout << ' ' << *it;
        setFile << ' ' << *it;
    }
    cout << endl;

    map<string, string> wordmap_1;
    string last="";
    ofstream mapFile(fileName + "_map.txt");
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap_1[last]=*it;
        last = *it;
        mapFile << last << ", " << wordmap_1[last] << endl;
    }

    return 0;
}