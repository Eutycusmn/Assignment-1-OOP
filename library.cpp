#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class
class Book {
public:
	string title;  // Title of the book
	string author; // Author of the book
	bool isBorrowed;    // Status of the book, whether it is borrowed or not

	// Constructor for the Book class
	Book(string title, string author) : title(title), author(author), isBorrowed(false) {}

	// Method to borrow a book
	void borrow() {
		if (!isBorrowed) {
			isBorrowed = true; // If the book is not borrowed, set the status to borrowed
		}
		else {
			cout << "This book is already borrowed." << endl; // If the book is already borrowed, print a message
		}
	}

	// Method to return a book
	void returned() {
		isBorrowed = false; // Set the status of the book to not borrowed
	}
};

// Library class
class Library {
private:
	vector<Book> library_books; // Vector to store the library_books in the library

public:
	// Method to add a book to the library
	void addNewBook(Book book) {
		library_books.push_back(book); // Add the book to the vector
	}

	// Method to remove a book from the library
	void removeBook(string title) {
		for (int i = 0; i < library_books.size(); i++) {
			if (library_books[i].title == title) {
				library_books.erase(library_books.begin() + i); // If the book is found, remove it from the vector
				return;
			}
		}
		cout << "Book not found." << endl; // If the book is not found, print a message
	}

	// Method to search for a book in the library
	Book* searchBook(string title) {
		for (int i = 0; i < library_books.size(); i++) {
			if (library_books[i].title == title) {
				return &library_books[i]; // If the book is found, return a pointer to the book
			}
		}
		cout << "Book not found." << endl; // If the book is not found, print a message
		return nullptr; // Return null if the book is not found
	}
};

// User class
class User {
public:
	string name;   // Name of the user
	Library* library;   // Pointer to the library that the user is using

	// Constructor for the User class
	User(string name, Library* library) : name(name), library(library) {}

	// Method for the user to borrow a book
	void borrowBook(string title) {
		Book* book = library->searchBook(title); // Search for the book in the library
		if (book != nullptr) {
			book->borrow(); // If the book is found, borrow the book
		}
	}

	// Method for the user to return a book
	void returnBook(string title) {
		Book* book = library->searchBook(title); // Search for the book in the library
		if (book != nullptr && book->isBorrowed) {
			book->returned(); // If the book is found and it is borrowed, return the book
		}
	}
};

// Main function to test the code
int main() {
	Library library; // Create a library
	cout << "Created new library" << endl;

	library.addNewBook(Book("Book1", "Author1")); // Add library_books to the library
	library.addNewBook(Book("Book2", "Author2"));
	cout << "Added 2 library_books to the library" << endl;


	User user("User1", &library); // Create a user
	cout << "Created a new user User1" << endl;

	user.borrowBook("Book1"); // User borrows a book
	cout << "User1 has borrowed the book Book1" << endl;

	user.returnBook("Book1"); // User returns a book
	cout << "User1 has returned the book Book1" << endl;

	return 0; // End of the program
}
