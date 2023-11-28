#include "state.h"
#include "auth.h"
#include "book.h"
using namespace std;

void processInput(int input){
    switch(input){
        case 0:
            logOut();
            break;
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
        case 7:
            searchBook();
            break;
        case 8:
            issueBook();
            break;
        case 9:
            showIssuedBook();
            break;
        case 10:
            returnBook();
            break;
        default:
            cout << "please select a valid option" << endl;
            initialMessages();
            break;
    }
};

void initialMessages(){
    cout << endl;
    int userInput;

    if(loggedInUser != nullptr){
       if(loggedInUser->type == 1){
        cout << "------------------------"<< endl << endl;
        cout << "3. Add book"<< endl;
        cout << "4. Delete book"<< endl;
        cout << "5. View students"<< endl;
        cout << "6. View All Books"<< endl;
       }else if(loggedInUser->type == 2){
        cout << "------------------------"<< endl << endl;
        cout << "6. View All Books"<< endl;
        cout << "7. search Books"<< endl;
        cout << "8. Issue book"<< endl;
        cout << "9. Show issued books"<< endl;
        cout << "10. Return book"<< endl;
       }
       cout << "To logout type 0" << endl << endl;
    }else{
        cout << "------------------------"<< endl << endl;
        cout << "1. Login" << endl;
        cout << "2. Registration"<< endl;
    }
    cout << "Type the order number to select an option" << endl;
    cin >> userInput;

   validate(userInput);
}

void validate(int input){
    if(!loggedInUser && input > 2){
        cout << "please login!" << endl;
        initialMessages();
    }else if(loggedInUser != nullptr && input == 0){
        processInput(input);
    }else if(loggedInUser != nullptr && loggedInUser->type == 1 && (input < 3 || input > 6)){
        cout << "Invalid option!" << endl;
        initialMessages();
    }else if(loggedInUser != nullptr && loggedInUser->type == 2 && (input < 6 || input > 10)){
        cout << "Invalid option!" << endl;
        initialMessages();
    }else{
        processInput(input);
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
    cout << "Welcome to Library Management System" << endl;
    // admin by default
    admin.name = "admin";
    admin.setPassword("1234");

    //student by default
    students[numStudents].name = "asifur";
    students[numStudents].id = 777;
    students[numStudents].setPassword("1234");
    numStudents++;

    initialMessages();

    return 0;
}
