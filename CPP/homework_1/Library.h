#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Member.h"
#include "Book.h"
#include "Loan.h"

using namespace std;

class Library {
    private:
        vector<Book> books;
        vector<Member> members;
        vector<Loan> loans;
    public:
        void addBook(const Book& b){
            books.push_back(b);
        }

        void addMember(const Member& m){
            members.push_back(m);
        }

        bool hasBook(const std::string& isbn) const {
            for (const auto& book : books){
                if (book.getISBN() == isbn){
                    return true;
                }
            }

            return false;
        }

        bool isBookAvailable(const std::string& isbn) const {
            for (const auto& loan : loans){
                if (loan.getISBN() == isbn && !loan.isReturned()){
                    return false;
                }
            }

            return true;
        }

        bool isValidMember(const std::string& memberId) const{
            for (const auto& member : members){
                if (member.getMemberId() == memberId){
                    return true;
                }
            }

            return false;
        }
        bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
            if (!hasBook(isbn)) return false;
            if (!isBookAvailable(isbn)) return false;
            if (!isValidMember(memberId)) return false;

            Loan loan(isbn, memberId, start, due);
            loans.push_back(loan);

            return true;
        }

        bool returnBook(const string& isbn, const string& memberId) {
            for (auto& loan : loans) {
                if (loan.getISBN() == isbn && loan.getMemberId() == memberId && !loan.isReturned()){
                    loan.markReturned();
                    return true;
                }
            }

            return false;
        }

        vector<Book> findByAuthor(const string& authorName) const {
            vector<Book> filteredBooks;

            for (const auto& book : books){
                if (book.getAuthor().getName().find(authorName) != std::string::npos){
                    filteredBooks.push_back(book);
                }
            }

            return filteredBooks;
        }

        std::string to_string() const {

            return "Books: " + std::to_string(books.size()) +
                ", Members: " + std::to_string(members.size());
        }
};