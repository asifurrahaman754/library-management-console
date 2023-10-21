// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 20; 

class Student {
public:
    string name;
    int id;
};
 Student students[MAX_STUDENTS];
int numStudents = 0;

void initialMessages();
void processInput(int input);
void registration();
void viewStudents();

void processInput(int input){
    switch(input){
        case 1:
            cout << "1 is selected";
            break;
        case 2:
            registration();
            break;
        case 3:
            viewStudents();
            break;
        default:
            cout << "no option selected";
            break;
    }
};

void initialMessages(){
    int userInput;
    cout << "1. Login" << endl;
    cout << "2. Registration"<< endl;
    cout << "2. Add book"<< endl;
    cout << "3. View students"<< endl;
    cout << "Please type the order number to select an option" << endl;
    
    cin >> userInput;
    
    processInput(userInput);
}

void registration(){
    string name;
    int id;
    
    cout << "type your name: ";
    cin >> name;
    
        // Clear the newline character from the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    students[numStudents].name = name;
    cout << "type your Id: ";
    cin >> id;
    students[numStudents].id = id;
    numStudents++;
    cout << "student added :)"<<endl;
    initialMessages();
}

void viewStudents(){
    if(numStudents == 0){
        cout << "no student found";
    }else{
        for(int i = 0; i< numStudents; i++){
            cout << "name is:"<< students[i].name << endl;
            cout << "id is:"<< students[i].id << endl;
        }
    }
}



int main() {
    initialMessages();

    return 0;
}