// BookLibraryClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "BookClass.h"
using namespace std;



/*Verson 1
int main() {
    const int NUM_BOOKS = 5;
    Book books[NUM_BOOKS];

    // Initialize the library: Array with 5 Books.
    books[0].setBookDetails("The Duke and I", "Julia Quinn", "1", true);
    books[1].setBookDetails("The Viscount Who Loved Me", "Julia Quinn", "2", true);
    books[2].setBookDetails("An Offer From a Gentleman", "Julia Quinn", "3", true);
    books[3].setBookDetails("Romancing Mister Bridgerton", "Julia Quinn", "4", true);
    books[4].setBookDetails("To Sir Phillip, With Love", "Julia Quinn", "5", true);

    string inputISBN;

    while (true) {
        cout << "Enter the ISBN of the book to borrow (or 0 to leave): ";
        getline(cin, inputISBN);

        if (inputISBN == "0") {
            cout << "Thank You. See you soon\n";
            break;
        }

        bool found = false;

        for (int i = 0; i < NUM_BOOKS; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].isAvailable()) {
                    if (books[i].borrowBook()) {
                        cout << "Borrowed Successfully\n";
                    }
                }
                else {
                    cout << "Book is unavailable\n";
                }
                break;
            }
        }

        if (!found) {
             cout << "Invalid ISBN. Please try again.\n";
        }

        cout << "Would you like to return a book? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the ISBN of the book to return: ";
            getline(cin, inputISBN);

            for (int i = 0; i < NUM_BOOKS; i++) {
                if (books[i].getISBN() == inputISBN) {
                    books[i].returnBook();
                    cout << "Returned Successfully\n";
                    break;
                }
            }
        }
    }

    return 0;
}
*/
//Verson2:
int main() {
    const int NUM_BOOKS = 5;
    Book books[NUM_BOOKS];

    // Initialize the library:arry with 5 books
    books[0].setBookDetails("The Duke and I", "Julia Quinn", "1", true);
    books[1].setBookDetails("The Viscount Who Loved Me", "Julia Quinn", "2", true);
    books[2].setBookDetails("An Offer From a Gentleman", "Julia Quinn", "3", true);
    books[3].setBookDetails("Romancing Mister Bridgerton", "Julia Quinn", "4", true);
    books[4].setBookDetails("To Sir Phillip, With Love", "Julia Quinn", "5", true);

    cout << "Romance Books Available:\n";
    cout << "ISBN 1: The Duke and I by Julia Quinn, \n";
    cout << "ISBN 2: The Viscount Who Loved Meby Julia Quinn, \n";
    cout << "ISBN 3: An Offer From a Gentleman bby Julia Quinn, \n";
    cout << "ISBN 4: Romancing Mister Bridgerton by Julia Quinn, \n";
    cout << "ISBN 5: To Sir Phillip, With Love by Julia Quinn, \n";
    cout << "\n";

    string inputISBN;
    int option;

    while (true) {
        // Display menu to the user
        cout << "Library Menu\n"
            << "1. Borrow Book\n"
            << "2. Return Book\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> option;
        cin.ignore(); // Ignore newline left in the input buffer

        if (option == 0) {
            cout << "Exiting the program\n";
            break;
        }

        switch (option) {
        case 1: { // Borrow Book
            cout << "Enter the ISBN of the book to borrow: ";
            getline(cin, inputISBN);

            bool found = false;
            for (int i = 0; i < NUM_BOOKS; i++) {
                if (books[i].getISBN() == inputISBN) {
                    found = true;
                    if (books[i].isAvailable()) {
                        books[i].borrowBook();
                        cout << "Borrowed successfully\n";
                    }
                    else {
                        cout << "Book is unavailable\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Invalid ISBN. Please try again.\n";
            }
            break;
        }

        case 2: { // Return Book
            cout << "Enter the ISBN of the book to return: ";
            getline(cin, inputISBN);

            bool found = false;
            for (int i = 0; i < NUM_BOOKS; i++) {
                if (books[i].getISBN() == inputISBN) {
                    found = true;
                    books[i].returnBook();
                    cout << "Returned successfully\n";
                    break;
                }
            }
            if (!found) {
                cout << "Invalid ISBN. Please try again.\n";
            }
            break;
        }

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}
    
