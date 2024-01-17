#include <iostream>
#include <string>

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

using std::cout, std::endl;

int main(int argc, char const* argv[]) {
    // Write your code here


    while (true) {
        std::string operation = input("operation: ");

        if (!operation.length()) {
            break;
        }
        else if (operation != "add" && operation != "subtract" && operation != "multiply" && operation != "divide" && operation != "mod") {
            cout << operation << " isn't a valid operation" << endl;
            continue;
        }
        
        int lOperand = stoi(input("left operand: "));
        int rOperand = stoi(input("right operand: "));

        if (operation == "add") {
            cout << lOperand + rOperand << endl;
        }
        else if (operation == "subtract") {
            cout << lOperand - rOperand << endl;
        }
        else if (operation == "multiply") {
            cout << lOperand * rOperand << endl;
        }
        else if (operation == "divide") {
            cout << lOperand / rOperand << endl;
        }
        else if (operation == "mod") {
            cout << lOperand % rOperand << endl;
        }
    }
    

    return 0;
}
