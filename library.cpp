#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "account.cpp"
#include "functions.h"


using namespace std;

fstream openFile;
fstream openFile2;

Book library_Book;
Student library_Student;

void write_Book_Record()
{
int keep = 1;
openFile.open("book.dat", ios::out|ios::app);
do
{
library_Book.add_Book();
openFile.write((char*)&library_Book, sizeof(Book));
cout << "\n Do you want to keep adding records (0/1)?: ";
cin >> keep;
} while (keep == 1);
openFile.close();
}

void write_Student_Record()
{
int keep = 1;
openFile.open("student.dat", ios::out | ios::app);
do
{
library_Student.add_Student();
openFile.write((char*)&library_Student, sizeof(Student));
cout << "\n Do you want to keep adding records (0/1)?: ";
cin >> keep;
} while (keep == 1);
openFile.close();
}

void show_Specific_Book(char l[])
{
	int key = 0;
	
	cout << "\n Book information \n";
	openFile.open("book.dat", ios::in);
	
	while(openFile.read((char*)&library_Book, sizeof(Book)))
	{
		if (strcmp(library_Book.get_Book_Number(),l) == 0)
		{
			library_Book.show_Book();
			key = 1;
		}
	}
	
	openFile.close();
	if(key == 0)
	{
		cout << "\n Book not found.\n";
	}
	
	getch();
}

void show_Student_Book(char s[])
{
  int key = 0;
  
cout << "\n Book information \n";

openFile.open("book.dat", ios::in);

while(openFile.read((char*)&library_Book, sizeof(Book)))
{
if(strcmp(library_Student.get_Student_Book_Number(),s) == 0)
{
library_Book.show_Book();
key = 1;
}
}

openFile.close();
if(key == 0)
{
cout << "\n Book not found.\n";
}

getch();
}

void show_Student(char d[])
{
	int key = 0;
	
	cout << "\n Student information \n";
	
	openFile.open("student.dat", ios::in);
	while(openFile.read((char*)&library_Student, sizeof(Student)))
	{
		if(strcmp(library_Student.get_Student_Number(), d) == 0)
		{
			library_Student.show_Student();
			key = 1;
		}
		
		openFile.close();
		if(key == 0)
		{
			cout << "\n Student not found.\n";
		}
		
		getch();
	}
}

void show_All_Books()
{
	openFile.open("book.dat", ios::in);
	if(!openFile)
	return;
	
	cout << "\n\n\tBook List\n\n";
	cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";
	
	
while(openFile.read((char*)&library_Book, sizeof(Book)))
   {
   
	}
	
	openFile.close();
	getch();	
}

void show_All_Students()
{
	openFile.open("student.dat", ios::in);
	if(!openFile)
	return;
	
	
	cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
	
	
	
	while(openFile.read((char*)&library_Student, sizeof(Student)))
	{
		
	}
	
	openFile.close();
	getch();
}

void sort_All_Books_By_Name()
{
	openFile.open("book.dat", ios::in);
	while(openFile >> book_Name)
	{
		bookVector.push_back(book_Name);
	}
	openFile.close();
	
	sort(bookVector.begin(), bookVector.end(), book_Name);
	
	openFile.open("book.dat", ios::in);
	if(!openFile)
	return;
	
	cout << "\n\n\tBook List\n\n";
	cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";

	while(openFile.read((char*)&library_Book, sizeof(Book)))
   {
   	
	}
	
	openFile.close();
	getch();	
}

void sort_All_Books_By_Number()
{
	
	openFile.open("book.dat", ios::in);
	while(openFile >> book_No)
	{
		bookVector.pushback(book_No);
	}
	openFile.close();
	
	sort(bookVector.begin(), bookVector.end(), book_No);
	
	openFile.open("book.dat", ios::in);
	if(!openFile)
	return;
	
	cout << "\n\n\tBook List\n\n";
	cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";
	
	while(openFile.read((char*)&library_Book, sizeof(Book)))
	{
		
	}
	
	openFile.close();
	getch();
}

void sort_All_Students_By_Name()
{
	openFile.open("student.dat", ios::in);
	while(openFile >> student_Name)
	{
		studentVector.pushback(student_Name);
	}
	openFile.close();
	
	sort(studentVector.begin(), studentVector.end(), student_Name);
	openFile.open("student.dat", ios::in);
	if(!openFile)
	return;
	
	
	cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
	
	
	while(openFile.read((char*)&library_Student, sizeof(Student)))
	{
		
	}
	
	openFile.close();
	getch();
}

void sort_All_Students_By_Number()
{
	openFile.open("student.dat", ios::in);
	while(openFile >> student_Number)
	{
		studentVector.pushback(student_Name);
	}
	openFile.close();
	
	sort(studentVector.begin(), studentVector.end(), student_Number);
	openFile.open("student.dat", ios::in);
	if(!openFile)
	return;
	
	cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
	
	
	
	while(openFile.read((char*)&library_Student, sizeof(Student)))
	{
		
	}
	
	openFile.close();
	getch();
}
