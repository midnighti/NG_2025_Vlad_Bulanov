#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void userInput(string text, char* userStr, int size) {
    cout << text << ": ";
    cin.getline(userStr, size);
}

int countVowel(char* str) {
    int count = 0;
    for (int i = 0; i < static_cast<int>(strlen(str)); i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int countUnspoken(char* str) {
    int count = 0;
    for (int i = 0; i < static_cast<int>(strlen(str)); i++) {
        char c = tolower(str[i]);
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            count++;
        }
    }
    return count;
}

void calculateTheRatio(int vowel, int unspoken) {
    if (vowel == 0 || unspoken == 0) {
        cout << "Cannot calculate ratio." << endl;
        return;
    }

    if (vowel > unspoken)
        cout << (vowel * 100 / unspoken) << "% more vowels" << endl;
    else if (vowel == unspoken)
        cout << "Equal number of vowels and unspoken" << endl;
    else
        cout << (unspoken * 100 / vowel) << "% more unspoken" << endl;
}

int main() {
    char userStr[100];
    userInput("Enter your string", userStr, 100);

    int vowels = countVowel(userStr);
    int unspoken = countUnspoken(userStr);

    cout << "Vowels: " << vowels << endl;
    cout << "Unspoken: " << unspoken << endl;

    calculateTheRatio(vowels, unspoken);

    return 0;
}
