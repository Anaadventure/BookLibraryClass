#include <iostream>
#include <string>
#include <algorithm>
#include "BookClass.h"

using namespace std;

// Sort function
void sortBooks(Book books[], int size) {
    sort(books, books + size, [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
        });
}

void displayBooks(const Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
        cout << "=======================\n";
    }
}

int main() {
    // Test Case 1: Correct Initialization
    Book correctBooks[3];
    correctBooks[0].setBookDetails("The Duke and I", "Julia Quinn", "1", true);
    correctBooks[1].setBookDetails("The Viscount Who Loved Me", "Julia Quinn", "2", true);
    correctBooks[2].setBookDetails("An Offer From a Gentleman", "Julia Quinn", "3", true);

    cout << "Correct Books Information:\n";
    displayBooks(correctBooks, 3);

    // Test Case 2: Incorrect Initialization
    Book incorrectBooks[3];
    incorrectBooks[0].setBookDetails("", "Julia Quinn", "invalidISBN", true); // Missing title and invalid ISBN
    incorrectBooks[1].setBookDetails("The Viscount Who Loved Me", "", "2", true); // Missing author
    incorrectBooks[2].setBookDetails("Romancing Mister Bridgerton", "Julia Quinn", "4", false); // Already borrowed

    cout << "\nIncorrect Books Information:\n";
    displayBooks(incorrectBooks, 3);

    // Test Case 3: Arrays in Different Orders
    Book ascendingBooks[3] = { correctBooks[0], correctBooks[1], correctBooks[2] };
    Book descendingBooks[3] = { correctBooks[2], correctBooks[1], correctBooks[0] };
    Book mixedBooks[3] = { correctBooks[1], correctBooks[2], correctBooks[0] };

    cout << "\nBooks in Ascending Order (Before Sort):\n";
    displayBooks(ascendingBooks, 3);

    cout << "\nBooks in Descending Order (Before Sort):\n";
    displayBooks(descendingBooks, 3);

    cout << "\nBooks in Mixed Order (Before Sort):\n";
    displayBooks(mixedBooks, 3);

    // Sorting the arrays
    sortBooks(ascendingBooks, 3);
    sortBooks(descendingBooks, 3);
    sortBooks(mixedBooks, 3);

    cout << "\nBooks in Ascending Order (After Sort):\n";
    displayBooks(ascendingBooks, 3);

    cout << "\nBooks in Descending Order (After Sort):\n";
    displayBooks(descendingBooks, 3);

    cout << "\nBooks in Mixed Order (After Sort):\n";
    displayBooks(mixedBooks, 3);

    return 0;
}
