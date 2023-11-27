#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

void viewBooks() {
    cout << endl;
    if (numBooks == 0) {
        cout << "No books found" << endl;
    } else {
        cout << "Here is the books list:" << endl << endl;
        cout << setw(20) << "Name" << setw(20) << "Author" << setw(10) << "ID" << setw(10) << "Quantity" << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << setw(20) << books[i].name
                 << setw(20) << books[i].author
                 << setw(10) << books[i].id
                 << setw(10) << books[i].quantity
                 << endl;
        }
    }
    initialMessages();
}

void addbook(){
    cout << endl;
    cout << "type book name: ";
    cin.ignore();
    getline(cin, books[numBooks].name);
    cout << "type book author: ";
    getline(cin, books[numBooks].author);
    cout << "type book id: ";
    cin >> books[numBooks].id;
    cout << "type book quantity: ";
    cin >> books[numBooks].quantity;

    numBooks++;
    cout << "book added :)"<<endl;
    initialMessages();
}

void deleteBook(){
    cout << endl;
    cout << "type book id: ";
    int bookId;
    cin >> bookId;

    int bookDeleted = 0;
    for(int i = 0; i < numBooks; i++){
        if(books[i].id == bookId){
            for(int j = i; j < numBooks; j++){
                books[j] = books[j+1];
            }
            numBooks--;
            bookDeleted = 1;
            break;
        }
    }

    if(!bookDeleted){
        cout << "no book found with id: "<< bookId << endl;
    }else{
        cout << "book deleted succesfully :)"<<endl;
    }

    initialMessages();
}

void issueBook(){
    cout << endl;
    if (numBooks == 0) {
        cout << "No books available for issuing." << endl;
        initialMessages();
        return;
    }

    cout << "Enter book ID to issue: ";
    int bookId;
    cin >> bookId;

    int bookIndex = -1;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == bookId) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        cout << "Book with ID " << bookId << " not found." << endl;
    } else {
        if (books[bookIndex].quantity > 0) {
            books[bookIndex].quantity--;

            // find the student and add the book to their list
            for (int i = 0; i < numStudents; i++) {
                if (students[i].id == loggedInUser->id) {
                    students[i].books[students[i].numBooksIssued] = books[bookIndex];
                    students[i].numBooksIssued++;
                    break;
                }
            }

            cout << "Book '" << books[bookIndex].name << "' issued successfully. Remaining quantity: " << books[bookIndex].quantity << endl;
        } else {
            cout << "Sorry, no more copies of this book available for issuing." << endl;
        }
    }

    initialMessages();
}

void showIssuedBook(){
    cout << endl;

    cout << "Here are the books issued to - " << loggedInUser->name << ":" << endl << endl;
    cout << setw(20) << "Name" << setw(20) << "Author" << setw(10) << "ID" << setw(10) << "Quantity" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    int studentIndex = -1;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == loggedInUser->id) {
            studentIndex = i;
            break;
        }
    }

    if(studentIndex != -1){
        for (int i = 0; i < students[studentIndex].numBooksIssued; i++) {
            cout << setw(20) << students[studentIndex].books[i].name
                << setw(20) << students[studentIndex].books[i].author
                << setw(10) << students[studentIndex].books[i].id
                << setw(10) << students[studentIndex].books[i].quantity
                << endl;
        }
    }

    initialMessages();
}

void searchBook() {
    cout << endl;
    if (numBooks == 0) {
        cout << "No books Added" << endl;
        initialMessages();
        return;
    }

    cout << "Enter book name to search: ";
    string searchQuery;
    cin.ignore();
    getline(cin, searchQuery);

    bool found = false;

    cout << setw(20) << "Name" << setw(20) << "Author" << setw(10) << "ID" << setw(10) << "Quantity" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (int i = 0; i < numBooks; i++) {
        // Case-insensitive search by converting both searchQuery and book name to lowercase
        string lowerSearchQuery = searchQuery;
        transform(lowerSearchQuery.begin(), lowerSearchQuery.end(), lowerSearchQuery.begin(), ::tolower);

        string lowerBookName = books[i].name;
        transform(lowerBookName.begin(), lowerBookName.end(), lowerBookName.begin(), ::tolower);

        if (lowerBookName.find(lowerSearchQuery) != string::npos) {
            cout << setw(20) << books[i].name
                 << setw(20) << books[i].author
                 << setw(10) << books[i].id
                 << setw(10) << books[i].quantity
                 << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No matching books found." << endl;
    }

    initialMessages();
}
