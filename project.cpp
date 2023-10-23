
#include <iostream>
#include <string>
#include "global.h"
#include "auth.h"
#include "book.h"
using namespace std;

void processInput(int input){
    switch(input){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            addbook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            viewStudents();
            break;
        case 6:
            viewBooks();
            break;
        default:
            cout << "no option selected";
            break;
    }
};

void initialMessages(){
    cout << "\n";
    int userInput;
    
    if(loggedInUser){
        cout << "------------------------"<< endl << endl;
        cout << "3. Add book"<< endl;
        cout << "4. Delete book"<< endl;
        cout << "5. View students"<< endl;
        cout << "6. View All Books"<< endl;
    }else{
        cout << "1. Login" << endl;
        cout << "2. Registration"<< endl;
    }
    cout << "Please type the order number to select an option" << endl;
    cin >> userInput;
    
    if(!loggedInUser && userInput > 2){
        cout << "please login!" << endl;
        initialMessages();
    }else{
        processInput(userInput);
    }
}

void viewStudents(){
    if(numStudents == 0){
        cout << "no student found" << endl;
    }else{
        for(int i = 0; i< numStudents; i++){
            cout << "name is:"<< students[i].name << endl;
            cout << "id is:"<< students[i].id << endl;
        }
    }
    initialMessages();
}

int main() {
    // admin by default
    admin.name = "admin";
    admin.setPassword("1234");
    initialMessages();

    return 0;
}