#include <iostream>
using namespace std;

int first_and_second_task();
void swap_by_pointer(int *a, int *b);
int fourth_task();

int main()
{
    first_and_second_task();

    int a = 5;
    int b = 10;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap_by_pointer(&a, &b);

    cout << "They have been swapped now!\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    fourth_task();

    return 0;
}

int first_and_second_task()
{
    int num = 15;
    int *ptr = &num;

    cout << "Num = " << num << endl;
    cout << "The address of Num = " << &num << endl;
    cout << "Pointer value = " << ptr << endl;
    cout << "Dereferenced value = " << *ptr << endl;

    *ptr = 42;

    cout << "After change via pointer: " << *ptr << endl;
    cout << "Num = " << num << endl;

    return 0;
}

void swap_by_pointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fourth_task()
{   
    cout << "\nThis is going to output the array now!\n";
    int arr[] = {1, 2, 3, 4, 5};
    int *arr_ptr = arr;

    for (int i = 0; i < 5; i++) {
        cout << *(arr_ptr + i) << " ";
    }

    cout << endl;
    return 0;
}
