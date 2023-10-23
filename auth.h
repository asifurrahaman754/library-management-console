
void login(){
    int userRole;
    string name;
    string pass;

    cout << "1. Login as Admin" << endl;
    cout << "2. Login as Student" << endl;
    cin >> userRole;
    
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


void registration(){
    string pass;
    
    cout << "type your name: ";
    cin >> students[numStudents].name;
    cout << "type your Id: ";
    cin >> students[numStudents].id;
    cout << "type your password: ";
    cin >> pass;
    
    cin.ignore();
    students[numStudents].setPassword(pass);
    
    numStudents++;
    cout << "student added :)"<<endl;
    initialMessages();
}