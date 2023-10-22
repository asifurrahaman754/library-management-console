#include <string>

using namespace std;

const int MAX_BOOKS = 30;

class Book{
    public:
        string name;
        string author;
        int id;
        int quantity;
};

Book books[MAX_BOOKS];
int numBooks = 0;


void viewBooks(){
    if(numBooks == 0){
        cout << "no book found" << endl;
    }else{
        for(int i = 0; i< numBooks; i++){
            cout << "name is:"<< books[i].name << endl;
            cout << "author is:"<< books[i].author << endl;
            cout << "id is:"<< books[i].id << endl;
            cout << "quantity is:"<< books[i].quantity << endl;
        }
    }
    initialMessages();
}

void addbook(){
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
