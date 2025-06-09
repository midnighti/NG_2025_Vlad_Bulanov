#include <iostream>

using namespace std;

int drawDiamond (int userSize) {
    int half = userSize / 2;

    for (int row = 0; row <= half; row++) {
        for (int space = 0; space < half - row; space++)
            cout << " ";
        for (int star = 0; star < 2 * row + 1; star++)
            cout << "*";
        cout << endl;
    }

    for (int row = half - 1; row >= 0; row--) {
        for (int space = 0; space < half - row; space++)
            cout << " ";
        for (int star = 0; star < 2 * row + 1; star++)
            cout << "*";
        cout << endl;
    }

    return 0;
}

void drawSpiral (int size){

}

int main() {
    int userSize = 0;
    cout << "Enter userSize (odd number): ";
    cin >> userSize;

    if (userSize % 2 == 0) {
        cout << "Please enter an odd number!" << endl;
        return 1;
    }

    drawDiamond(userSize);
    drawSpiral(userSize);

    return 0;
}
