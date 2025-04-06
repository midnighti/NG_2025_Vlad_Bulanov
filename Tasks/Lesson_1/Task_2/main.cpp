#include <iostream>
#include <cmath>

using namespace std;

double sum (double firNum, double secNum) { return firNum + secNum; }

double sub (double firNum, double secNum) { return firNum - secNum; }

double mult (double firNum, double secNum) { return firNum * secNum; }

double devide (double firNum, double secNum) { return firNum / secNum; }

int main()
{
    double firNum, secNum;
    cout << "Enter first number: ";
    cin >> firNum;
    cout << "Enter second number: ";
    cin >> secNum;
    // string operations[6] = {'+', '-', '*', '/', 'pow', 'sqrt'};
    int operation = 0;
    cout << "Enter number of operation '+', '-', '*', '/', 'pow', 'sqrt': ";
    cin >> operation;
    switch (operation){
        case 1: cout << "Sum of your 2 nums: " << sum(firNum, secNum) << endl; break;
        case 2: cout << "Subtract of your 2 nums: " << sub(firNum, secNum) << endl; break;
        case 3: cout << "Multiply of your 2 nums: " << mult(firNum, secNum) << endl; break;
        case 4: cout << "Devide of your 2 nums: " << devide(firNum, secNum) << endl; break;
        case 5: cout << "Pow of your 2 nums: " << pow(firNum, secNum) << endl; break;
        case 6: cout << "Sqrt of your first num: " << sqrt(firNum) << endl << "Sqrt of your second num: " << sqrt(secNum) << endl; break;
    }

    return 0;
}
