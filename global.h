#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 20;

class Student {
private:
    string password;
public:
    string name;
    int id;

    void setPassword(string pass) {
        password = pass;
    }

    string getPassword(){
        return password;
    }
};

Student students[MAX_STUDENTS];
Student admin;
int numStudents = 0;
// 0 = null; 1 = admin, 2 = student;
int loggedInUser = 0;

void initialMessages();
void processInput(int input);
void registration();
void viewStudents();
void login();
void addbook();
void viewBooks();
void deleteBook();
void searchBook();
