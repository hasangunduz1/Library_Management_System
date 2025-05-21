#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "functions.h"
using namespace std;

fstream loginFile;
fstream loginFile2;

int num_of_accounts;

void Registration()
{
	Account new_User;
int account_Number = 0;

fstream loginFile;

loginFile.open("loginfile.txt", ios::app);

cout << "To exit the program, input 0.";
cout << "Enter your new username (6-50 characters): ";
cin >> new_User.user_Id;
new_User.id_Length = strlen(new_User.user_Id);
if(new_User.id_Length < 6 || new_User.id_Length > 50)
{
cout << "Your username is invalid. Please try to enter a new username: ";
cin >> new_User.user_Id;
new_User.id_Length = strlen(new_User.user_Id);

}

cout << "Please enter your new password(6-25 characters): ";
cin >> new_User.user_Password;
new_User.password_Length = strlen(new_User.user_Password);
if(new_User.password_Length < 6 || new_User.password_Length > 25)
{

cout << "Your password is invalid. Please try to enter a new password: ";
cin >> new_User.user_Password;
new_User.password_Length = strlen(new_User.user_Password);

}

loginFile << new_User.user_Id << ' ' << new_User.user_Password << endl;
account_Number += 1;
loginFile.close();
int enter_Program;
enter_Program = 0;
}

void Login()
{
char my_Id[50];
char my_Password[25];

cout << "To login, please enter your username: ";
cin >> my_Id;
cout << "Enter your password: ";
cin >> my_Password;

ifstream loginInput("loginFile.txt");

while(loginInput >>  new_User.user_Id >> new_User.user_Password)
{
if ( strcmp(new_User.user_Id,my_Id) == 0 && strcmp(new_User.user_Password,my_Password) == 0)
{
count = 1;

}
loginInput.close();

if(count == 1)
{
cout << "Your login is succesful. Logging to the system.." << endl;
enter_Program = 1;
}
else
{
cout << "Your login could not be succesfully done. Please check your username and password and try again." << endl;
Login();
enter_Program = 0;
}
}
}

void reset_Password(int account_Number)
{
	int keep_2 = 0;
	char new_Password[PASSWORD_MAX_LENGTH];
	char new_Password_confirm[PASSWORD_MAX_LENGTH];
	
	cout << "Enter your new password: ";
	
	do{
		
	cin >> new_Password;
	
	cout << "To confirm, enter your new password again: ";
	cin >> new_Password_confirm;
	
	if (strcmp(new_Password, new_Password_confirm) != 0)
	{
		cout << "Your updating password attempt is invalid. Passwords don't match each other. Please try again." << endl;
		keep_2 = 0;
	}
	
	else if (strcmp(new_Password, new_User.user_Password) == 0)
	{
		cout << "Your updating password attempt is invalid. This password is already in use. Please try again." << endl;
		keep_2 = 0;
	}
	
	else 
	{
		keep_2 = 1;
	}
	
  } while (keep_2 != 1);
	
	loginFile.open("loginFile.txt", ios::in);
	loginFile2.open("temploginFile.txt", ios::app);
	int row = 0;
	string preserve;
	string updated_account = puts(new_User.user_Id) + " " + puts(new_Password);
	while(loginFile >> ws >> new_User.user_Id >> new_User.user_Password)
	{
		if (row == account_Number)
		{
			loginFile2 << updated_account << endl;
			row += 1;
		}
		
		else
		{
			loginFile2 << preserve << endl;
			row += 1;
		}
	}
	
	loginFile.close();
	loginFile2.close();
	
	remove("loginFile.txt");
	rename("temploginFile.txt", "loginFile.txt");
	cout << "Your password has been changed. You can now use your new password to login." << endl;	
}
 
 Account* retrieve_account_details(Account* accounts, int num_of_accounts)
 {
 	int account_Number = 0;
 	for (int i = 0; i < num_of_accounts; i++)
 	{
 		accounts[i].user_Id[NAME_MAX_LENGTH];
 		accounts[i].user_Password[PASSWORD_MAX_LENGTH];
	}
 	
 	fstream loginFile;
 	loginFile.open("loginFile.txt", ios::in);
 	string detail;
 	string account_Detail = "id";
 	
 	while(loginFile >> ws, getline(loginFile, detail, " "))
 	{
 		if (account_Detail == "id")
 		{
 			strcpy(accounts[account_Number].user_Id, detail.c_str());
            accounts[account_Number].id_Length = strlen(accounts[account_Number].user_Id);
            account_Detail = "pass";    
		 }
		 
		 else if (account_Detail == "pass") {
            strcpy(accounts[account_Number].user_Password, detail.c_str());
            accounts[account_Number].password_Length = strlen(accounts[account_Number].user_Password);
            account_Detail = "id";
            account_Number += 1 ;
	 }
 }
 
 loginFile.close();
 return accounts;
}

