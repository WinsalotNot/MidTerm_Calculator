#include <iostream>
#include <string>
#include <cmath>
#include "Sci_Calcu.h"
using namespace std;



float calculator::namedCalc(string val){
     int i=0;
        calculator calc;
        string s="", u = "";
        float x;
        while (i < val.length()) {
        if (isalpha(val[i])) {
            s += val[i];
        } else {
            u += val[i];
        }
        i++;
        }
        u = u.substr(1, u.length() - 2);
        x = calc.calc(u);
        if (s == "sin") {
            return sin(x * M_PI / 180.0);
        } else if (s == "cos") {
            return cos(x * M_PI / 180.0);
        } else if (s == "tan") {
            return tan(x * M_PI / 180.0);
        } else if (s == "asin") {
            if (x >= -1 && x <= 1) {
                return asin(x) * 180.0 / M_PI;
            } else {
                cout << "ArcSin must be between -1 and 1" << endl;
                return NAN;
            }
        } else if (s == "acos") {
            if (x >= -1 && x <= 1) {
                return acos(x) * 180.0 / M_PI;
            } else {
                cout << "ArcCos must be between -1 and 1" << endl;
                return NAN;
            }
        } else if (s == "atan") {
            if (x >= -1 && x <= 1) {
                return atan(x) * 180.0 / M_PI;
            } else {
                cout << "Arctan must be between -1 and 1" << endl;
                return NAN;
            }
        } else if (s == "sqrt") {
            if (x >= 0) {
            return sqrt(x);
            } else {
                cout << "Sqrt cannot be negative!"<<endl;
            return NAN;
            }
        } else if (s == "exp") {
            return exp(x);
        } else if (s == "log") {
            if (x >= 0) {
            return log10(x);
            } else {
                cout << "Log cannot be negative!"<<endl;
                return NAN;
            }
        } else if (s == "ln") {
            if (x >= 0) {
                return log(x);
            } else {
                cout << "Log cannot be negative!"<<endl;
                return NAN;
            }
        }
        else return NAN;
}



float calculator::calc(string equation){
    doublyLinkedList equationElements;
        float numHolder=0;
        string stringHolder = "";
        for (int i = 0; i < equation.length(); i++){
            if (equation[i] == '(' && !isalpha(equation[i-1]) && !isdigit(equation[i-1])) {
                int parOpen = 1;
                int parClose = 0;
                while (parOpen != parClose) {
                    stringHolder += equation[i];
                    i++;
                    if (equation[i] == '(') {
                        parOpen++;
                    } else if (equation[i] == ')') {
                        parClose++;
                    }
                    if (i >= equation.length()) {
                        cout << "Parenthesis error!"<<endl;
                        return NAN;
                    }
                }
                stringHolder += ")";
                equationElements.insertValue(stringHolder);
                stringHolder = "";
            } else if((isalpha(equation[i])&& equation[i-1] != ')')){
                while (equation[i] != ')') {
                    if (i >= equation.length()) {
                        cout << "Parenthesis error!"<<endl;
                        return NAN;
                    }
                    stringHolder += equation[i];
                    i++;
                }
                stringHolder += equation[i];
                equationElements.insertValue(stringHolder);
                stringHolder = "";
            } else if (((isdigit(equation[i]) || equation[i] == '.')) && equation[i-1] != ')'){
                stringHolder += equation[i];
                if (!isdigit(equation[i+1]) && equation[i+1] != '.'){
                    equationElements.insertValue(stof(stringHolder));
                    stringHolder = "";
                }
            } else if (isOperator(equation[i])){
                if (isOperator(equation[i-1])) {
                    cout << "Operator error!"<< endl;
                    return NAN;
                } else if (equation[i] == '-' && i==0) {
                    stringHolder += equation[i];
                } else if (i==0) {
                    cout << "Operator shouldn't go first!"<<endl;
                    return NAN;
                } else {
                    stringHolder += equation[i];
                    equationElements.insertValue(stringHolder);
                    stringHolder = "";
                }
            } else if (equation[i] == '(' || equation[i] == ')') {
                stringHolder += equation[i];
                equationElements.insertValue(stringHolder);
                stringHolder = "";
            } else {
                cout<<"Input not valid!"<<endl;
                return NAN;
            }
        }
        calculate(equationElements);
        return equationElements.getFloat(0);
}

void calculator::calculate(doublyLinkedList &equationElements){
     string stringHolder = "";
        for (int i = 0; i < equationElements.checkSize(); i++){
            if (equationElements.checkValue(i) == 0) {
                stringHolder = equationElements.getString(i);
                if (stringHolder[0] == '('){
                    stringHolder = stringHolder.substr(1, stringHolder.length() - 2);
                    if (stringHolder[0]= '-') {
                        equationElements.replaceValue(i,stof(stringHolder));
                    } else {
                    equationElements.replaceValue(i,calc(stringHolder));
                    }
                } else if (isalpha(stringHolder[0])) {
                    float x = namedCalc(stringHolder);
                    if (isnan(x)){
                        equationElements.replaceValue(0,NAN);
                        return;
                    }
                    equationElements.replaceValue(i,x);
                } 
            }   
        }
        takeOperator(equationElements);
}

void calculator::takeOperator(doublyLinkedList &equationElements){
    for (int i = 0; i < equationElements.checkSize() - 1; i++) {
            if (equationElements.checkValue(i) == 0) {
                string stringHolder = equationElements.getString(i);
                if (isOperator(stringHolder[0])) {
                    string stringHolder2 = equationElements.getString(i + 2);

                    if (stringHolder[0] == '^') {
                        float numHolder = operatorCalc(equationElements, stringHolder, i);

                        if (!isnan(numHolder)) {
                            equationElements.deleteNode(i - 1);
                            equationElements.deleteNode(i - 1);
                            equationElements.replaceValue(i - 1, numHolder);
                            i -= 2;
                        }
                    } else if (isWhat(stringHolder[0], "*/") && !isWhat(stringHolder2[0], "^")) {
                        float numHolder = operatorCalc(equationElements, stringHolder, i);

                        if (!isnan(numHolder)) {
                            equationElements.deleteNode(i - 1);
                            equationElements.deleteNode(i - 1);
                            equationElements.replaceValue(i - 1, numHolder);
                            i -= 2; 
                        }
                    } else if (isWhat(stringHolder[0], "-+") && !isWhat(stringHolder2[0], "^*/")) {
                        float numHolder = operatorCalc(equationElements, stringHolder, i);

                        if (!isnan(numHolder)) {
                            equationElements.deleteNode(i - 1);
                            equationElements.deleteNode(i - 1);
                            equationElements.replaceValue(i - 1, numHolder);
                            i -= 2;
                        }
                    }
                }
            }
        }   

        if (equationElements.checkSize() >1) {
            takeOperator(equationElements);
        }
    }

