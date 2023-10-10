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
