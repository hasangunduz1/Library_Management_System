#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "functions.h"
#include "account.cpp"
#include "library.cpp"

using namespace std;

int main()
{
cout << "1-) Register";
cout << "\n2-) Login";
cout << "\n3-) Reset your password";
cout <<"\n\n Welcome to the login system. Please select what you want to do: ";
int select;
cin >> select;
do {
switch(select)
{
case 1:
Registration();
cout <<"\n\n Welcome to the login system. Please select what you want to do: ";
cin >> select;
break;

case 2:
Login();
break;

default:
	cout << "Your choice doesn't match any operation. Please try again." << endl;
	break;
} 
  } while (enter_Program != 1);
  
  

  
return 0;
}



