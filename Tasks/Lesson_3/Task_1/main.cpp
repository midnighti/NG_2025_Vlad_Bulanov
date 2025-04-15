#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void userInput(string text, char* userStr){
    int size = sizeof(userStr) - 1;
    cout << text << ": ";
    cin.getline(userStr, size);
}

bool isLetter(char ch){
    if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123)){
        return true;
    }else return false;
}

void wordCount(char* text){
    int count = 0;
    for (int index = 0; index < static_cast<int>(strlen(text)); index++){
        if (isLetter(text[index]) == true && (isLetter(text[index+1]) == false || text[index+1] == 0)) {
            count++;
        }
    }
    cout << "Number of words per line: " << count << endl;
}

int main()
{
    char userStr[100];
    userInput("Enter your string", userStr);
    wordCount(userStr);
    return 0;
}
