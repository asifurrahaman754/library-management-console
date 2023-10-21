// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <limits>
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

void login(int userRole){
    string name;
    string pass;
    
    cout << "type your name: ";
    cin >> name;
    cout << "type your password: ";
    cin >> pass;
    if(userRole == 1){
        if(admin.name == name && admin.getPassword() == pass){
            cout << "Welcome admin!"<< endl;
            loggedInUser = 1;
        }else{
            cout << "Wrong credentials!"<<endl;
        }
        
    }else if(userRole == 2){
        int userFound = 0;
        for(int i = 0; i < numStudents; i++){
            if(students[i].name == name && students[i].getPassword() == pass){
                cout << "Welcome "<< name;
                loggedInUser = 2;
                userFound = 1;
                break;
            }
        }
        
        if(!userFound){
            cout << "No data Found!"<<endl;
        }
    }
    
    initialMessages();
}

void processInput(int input){
    switch(input){
        case 1:
            int userRole;
            cout << "1. Login as Admin" << endl;
            cout << "2. Login as Student" << endl;
            cin >> userRole;
            login(userRole);
            
            break;
        case 2:
            registration();
            break;
        case 4:
            viewStudents();
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
        cout << "3. Add book"<< endl;
        cout << "4. View students"<< endl;
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

void registration(){
    string pass;
    
    cout << "type your name: ";
    cin >> students[numStudents].name;
    cout << "type your Id: ";
    cin >> students[numStudents].id;
    cout << "type your password: ";
    cin >> pass;
    
    // Clear the newline character from the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    students[numStudents].setPassword(pass);
    
    numStudents++;
    cout << "student added :)"<<endl;
    initialMessages();
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