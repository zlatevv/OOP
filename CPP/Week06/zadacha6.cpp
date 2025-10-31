#include <iostream>
using namespace std;

/* THEORY
    1. Структурата е начин да се групират няколко променливи с различни типове в един логически блок под едно общо име, 
    При масива това не е възможно, тъй като той може да съдържа само елементи от един и същи тип.

    2. Двата записа по дереференция или с оператора -> са еквивалентни и правят едно и също (достъпват даден член на структурата), но записа със -> е много по-чист и затова
    той е предпочитан за използване във всички случаи. 

    3. Използването на enum е доста по-удобно, защото там се използват точно конкретни стойности, което прави кода по-четим и сигурен. По подразбиране компилатора присвоява на 
    първата константа 0, после на втората 1 и т.н. Ако напишем в програмата int color = 0; не става ясно дали този цвят е син, зелен или някой друг 
    докато с enum Color {RED, GREEN, BLUE}; и color = RED; кодът е много по-разбираем.
*/

// ------------TASK-04-----------
enum Genre {
    NOVEL,
    POETRY,
    FANTASY,
    TECH
};

// -------TASK-01---------
struct Book{
    std::string title;
    std::string author;
    int year_published;
    double price;
    Genre genre;
};

// ------------TASK-02-----------
void second_task();

// ------------TASK-03-----------
void apply_discount(Book *b_ptr, double discount_percent);

int main()
{   
    // ------------TASK-01-----------
    Book book1;

    cout << "Enter the book title: " << endl;
    cin >> book1.title;
    cout << "Enter the book author: " << endl;
    cin >> book1.author;
    cout << "Enter the book year of publishing: " << endl;
    cin >> book1.year_published;
    cout << "Enter the book price: " << endl;
    cin >> book1.price;

    printf("%s has published %s in %d. It's price is %.2f !\n", book1.author.c_str(), book1.title.c_str(), book1.year_published, book1.price);

    // ------------TASK-02-----------
    second_task();

    // ------------TASK-03-----------

    printf("The book from the first task's price is %.2f before discount\n", book1.price);
    apply_discount(&book1, 0.20);
    printf("The book from the first task's price is %.2f after discount\n", book1.price);

    // ------------TASK-04-----------
    book1.genre = Genre::FANTASY;

    switch (book1.genre){
        case FANTASY: printf("The book is a fantasy\n"); break;
        case POETRY: printf("The book is a poetry\n"); break;
        case NOVEL: printf("The book is a novel\n"); break;
        case TECH: printf("The book is a tech\n"); break;
    }
}



void second_task()
{
    Book books[3];

    for (int i = 0; i < 3; i++){
        Book book;

        cout << "Enter book number " << i + 1 << " title: " << endl;
        cin >> book.title;
        cout << "Enter book number " << i + 1 << " author: " << endl;
        cin >> book.author;
        cout << "Enter book number " << i + 1 << " year of publishing: " << endl;
        cin >> book.year_published;
        cout << "Enter book number " << i + 1 << " price: " << endl;
        cin >> book.price;

        books[i] = book;
    }
    int furthest_year = 2025;
    Book oldestBook;
    for (int i = 0; i < 3; i++){
        Book currentBook = books[i];

        if (currentBook.year_published < furthest_year){
            furthest_year = currentBook.year_published;
            oldestBook = currentBook;
        }
    }
    printf("%s has published %s in %d. It's price is %.2f !\n", oldestBook.author.c_str(), oldestBook.title.c_str(), oldestBook.year_published, oldestBook.price);
}

void apply_discount(Book *b_ptr, double discount_percent)
{
    b_ptr->price -= b_ptr->price * discount_percent;
}