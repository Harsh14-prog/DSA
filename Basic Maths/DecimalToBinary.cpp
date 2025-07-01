#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter a decimal number: ";
    cin >> a;

    if (a == 0) {
        cout << "0" << endl;
        return 0;
    }

    int arr[32]; // For storing binary digits
    int i = 0;

    while (a != 0) {
        arr[i++] = a % 2;
        a = a / 2;
    }

    cout << "Binary: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j];
    }
    cout << endl;

    return 0;
}
