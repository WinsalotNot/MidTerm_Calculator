#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <variant>
#include <cmath>
#include <string_view>
#include "Sci_Calcu.h"
using namespace std;
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class Database {
    public:
    void history() {}
};

int main() {
    calculator calc;
    std::vector<index> historyList;
    std::string n;
    std::string equa;
    int incorrectInputCount = 0;
    int TriesLeft = 3;

    while (true) {
        if (incorrectInputCount >= 3) {
            system("cls");
            std::cerr << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" 
                         "                       Too many incorrect inputs. Exiting...\n"
                         ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
            system("pause");
            break;
        }
        cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n"
                ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                "II||||||||||||||||||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||||||||||||||||||II\n"
                "II||||||||||||||||||[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]||||||||||||||||||II\n"
                "II||||||||||||||||||[                                       ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ************************************* ]||||||||||||||||||II\n"
                "II||||||||||||||||||[        What Do You Want To Do?        ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ************************************* ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ Type:                                 ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ 1 = Use The Scientific Calculator     ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ===================================== ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ 2 = Calculation History               ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ===================================== ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ 3 = Delete Calculation History        ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ===================================== ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ 4 = END!                              ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ r-----    -----    r-----    I   /    ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ |     |     |      |         |  /     ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ |     |     |      |         | /      ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ |-----      |      |         |-       ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ |           |      |         | \\      ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ |           |      |         |  \\     ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ |         -----    L-----    I   \\    ]||||||||||||||||||II\n"
                "II||||||||||||||||||[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]||||||||||||||||||II\n"
                "II||||||||||||||||||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||||||||||||||||||II\n"
                ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n"
                "\nEnter Option Here: ";
        
        std::cin >> n;
        std::cin.ignore();
        system("cls");

        if (n == "4") {
            break;
        } else if (n == "1") {
            cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n"
                ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                "II||||||||||||||||||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||||||||||||||||||II\n"
                "II||||||||||||||||||[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]||||||||||||||||||II\n"
                "II||||||||||||||||||[                                       ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ************************************* ]||||||||||||||||||II\n"
                "II||||||||||||||||||[  Enter the Equation to be Calculated  ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ************************************* ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ Rules:                                ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ - Limited to Trigonometry             ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   Natural Logarithm, Logarithm,       ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   Exponential, SquareRoot, Addition   ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   Subtraction, Division, and          ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   Multiplication                      ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ===================================== ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ - FOLLOWS PEMDAS (Parentheses,        ]||||||||||||||||||II\n"
                "II||||||||||||||||||[    Exponential, Multiplication,       ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   Division, Addition, Subtraction     ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ===================================== ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ - Trigonometry, Natural Logarithm,    ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   and Logarithm are calculated first! ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ ===================================== ]||||||||||||||||||II\n"
                "II||||||||||||||||||[ - Available operations are:           ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   addition(a+b), subtraction(a-b),    ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   multiplication(a*b), division(a/b), ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   power(a^b), trigonometry (sin(a),   ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   cos(a), tan(a), asin(a), acos(a),   ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   atan(a)), exponential(exp(a)),      ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   squareroot(sqrt(a)), log(log(a),    ]||||||||||||||||||II\n"
                "II||||||||||||||||||[   ln(a))                              ]||||||||||||||||||II\n"
                "II||||||||||||||||||[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]||||||||||||||||||II\n"
                "II||||||||||||||||||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||||||||||||||||||II\n"
                ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n";
            cout << "\nInsert your equation: " << endl;
            getline(cin >> ws, equa);
            system("cls");
            equa = toLowerCase(equa);
            float x = calc.calc(equa);
            cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n"
                    ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                    "=================================================================================\n\n"
                    "    Answer = " << x << endl;
            cout << "=================================================================================\n"
                    ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                    "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n";
            system("pause");
            system("cls");
            if (!isnan(x)) {
                index newIndex(equa,x);
                historyList.push_back(newIndex);
            }
        } else if (n == "2") {
            if(historyList.empty()) {
                cout << "#################################################################################\n"
                        "##########################    No History Available!    ##########################\n"
                        "#################################################################################\n"
                        "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n";
                system("pause");
                system("cls");
            } else { 
                int u =1;
                system("cls");
                cout << "#################################################################################\n"
                        "#############################     Your History!     #############################\n"
                        "#################################################################################\n"
                        "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n";
                for (auto i = historyList.begin(); i != historyList.end(); ++i) {
                    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
                            "=================================================================================\n\n"
                            "   Input " << u << ": " << endl;
                    (*i).print();
                    cout << "=================================================================================\n"
                            ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
                    ++u;
                }
                system("pause");
                system("cls");
            }
        } else if (n == "3") {
            historyList.clear();
            cout << "#################################################################################\n"
                    "############################     History Deleted     ############################\n"
                    "#################################################################################\n";
            system("pause");
            system("cls");
        } else {
            incorrectInputCount++;
            TriesLeft--;
            cout << "#################################################################################\n"
                    "####################    Invalid Option! Please Try Again!    ####################\n"
                    "####################               "<<TriesLeft<<" Tries Left              ####################\n"
                    "#################################################################################\n";
            system("pause");
            system("cls");
        }
    }
    cout << "#################################################################################\n"
            "######################  Thank You For Using Our Services!  ######################\n"
            "#################################################################################\n" << endl;
            system("pause");
    return 0;
}