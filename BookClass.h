// BookClass.h : This file contains the 'header' function. Where is the functions for the Book Class.

#include <iostream>
#include <string>
using namespace std;


// This BookClass contains the sample informaton about the books: Title, Author Name's, ISBN (The unique identifier for the book),
// and Availabilty ( A flag indicating whether the book is available for borrowing or is already borrowed).
class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;

public:
    Book();
    void setBookDetails(const string& bookTitle, const string& bookAuthor, const string& bookISBN, bool isAvailable);
    void displayBookDetails() const;
    bool borrowBook();
    void returnBook();
    string getISBN() const;
    bool isAvailable() const;
};
