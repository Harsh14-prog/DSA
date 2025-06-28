#include <iostream>
using namespace std;

// Function to calculate digit^count
int power(int digit, int count) {
    int multi = 1;

    // Multiply digit by itself 'count' times
    while (count--) {
        multi = multi * digit;
    }

    return multi;
}

// Function to count the number of digits in a number
int countDigits(int n) {
    int count = 0;

    while (n != 0) {
        int digit = n % 10; // get the last digit (not used, can be skipped)
        count++;            // increase digit count
        n = n / 10;         // remove the last digit
    }

    return count;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int n) {
    int sum = 0;
    int number = n;             // Store original number to compare later
    int count = countDigits(n); // Get total number of digits

    while (n != 0) {
        int digit = n % 10;                         // extract last digit
        sum = sum + power(digit, count);           // add digit^count to sum
        n = n / 10;                                 // remove last digit
    }

    // If sum of powered digits equals the original number, it's Armstrong
    if (sum == number) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n = 1634;
    bool ans = isArmstrong(n);      
    cout << ans;                  
}
