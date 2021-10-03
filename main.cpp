#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    // TODO(student): implement the UI
    string input;
    getline(cin, input);
    string answer = "temp";
    if (input.at(0) == ' '){
            input.erase(0,1);
        }
    while (input != "q" && input != "quit"){
        if (input.at(0) == ' '){
            input.erase(0,1);
        }
        std::size_t foundAdd = input.find("+");
            if (foundAdd!=std::string::npos){
                std::size_t foundSpace = input.find(" ");
                string num1 = input.substr(0,foundSpace);
                std::size_t foundSpace2 = input.rfind(" ");
                string num2 = input.substr(foundSpace2 + 1, input.size() - foundSpace2);
                answer = add(num1, num2);
            }
        std::size_t foundMult = input.find("*");
            if (foundMult!=std::string::npos){
                std::size_t foundSpace = input.find(" ");
                string num1 = input.substr(0,foundSpace);
                std::size_t foundSpace2 = input.rfind(" ");
                string num2 = input.substr(foundSpace2 + 1, input.size() - foundSpace2);
                answer = multiply(num1, num2);
            }
        cout << "ans =" << endl;
        cout << endl;
        cout << "    " << answer << endl;
        cout << endl;
        getline(cin, input);
    }
    cout << endl;
    cout << "farvel!" << endl;
    
}

