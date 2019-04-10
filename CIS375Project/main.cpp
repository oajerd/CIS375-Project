#include<iostream>
#include "graph.h"
#include "city.h"
#include<string>

using namespace std;
using namespace GraphNameSpace;

int main() {

	char choice;

	cout << "Choose the user below: \nA.Director\nB.Manager\nC.Operator\nD.Crew " << endl;
	cin >> choice;

	switch (choice) 
	{
	case('A'):
	{
		string pass;
		bool enterPass = true;
		while (enterPass) {
			cout << "Please Enter Password: ";
			cin >> pass;
			if (pass == "Director123")
			{
				cout << "Success!";
				enterPass = false;
			}
			else
				cout << "Try again.";
		}
		break;
	}
	case('a'):
	{
		string pass;
		bool enterPass = true;
		while (enterPass) {
			cout << "Please Enter Password: ";
			cin >> pass;
			if (pass == "Director123")
			{
				cout << "Success!";
				enterPass = false;
			}
			else
				cout << "Try again.";
		}
	}
}




  system("pause");
  
  return 0;
}