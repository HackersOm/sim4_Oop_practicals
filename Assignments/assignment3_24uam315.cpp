#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char *title;
    char *author;
    int pageCount;
    bool formate;
    float *chapterPages;
    int chapters;

public:
    // Default constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        formate = false;
        chapterPages = NULL;
        chapters = 0;
    }

    // Parameterized constructor
    Book(const char* bookTitle, const char* bookAuthor, int totalPages, bool isHardcover, int totalChapters) {
        title = new char[strlen(bookTitle) + 1];
        strcpy(title, bookTitle);
        author = new char[strlen(bookAuthor) + 1];
        strcpy(author, bookAuthor);
        pageCount = totalPages;
        formate = isHardcover;
        chapters = totalChapters;
        chapterPages = new float[chapters];
        for (int i = 0; i < chapters; i++) {
            chapterPages[i] = static_cast<float>(pageCount) / chapters;
        }
    }

    // Copy constructor
    Book(const Book& book) {
        title = new char[strlen(book.title) + 1];
        strcpy(title, book.title);
        author = new char[strlen(book.author) + 1];
        strcpy(author, book.author);
        pageCount = book.pageCount;
        formate = book.formate;
        chapters = book.chapters;
        chapterPages = new float[chapters];
        for (int i = 0; i < chapters; i++) {
            chapterPages[i] = book.chapterPages[i];
        }
    }

    // Function to copy book manually
    void copyBook(const Book& book) {
        delete[] title;
        delete[] author;
        delete[] chapterPages;

        title = new char[strlen(book.title) + 1];
        strcpy(title, book.title);
        author = new char[strlen(book.author) + 1];
        strcpy(author, book.author);
        pageCount = book.pageCount;
        formate = book.formate;
        chapters = book.chapters;
        chapterPages = new float[chapters];
        for (int i = 0; i < chapters; i++) {
            chapterPages[i] = book.chapterPages[i];
        }
    }

    // Modify pages in a chapter
    void modifypages(int chapterIndex, int newPageCount) {
        if (chapterIndex < 0 || chapterIndex >= chapters) {
            cout << "Error: Invalid chapter index." << endl;
            return;
        }
        chapterPages[chapterIndex] = newPageCount;
        cout << "Chapter " << chapterIndex + 1 << " updated successfully!" << endl;
    }

    // Display book details
    void display() {
        cout << "\nTitle: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pageCount << endl;
        cout << "Format: " << (formate ? "Hardcover" : "Paperback") << endl;
        cout << "Number of Chapters: " << chapters << endl;
        if (chapterPages != NULL) {
            cout << "Pages per chapter: ";
            for (int i = 0; i < chapters; i++) {
                cout << chapterPages[i] << " ";
            }
        } else {
            cout << "No pages in book.";
        }
        cout << endl;
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }
};

// Function to create a book dynamically
Book createBook() {
    char bookTitle[100], bookAuthor[100];
    int totalPages, totalChapters;
    bool isHardcover;
    
    cin.ignore();  // Ignore any newline characters from previous input
    cout << "Enter Book Title: ";
    cin.getline(bookTitle, 100);
    cout << "Enter Author: ";
    cin.getline(bookAuthor, 100);
    cout << "Enter Total Pages: ";
    cin >> totalPages;
    cout << "Enter Number of Chapters: ";
    cin >> totalChapters;
    cout << "Is it Hardcover? (1 for Yes, 0 for No): ";
    cin >> isHardcover;

    return Book(bookTitle, bookAuthor, totalPages, isHardcover, totalChapters);
}

int main() {
    Book book;
    Book copyBook;
    int choice, chapterIndex, newPageCount;

    while (true) {
        cout << "\n===== Book Menu =====" << endl;
        cout << "1. Create Book" << endl;
        cout << "2. Modify Chapter Pages" << endl;
        cout << "3. Display Book Details" << endl;
        cout << "4. Copy Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                book = createBook();
                cout << "Book Created Successfully!\n";
                break;

            case 2:
                if (book.display(), "") {  // Check if book exists
                    cout << "Enter Chapter Index (0-based): ";
                    cin >> chapterIndex;
                    cout << "Enter New Page Count: ";
                    cin >> newPageCount;
                    book.modifypages(chapterIndex, newPageCount);
                } else {
                    cout << "No book exists! Please create a book first.\n";
                }
                break;

            case 3:
                book.display();
                break;

            case 4:
                copyBook.copyBook(book);
                cout << "Book Copied Successfully!\n";
                cout << "Copied Book Details: ";
                copyBook.display();
                break;

            case 5:
                cout << "Exiting Program...\n";
                return 0;

            default:
                cout << "Invalid Choice! Please try again.\n";
        }
    }

    return 0;
}
