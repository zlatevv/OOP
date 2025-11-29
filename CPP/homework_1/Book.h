
#include <iostream>
#include <stdexcept>
#include "Author.h"
using namespace std;

class Book {
    private:
        std::string title;
        Author author;
        int year;
        double price;
        std::string isbn;
        static int totalBooks;
    public:
        Book() : title(""), author(), year(0), price(0.0), isbn("") {
            totalBooks++;
        }
        ~Book() {totalBooks--;};

        Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn)
            : title(std::move(title)), author(std::move(author)), year(year),  price(price), isbn(std::move(isbn)) {totalBooks++;}
        
        Book(const Book& other)
            : title(std::move(other.title)),
            author(std::move(other.author)),
            year(other.year),
            price(other.price),
            isbn(std::move(other.isbn))
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

        std::string getTitle() const{ return title;}
        std::string getISBN() const{ return isbn;}
        Author getAuthor() const{ return author;}
        int getYear() const{ return year;}
        double getPrice() const{return price;}

        string to_string() const {
            return "Title: " + title + ", Author: " + author.to_string() +
                ", Year: " + std::to_string(year) +
                ", Price: " + std::to_string(price) +
                ", ISBN: " + isbn;
            }
};
int Book::totalBooks = 0;