/*
    THEORY

    1. struct работи добре за групиране на данни, както досега имаше данни за студент. Проблемът е че ако някой напише в main метода данни за дадено поле, няма как да ги валидираме
    тоест те ще се запишат независимо от вярността им (например няма как да ни подадат празно има т.н), членовете са публични по подразбиране. Класът (class) като ни предлага
    енкапсулация и access control върху данните. Те по подразбиране са private -> не могат да се модифицират директно в main, а най-често е чрез извикане на сет метод.
    В сет метода може да има валидация и при несъответствие да хвърли грешка

    2. Енкапсулатцията е принцип от ООП, при който вътрешното състояние на обекта се скрива от външния свят,  а достъпът до него става само чрез контролирани интерфейси
    Капсулацията в С++ се получава чрез private (полетата) и public (методи, които предоставят контролирано взаимодействие с данните)

    3. Ролята на сет метода е да задава стойност на private променливи. Той е важен, защото директният достъп до полета не позволява валидация. 
    Чрез setter метода можем да проверим коректността на стойността, преди да бъде записана.
*/
#include <iostream>
using namespace std;

class Rectangle {

private:
    double length;
    double width;
public:
    void setLength(double l){
        if (l < 0){
            cout << "Error given length is negative!" << endl;
            length = 1.0;
        }else {
            length = l;
        }
    }
    void setWidth(double w){
        if (w < 0){
            cout << "Error given width is negative!" << endl;
            width = 1.0;
        }else {
            width = w;
        }
    }

    double getLength(){return length;}
    double getWidth(){return width;}

    double calculateArea(){return length * width;}
    double calculatePerimeter(){return 2 * (length + width);}
};

int main()
{
    Rectangle r1;

    r1.setLength(10.0);
    r1.setWidth(5.0);

    cout << "Length is: " << r1.getLength() << endl;
    cout << "Width is: " << r1.getWidth() << endl;
    cout << "Area is: " << r1.calculateArea() << endl;
    cout << "Perimeter is: " << r1.calculatePerimeter() << endl;

    r1.setLength(-5.0);

    if (r1.getLength() == 1.0){
        cout << "Ma setter works" << endl;
    }

    return 0;
}