#include <iostream>
#include "global.h"
using namespace std;

Student students[MAX_STUDENTS];
Student admin;
int numStudents = 0;
//  1 = admin, 2 = student;
Student* loggedInUser = nullptr;

Book books[MAX_BOOKS];
int numBooks = 0;