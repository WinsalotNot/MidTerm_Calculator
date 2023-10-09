#include <iostream>
#include "Calculator.h"
#include <string>
using namespace std;

void ParsingString(string UserInput, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << UserInput[i] << endl;
    }
}
//test
int main()
{
    string Input;
    cout << "Enter string: ";
    getline(cin, Input);
    ParsingString(Input, Input.size());
}
