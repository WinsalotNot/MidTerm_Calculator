#include<iostream>
#include<string>
#include "Sci_Calcu.h"
using namespace std;

index::index(): equation(""), result(0) {}
index::index(string& n, float r) : equation(n), result(r) {}
void index::print(){
    cout << "\tEquation: " << equation << endl;
        cout << "\tThe result: " << result << endl<<endl;
}

 // Function to insert data to a previously initialized class
 void index::Insert(string& n, float r){
    equation = n;
    result = r;
 }
