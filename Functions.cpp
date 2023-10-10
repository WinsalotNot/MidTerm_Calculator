#include<iostream>
#include<string>
#include"Sci_Calcu.h"
using namespace std;

bool isOperator(char c) {
     string operators = "+-*/^%"; 

    for (int i = 0; i < operators.length(); ++i) {
        if (operators[i] == c) {
            return true;
        }
    }
    return false;
}

bool isWhat(char c, string val) {
    for (int i = 0; i < val.length(); ++i) {
        if (val[i] == c) {
            return true;
        }
    }
    return false;
}

string toLowerCase(const string& val) {
    string result;
    for (char c : val) {
        result += tolower(c);
    }
    return result;
}

