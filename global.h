#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 20;
const int MAX_BOOKS = 30;
const int MAX_BOOKS_ISSUED = 3;

class Book{
    public:
        string name;
        string author;
        int id;
        int quantity;
};

class Student {
    private:
        string password;
    public:
        string name;
        int id;
        int type = 2;
        int numBooksIssued = 0;
        Book books[MAX_BOOKS_ISSUED];

        void setPassword(string pass) {
            password = pass;
        }

        string getPassword(){
            return password;
        }
};


void initialMessages();
void processInput(int input);
void registration();
void viewStudents();
void login();
void addbook();
void viewBooks();
void deleteBook();
void searchBook();
