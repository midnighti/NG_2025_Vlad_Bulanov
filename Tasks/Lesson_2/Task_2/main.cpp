#include <iostream>
#include <string>

using namespace std;

int userInput(string text){
    int value = 0;
    cout << text << ": ";
    cin >> value;
    return value;
}

void fillingArray (int* arr){
    for (int index = 0; index < 5; index ++)
        arr[index] = userInput("Enter numder");
}

void printStars (int* arr){
    for (int row = 0; row < 5; row++){
        for (int index = 0; index < arr[row]; index ++)
            cout << "*";
        cout << endl;
    }
}

int main()
{
    int arr[5];
    fillingArray(arr);
    printStars(arr);

    return 0;
}
