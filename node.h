#ifndef Node_h
#define Node_h
#include <iostream>
#include <string>


using namespace std;
class Node {
public:
    variant<string, float> value;
    Node* next;
    Node* previous;
};

#endif
