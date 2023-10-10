#ifndef CALCULATORH
#define CALCULATORH
#include <iostream>
#include <string>
#include <cmath>
#include <variant>
using namespace std;

class Node {
public:
    variant<string, float> value;
    Node* next;
    Node* previous;
};

class doublyLinkedList{
    private:
    Node* head;
    public:
    doublyLinkedList();
    void insertValue(variant<string,float> val);
    void deleteNode(int val);
    void replaceValue(int position, variant<string, float> val);
    void print(float val);
    void printAll();  
    int checkSize();
    int checkValue(int val);
    string getString(int val);
    float getFloat(int val);
    
    };

class calculator {
    public:

    float operatorCalc(doublyLinkedList list,string val, int position);
    float namedCalc(string val);
    float calc(string equation);
    void calculate(doublyLinkedList &equationElements);
    void takeOperator(doublyLinkedList &equationElements);
};

class index {
    public:
    index();
    index( string& n, float r);

    void print();
     void Insert(string& n, float r);

     private:
    string equation;
    float result;

};

bool isOperator(char c);
bool isWhat(char c, string val);
string toLowerCase(const string& val);


#endif
