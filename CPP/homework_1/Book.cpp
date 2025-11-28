#include <iostream>
#include <stdexcept>
#include "Author.cpp"
using namespace std;

class Book {
    private:
        std::string title;
        Author author;
        double price;
        int year;
        std::string isbn;
        static int totalBooks;
    public:
        Book() : title(""), author(), price(0.0), year(0), isbn("") {
            totalBooks++;
        }
        ~Book() {totalBooks--;};

        Book(const std::string& title, const Author& author, double price, int year, const std::string& isbn)
            : title(title), author(author), price(price), year(year), isbn(isbn) {totalBooks++;}
        
        Book(const Book& other)
            : title(other.title),
            author(other.author),
            price(other.price),
            year(other.year),
            isbn(other.isbn)
            {
                totalBooks++;
            }

        Book(Book&& other) noexcept
            : title(std::move(other.title)),
            author(std::move(other.author)),
            year(other.year),
            price(other.price),
            isbn(std::move(other.isbn))
            {
                totalBooks++;
            }
        Book& operator=(const Book& other) {
            if (this != &other) {
                title  = other.title;
                author = other.author;
                year   = other.year;
                price  = other.price;
                isbn   = other.isbn;
            }
            return *this;
        }
        Book& operator=(Book&& other) noexcept {
            if (this != &other) {
                title  = std::move(other.title);
                author = std::move(other.author);
                year   = other.year;
                price  = other.price;
                isbn   = std::move(other.isbn);
            }
            return *this;
        }

        void setTitle(const std::string& title){
            if (title.empty()){
                throw std::invalid_argument("Invalid title!");
            }
            this->title = title;
        }

        void setPrice(double price){
            if (price < 0){
                throw std::invalid_argument("Price is negative");
            }

            this->price = price;
        }

        void setYear(int year){
            if (year < 1400 || year > 2025){
                throw std::invalid_argument("Invalid book year!");
            }

            this->year = year;
        }

        void setISBN(const std::string& isbn){
            if (isbn.empty()){
                throw std::invalid_argument("ISBN is empty!");
            }

            this->isbn = isbn;
        }

        static int getTotalBooks(){ return totalBooks;}

        string to_string() const {
            return "Title: " + title + ", Author: " + author.to_string() +
                ", Year: " + std::to_string(year) +
                ", Price: " + std::to_string(price) +
                ", ISBN: " + isbn;
            }
};
int Book::totalBooks = 0;