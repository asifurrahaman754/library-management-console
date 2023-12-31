#include <limits>

void login(){
    cout << endl;
    int userRole;
    string name;
    string pass;

    cout << "1. Login as Admin" << endl;
    cout << "2. Login as Student" << endl;
    cin >> userRole;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "type your name: ";
    getline(cin, name);
    cout << "type your password: ";
    getline(cin, pass);

    if(userRole == 1){
        if(admin.name == name && admin.getPassword() == pass){
            cout << "Welcome "<< admin.name << "."<< endl;
            loggedInUser = new Student;
            loggedInUser->name = name;
            loggedInUser->setPassword(pass);
            loggedInUser->type = 1;
        }else{
            cout << "Wrong credentials!"<<endl;
        }

    }else if(userRole == 2){
        int userFound = 0;
        for(int i = 0; i < numStudents; i++){
            if(students[i].name == name && students[i].getPassword() == pass){
                cout << "Welcome "<< name;
                loggedInUser = new Student;
                loggedInUser->name = name;
                loggedInUser->setPassword(pass);
                loggedInUser->id = students[i].id;
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

void logOut (){
    cout << endl;
    cout << "Loged out!";
    loggedInUser = 0;
    initialMessages();
}

void registration() {
    cout << endl;
    string pass;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Type your name: ";
    getline(cin, students[numStudents].name);

    cout << "Type your Id: ";
    cin >> students[numStudents].id;

    cout << "Type your password: ";
    cin >> pass;

    students[numStudents].setPassword(pass);

    numStudents++;
    cout << "Student added :)" << endl;
    initialMessages();
}
