#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std;

char computeCheckDig(const char*);

char rndDig() {
    return rand() % 10 + 48;
}

char* generateCardNumber()
{
    char* number = new char[12];
    for(int i =0;i<11;i++)
    {
        number[i] = rndDig();
    }
    number[11] = computeCheckDig(number);
    return number;
}

int numChars(const char* num) {
    const char* current = num;
    int count = 0;
    while (*current != '\0') {
        count++;
        current++;
    }
    return count;
}

char computeCheckDig(const char* cardNumber) {
    int cardNumberLength = numChars(cardNumber);
    int sum = 0;
    bool shouldDouble = true; //Used for doubling only odd digits
    for (int i = cardNumberLength - 2; i >= 0; i--) //Start with second digit from right
    {
        int d = cardNumber[i] - 48; //Convert char to int
        int s = d;
        if (shouldDouble) {
            if (2 * d > 9) {
                s = floor(2 * d / 10)+(2 * d) % 10;
            } else {
                s = 2 * d;
            }
        }
        sum += s;
        shouldDouble = !shouldDouble;
    }
    int chkDig = sum * 9 % 10;
    return chkDig + 48;
}

void inputNumberMode()
{
    cout << "Enter a credit card number: ";
        string cardNumber;
        cin >> cardNumber;
        int cardNumberLength = numChars(cardNumber.c_str());
        if(computeCheckDig(cardNumber.c_str()) == cardNumber.c_str()[cardNumberLength-1])
            cout << "Number is valid." << endl;
        else
            cout << "Number is invalid." << endl;
}

void generateNumberMode()
{
    char* cardNumber = generateCardNumber();
    int cardNumberLength = numChars(cardNumber);
    bool valid = computeCheckDig(cardNumber) == cardNumber[cardNumberLength-1];
    if(valid)
    {
        for(int i=0;i<cardNumberLength;i++)
        {
            cout << cardNumber[i];
        }
        cout << " Valid" << endl;
    }
}

int main() {
    srand(time(0));
    while (true) {
        inputNumberMode();
    }
}