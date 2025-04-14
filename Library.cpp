#include <iostream>
#include <string>
using namespace std;

// Define the Book class
class Book {
public:
    int id;
    string title;
    string author;

    // Function to display book details
    void displayBook() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }

    // Function to update book details
    void updateBook(string newTitle, string newAuthor) {
        title = newTitle;
        author = newAuthor;
    }
};

// Global array to store books and count of books
Book books[100];
int bookCount = 0;

// Function to add a new book
void addBook() {
    if (bookCount >= 100) {
        cout << "Library is full! Cannot add more books." << endl;
        return;
    }

    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.id;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Book Author: ";
    getline(cin, newBook.author);

    books[bookCount] = newBook;
    bookCount++;
    cout << "Book added successfully!" << endl;
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        cout << "No books available in the library." << endl;
        return;
    }

    cout << "\nList of Books:\n";
    for (int i = 0; i < bookCount; i++) {
        books[i].displayBook();
    }
}

// Function to search for a book by ID
void searchBook() {
    int searchID;
    cout << "Enter Book ID to search: ";
    cin >> searchID;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == searchID) {
            cout << "Book found: \n";
            books[i].displayBook();
            return;
        }
    }

    cout << "Book with ID " << searchID << " not found." << endl;
}

// Function to update book details
void updateBook() {
    int updateID;
    cout << "Enter Book ID to update: ";
    cin >> updateID;
    cin.ignore(); // Clear the input buffer

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == updateID) {
            string newTitle, newAuthor;
            cout << "Enter new Title: ";
            getline(cin, newTitle);
            cout << "Enter new Author: ";
            getline(cin, newAuthor);

            books[i].updateBook(newTitle, newAuthor);
            cout << "Book updated successfully!" << endl;
            return;
        }
    }

    cout << "Book with ID " << updateID << " not found." << endl;
}

// Function to delete a book
void deleteBook() {
    int deleteID;
    cout << "Enter Book ID to delete: ";
    cin >> deleteID;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == deleteID) {
            // Shift all books after the deleted book
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            cout << "Book deleted successfully!" << endl;
            return;
        }
    }

    cout << "Book with ID " << deleteID << " not found." << endl;
}

// Main function
int main() {
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
