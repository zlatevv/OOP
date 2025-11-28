/*
    1. Наследяване: Идеята е производният клас да получава (наследява) всички
    полета и методи на базовия клас. Така не се пише един и същ код многократно
    и се спазва принципът DRY (Don't Repeat Yourself). Спестява време, защото
    общата логика е написана само веднъж в базовия клас.

    2. private vs protected: private членовете на базовия клас НЕ са достъпни
    в наследника – виждат се само вътре в самия базов клас. protected членовете
    са скрити за външния код, но са достъпни в наследника. Т.е. protected позволява
    наследниците да работят с тези членове.

    3. virtual: Слага се пред метод в базовия клас, за да може при работа през
    указател към базов клас да се извика правилният метод от производния клас.
    Това включва динамично свързване (late binding) и позволява полиморфизъм.
*/
#include <iostream>
using namespace std;

class Employee {
    protected:
        std::string name;
        double salary;
    public:
        Employee(const std::string& name, double salary)
            : name(name), salary(salary) {}
        
        virtual double calculateBonus() const{
            return salary * 0.1;
        }

        virtual void displayInfo() const{
            cout << "Name: " << name << ", salary: " << salary << endl;
        }

        std::string getName() const {return name; }
};

class Manager : public Employee{
    private:
        std::string department;
    
    public:
        Manager(std::string name, double salary, std::string department) : Employee(name, salary), department(department) {}

        double calculateBonus() const override{
            return salary * 0.2;
        }
};

int main() 
{
    Employee e1("Ivan Ivanov", 3000.0);
    Manager m1("Petar Petrov", 5000.0, "IT");

    Employee* employees[2];
    employees[0] = &e1;
    employees[1] = &m1;

    for (int i = 0; i < 2; i++){
        cout << employees[i]->getName() << " Bonus: " << employees[i]->calculateBonus() << endl;
    }
    
    return 0;
}