/*=========== ТЕОРИЯ =========
    1. Когато съхраняваме данните си във файлове, те се записват на хард диска на компютъра съответно няма да се изтрият и могат да се използват повторно в други програми, 
    освен ако потребителят не реши да ги изтрие. При съхранение на тези данни в оперативната памет (RAM), след завършване на програмата тези данни се губят

    2. За запис или писане във файл се използва std::ofstream (Output File Stream), a за четене от файл се използва std::ifstream (Input File Stream). Има 
    и трети метод - std::fstream, който може и да чете, и да записва от файл. Препоръчително е да се използват отделните, за по-ясно.

    3. Когато отворим файл в режим std::ios::out (по подразрбиране за запис) съдържанието във файла ще се изтрие (ако съществува) и пишем от началото, докато при 
    std::ios::app ако файлът съществува започваме да пишем накрая, без да се трие стара информация.
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    std::string name;
    int fn;
    double avg_grade;
};

int task_01();
int task_02();
int save_student(const Student& student);

int main()
{
    task_01();
    task_02();


    Student student1 = {"Tsvetan", 34235266, 5.80};
    Student student2 = {"Peter", 135236734, 5.50};

    save_student(student1);
    save_student(student2);

    return 0;
}

int task_01()
{
    std::string name, surname;
    int age;

    cout << "Enter first name: " << endl;
    cin >> name;
    cout << "Enter last name: " << endl;
    cin >> surname;
    cout << "Enter age: " << endl;
    cin >> age;

    std::ofstream out_file("users.txt", std::ios::app);

    if (out_file.is_open()){
        out_file << name << " " << surname << " " << age << endl;
        
        out_file.close();
    }else {
        std::cerr << "Could not open the file! " << endl;
    }

    return 0;
}

int task_02()
{
    std::ifstream in_file("users.txt");

    if (in_file.is_open()){

        std::string name, surname;
        int age;

        while (in_file >> name >> surname >> age){
            cout << name << " " << surname << " is " << age << " years old!" << endl;
        }

        in_file.close();
    }else {
        std::cerr << "Could not open the file! " << endl;
    }
    return 0;
}

int save_student(const Student& student)
{
    std::ofstream out_file("students.csv", std::ios::app);

    if (out_file.is_open()){
        out_file << student.name << "," << student.fn << "," << student.avg_grade << endl;

        out_file.close();
    }else {
        std::cerr << "Could not open the file! " << endl;
    }

    return 0;
}