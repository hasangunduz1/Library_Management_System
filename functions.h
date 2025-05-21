#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;
const int NAME_MAX_LENGTH = 50;
const int NUMBER_MAX_LENGTH = 5;
const int PASSWORD_MAX_LENGTH = 25;

class Account
{
public:
char user_Id[NAME_MAX_LENGTH];
char user_Password[NUMBER_MAX_LENGTH];
int id_Length;
int password_Length;




};

class Book
{
char book_Name[NAME_MAX_LENGTH];
char book_No[NUMBER_MAX_LENGTH];
char book_Author[NAME_MAX_LENGTH];

public:

vector <string> bookVector;
	

void add_Book()
{
cout << "\n Adding book\n";
cout << "\n Enter book no: ";
cin >> book_No;
cout << "\n Enter name of book: ";
cin.getline(book_Name, NAME_MAX_LENGTH);
cout << "\n Enter author's name: ";
cin.getline(book_Author, NAME_MAX_LENGTH);
cout << "\n Book succesfully added. " << endl;
}

void show_Book()
{
cout << "\n Book no: " << book_No;
cout << "\n Book name: " << puts(book_Name);
cout << "\n Book author: " << puts(book_Author);
}

void change_Book()
{
cout << "\n Book no: " << book_No;
cout << "\n Book name: ";
cin.getline(book_Name, NAME_MAX_LENGTH);
cout << "\n Enter author's name: ";
cin.getline(book_Author, NAME_MAX_LENGTH);
}

char* get_Book_Number()
{
	return book_No;
}


void book_Record()
{
	
}

};

class Student
{
char student_Number[5];
char student_Name[50];
char student_Book_Number[5];


public:
	
vector <string> studentVector;	
int token;

void add_Student()
{

cout << "\n Adding student.\n";
cout << "Enter student number: ";
cin >> student_Number;
cout << "Enter name of student: ";
cin.getline(student_Name, NAME_MAX_LENGTH);
token = 0;

cout << "Student has been succesfully added." << endl;
}

void show_Student()
{
cout << "Student number: " << student_Number;
cout << "Student name: " << puts(student_Name);
cout << "\n Number of books issued: " << token;
}

void change_Student()
{
cout << "\n Student number: " << student_Number;
cout << "\n Enter student name: ";
cin.getline(student_Name, NAME_MAX_LENGTH);
}

char* get_Student_Number()
{
return student_Number;
}

char* get_Student_Book_Number()
{
return student_Book_Number;
}

int get_Token()
{
return token;
}

int add_Token()
{
token = token + 1;
return token;
}

int remove_Token()
{
token = token - 1;
return token;
}

int reset_Token()
{
token = 0;
return token;
}

void student_Record()
{
	
}

};


void Registration();
void Login();
void reset_Password(int account_Number);
Account* retrieve_account_details(Account* accounts, int num_of_accounts);


#endif


