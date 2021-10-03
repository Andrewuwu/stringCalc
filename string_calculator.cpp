#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    switch(digit){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            throw std::invalid_argument("Invalid");
    }   
    return 0;
}

char decimal_to_digit(unsigned int decimal) {
    switch(decimal){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            throw std::invalid_argument("Invalid");
    }   
    return '\0';
}

string trim_leading_zeros(string num) {
    string trimmed = "";
    bool negative = false;
    unsigned long i = 0;
    if (num.at(i) == '-'){
        i++;
        negative = true;
    }
    while(i < num.length()-1){
        if (num.at(i) == '0'){
            i++;
        }
        else{
            break;
        }
    }
    while (i < num.size()){
        trimmed.push_back(num.at(i));
        i++;
    }
    if (negative && trimmed != "0"){
        trimmed.insert(0, "-");
    }
    return trimmed;
}

string add(string lhs, string rhs) {
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    bool negative = false;
    if (lhs.at(0) == '-'){
        lhs.erase(0,1);
        negative = true;
    } 
    else {
        negative = false;
    }
    if (rhs.at(0) == '-'){
        rhs.erase(0,1);
        negative = true;
    }
    string answer = "";
    int i = lhs.length()-1;
    int j = rhs.length()-1;
    int carry = 0;
    while( i >= 0 || j >= 0){ 
        int temp = 0;
        if (i >= 0 && j >= 0) {
            temp = digit_to_decimal(lhs.at(i)) 
            + digit_to_decimal(rhs.at(j)) + carry;
        } else if(j < 0 && i >= 0){
            temp = digit_to_decimal(lhs.at(i)) + carry;
        } else if (i < 0 && j >= 0){
            temp = digit_to_decimal(rhs.at(j)) + carry;
        }
        carry = 0;
        if (temp > 9){
            temp = temp % 10;
            carry = 1;
        }
        char tempChar = decimal_to_digit(temp);
        answer.insert(0,1,tempChar);
        i--;
        j--;
    } 
    if (carry == 1){
        answer.insert(0,"1");
    }
    if (negative){
        answer.insert(0, "-");
    }
    return answer;
}

string multiply(string lhs, string rhs) {
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    bool lhsNegative = false;
    bool rhsNegative = false;
    if (lhs.at(0) == '-'){
        lhs.erase(0,1);
        lhsNegative = true;
    } else {
        lhsNegative = false;
    }
    if (rhs.at(0) == '-'){
        rhs.erase(0,1);
        rhsNegative = true;
    } else {
        rhsNegative = false;
    }
if (rhs.length() < 2){
    int digit = rhs.at(0);
    int number = digit_to_decimal(digit);
    string answer = add(lhs, lhs);
    for (int i = 0; i < number - 2; i++){
        answer = add(answer, lhs);
    }
    if ((lhsNegative && !rhsNegative) || (!lhsNegative && rhsNegative)){
        answer.insert(0, "-");
    }
    return answer;
}
   
    string answer = "";
    string multiplicationIndex = "2";
    
    
    answer = add(lhs, lhs);
    while (multiplicationIndex != rhs){
        answer = add(answer, lhs);
        multiplicationIndex = add(multiplicationIndex, "1");
    }
    if ((lhsNegative && !rhsNegative) || (!lhsNegative && rhsNegative)){
        answer.insert(0, "-");
    }
    return answer;
}
