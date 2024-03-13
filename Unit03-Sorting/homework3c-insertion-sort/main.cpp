#include <iostream>
#include <vector>
#include <string>

using std::cout, std::vector, std::string, std::endl;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}