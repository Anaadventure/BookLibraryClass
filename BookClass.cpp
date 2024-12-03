// BookClass.cpp: this is the file where storage the information about the BookClass.h.
#include <iostream>
#include <string>
using namespace std;
#include"BookClass.h"

Book::Book() : title(""), author(""), isbn(""), availability(true) {}

void Book::setBookDetails(const string& bookTitle, const string& bookAuthor, const string& bookISBN, bool isAvailable) {
    title = bookTitle;
    author = bookAuthor;
    isbn = bookISBN;
    availability = isAvailable;
}

void Book::displayBookDetails() const {
        cout << "Title: " << title << "\n"
        << "Author: " << author << "\n"
        << "ISBN: " << isbn << "\n"
        << "Availability: " << (availability ? "Available" : "Borrowed") << "\n";
}

bool Book::borrowBook() {
    if (availability) {
        availability = false;
        return true;
    }
    return false;
}

void Book::returnBook() {
    availability = true;
}

string Book::getISBN() const {
    return isbn;
}

bool Book::isAvailable() const {
    return availability;
}