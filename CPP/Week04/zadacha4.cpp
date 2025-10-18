#include <iostream>
#include <cstring>
#include <climits>
using namespace std;


// ------------TASK-01-------------------

void arrayFiller(int array[]);
int biggestElement(int array[]);
int sumOfPositives(int array[]);


// ------------TASK-02-------------------
void reverseString(char str[]);

// ------------TASK-03-------------------
void increase_value(int num);
void increase_reference(int &num);

// ------------TASK-04-------------------
double average_array(const int arr[], int size);


// ------------MAIN----------------------
int main() {
    // ---------- ТЕСТ НА TASK 01 ----------
    int numbers[10];
    arrayFiller(numbers);
    cout << "Biggest element: " << biggestElement(numbers) << endl;
    cout << "Sum of positives: " << sumOfPositives(numbers) << endl;

    // ---------- ТЕСТ НА TASK 02 ----------
    char text[50];
    cout << "Enter a string: ";
    cin >> text;
    reverseString(text);

    // ---------- ТЕСТ НА TASK 03 ----------
    int x = 5;
    cout << "\nInitial x = " << x << endl;

    increase_value(x);
    cout << "After increase_value(x): " << x << endl;

    increase_reference(x);
    cout << "After increase_reference(x): " << x << endl;

    // ---------- ТЕСТ НА TASK 04 ----------
    cout << "\nAverage of array: " << average_array(numbers, 10) << endl;

    return 0;

    return 0;
}

//-----------INITIALIZATIONS-------------
void arrayFiller(int array[]){
    int a;

    for (int i = 0; i < 10; i++){
        cout << "Enter number " << i + 1<< ": " << endl;
        cin >> a;
        array[i] = a;
    }
}

int biggestElement(int array[]){
    int maxNumber = INT_MIN;

    for (int i = 0; i < 10; i++){
        if (array[i] > maxNumber){
            maxNumber = array[i];
        }
    }

    return maxNumber;
}

int sumOfPositives(int array[]){
    int sum = 0;

    for (int i = 0; i < 10; i++){
        if (array[i] > 0){
            sum += array[i];
        }
    }

    return sum;
}

void reverseString(char str[]){
    int length = strlen(str);
    cout << "Reversed string: ";
    for (int i = length - 1; i >= 0; i--){
        cout << str[i];
    }
    cout << endl;
}

void increase_value(int num){
    // Тук променливата num е *копие* на оригиналната стойност
    // Промените направени в тази функция засягат само копието
    // Оригиналната променлива от main не се променя

    num += 10;
}
void increase_reference(int &num){
    // Тук променливата num е референция към оригиналната
    // Промените се прилагат директно върху нея
    // Затова стойността се променя и в main()

    num += 10;
}

double average_array(const int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < 10; i++){
         sum += arr[i];        
    }

    return sum / size;
}