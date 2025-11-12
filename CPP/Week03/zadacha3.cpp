#include <iostream>
using namespace std;

int year_checker(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        cout << "Leap year" << endl;
    }else {
        cout << "Not a leap year" << endl;
    }

    return 0;
}

int text_calculator(int a, int b, char op)
{
    switch (op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                cout << "Error division by zero" << endl;
                return 1;
            }
            return a / b;
        default: 
            cout << "Not a valid operator!" << endl;
            return 1;
    }
}

int multiplying_table()
{
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            cout << i << " * " << j << " = " << i * j << "\t";
        }
        cout << endl;
    }
    return 0;
}


int positives_sum() 
{
    int sum = 0;
    int a;

    cout << "Enter a: ";
    cin >> a;

    while (a > 0){
        sum += a;

        cout << "Enter a: ";
        cin >> a;
    }

    return sum;
}

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;
    year_checker(year);

    int x, y;
    char op;
    cout << "Enter two numbers for calculation: ";
    cin >> x >> y;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Result: " << text_calculator(x, y, op) << endl;

    cout << "Multiplication table:" << endl;
    multiplying_table();

    cout << positives_sum();

    return 0;
}