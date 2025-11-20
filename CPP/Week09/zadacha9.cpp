/*
    1. Конструкторът е псевдо-метод, чието име съвпада с това на класа и задължително НЕ
    връща стойност. Нормалния метод може да се кръщава всякак (хубаво е в името да има глагол)
    и се залага тип, който се връща. Конструктора трябва да е public, нормалния метод може
    и private.

    2. Идеята на деструктура е да "унищожава" обекта.Извиква се автоматично, когато обектът 
    не съществува вече (напр. завършва програмата или излезе извън обхват). Именува се 
    като конструктора, но се слага тилда (~) пред името на класа. МОже да има само един и
    не приема аргументи. Жизненоважен е при работа с динамична памет, защото там има риск
    от memory leak.

    3. this е указател към текущия обект. Използваме го в конструктора, когато имената на 
    параметрите съвпадат с имената на член-променливите, за да ги разграничим.
*/
#include <iostream>
using namespace std;

class Car {
    private:
        std::string brand;
        int year;
        int speed;
    public:
        Car(){
            this->brand = "Unknown";
            this->year = 2020;
            this->speed = 0;

            cout << "Car object created with default values." << endl;
        }
        Car(std::string brand, int year, int speed){
            this->brand = brand;
            this->year = year;
            this->speed = speed;

            cout << "Car object created with custom parameters." << endl;
        }
        ~Car(){
            cout << "Car " << this->brand << " from " << this->year << " destroyed." << endl;
        }
};

int main()
{
    Car c1;
    Car c2("Audi", 2023, 180);

    {
        Car c3("Lada", 1985, 90);
    }

    return 0;
}