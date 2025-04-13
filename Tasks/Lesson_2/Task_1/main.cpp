#include <iostream>
#include <string>

using namespace std;

void drawLine(){
    cout << "------------------------" << endl;
}

void getValueOfAccount(int accountNumber, long* accounts){
    drawLine();
    cout << "There is " << accounts[accountNumber] << " money in the account" << endl;
}

void deposit (int accountNumber, long* accounts, long value){
    drawLine();
    accounts[accountNumber] = accounts[accountNumber] + value;
    cout << "There is " << accounts[accountNumber] << " money in the account" << endl;
}

void withdraw (int accountNumber, long* accounts, long value){
    drawLine();
    if (accounts[accountNumber] == 0){ cout << "You have no money in the account" << endl; }
    else{
        accounts[accountNumber] = accounts[accountNumber] - value;
        cout << "There is " << accounts[accountNumber] << " money in the account" << endl;
    }
}

void getValuesOfAllAccounts (long* accounts){
    drawLine();
    for (int index = 0; index < 10; index++)
        cout << index + 1 << " : " << "$" << accounts[index] << endl;
}

int menu(){
    drawLine();
    int choice = 0;
    cout << "1: deposit on account" << endl << "2: withdraw from account" << endl << "3: get value of account" << endl << "4: get value of all accounts" << endl << "5: exit" << endl;
    cout << "Enter number of mode: ";
    cin >> choice;
    return choice;
}

int userInput(string text){
    long value = 0;
    cout << text << ": ";
    cin >> value;
    return value;
}

int main()
{
    long accounts[10];
    for (int index = 0; index < 10; index++)
        accounts[index] = 0;

    int choice = menu();
    do{
    if (choice == 1) {
        int accountNumber = userInput("Enter account number");
        long value = userInput("Enter value");
        deposit(accountNumber, accounts, value);
        choice = menu();
    }
    else if (choice == 2) {
        int accountNumber = userInput("Enter account number");
        long value = userInput("Enter value");
        withdraw(accountNumber, accounts, value);
        choice = menu();
    }
    else if (choice == 3) {
        int accountNumber = userInput("Enter account number");
        getValueOfAccount(accountNumber, accounts);
        choice = menu();
    }
    else if (choice == 4) {
        getValuesOfAllAccounts(accounts);
        choice = menu();
    }
    else if (choice == 5) {
        return 0;
    }else {
        drawLine(); cout << "Nothing is selected" << endl;
        choice = menu();
    }
    }while (choice != 0);

    // deposit(1, accounts, 10);
    // withdraw(2, accounts, 10);
    //getValuesOfAllAccounts(accounts);

    return 0;
}
