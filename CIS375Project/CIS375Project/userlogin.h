#pragma once
#include<string>
#include <iostream>
#include <string>
using namespace std;


char choice;


 class userlogin {
 private:
	 char menuChoice;
	 bool validPassword;
	 string directorPass;
	 string managerPass;
	 string operatorPass;
	 string crewPass;
	 string inputPass;
 public:
	 userlogin() {
		  menuChoice;
		  validPassword = false;
		  directorPass = "1";
		  managerPass = "2";
		  operatorPass = "3";
		  crewPass = "4";
		  inputPass;
		  void initialMenu();
	 }
	 
	 char menuChoice;
	 bool checkPassword(string p1, string p2);
	 

};

bool checkPassword(std::string p1, std::string p2) {
	if (p1 == p2) { return true; }
	else { return false; }
}

void directorMenu() {

}


void initialMenu()
{
	

	do {
		inputPass.clear();
		cout << "\nA:Director\nB:Manager\nC:Operator\nD:Crew\n\nEnter choice:";
		cin >> menuChoice;
		cout << "Enter Password: ";
		cin >> inputPass;

		switch (menuChoice) {
		case 'a': case 'A':
			validPassword = checkPassword(directorPass, inputPass);
			if (validPassword == true) {
				//initiate director menu
				directorMenu();
			}
			else { cout << "Incorrect Password. Try Again\n"; }
			break;

		case 'b': case 'B':
			validPassword = checkPassword(managerPass, inputPass);
			if (validPassword == true) {
				//initiate manager menu
				//managerMenu();
			}
			else { cout << "Incorrect Password. Try Again\n"; }
			break;

		case 'c': case 'C':
			validPassword = checkPassword(operatorPass, inputPass);
			if (validPassword == true) {
				//initiate operator menu
				//operatorMenu();
			}
			else { cout << "Incorrect Password. Try Again\n"; }
			break;

		case 'd': case 'D':
			validPassword = checkPassword(crewPass, inputPass);
			if (validPassword == true) {
				//initiate crew menu
				//crewMenu();
			}
			else { cout << "Incorrect Password. Try Again\n"; }
			break;

		default:
			cout << "Invalid Menu Choice. Try Again\n";
			break;
		};
	} while (validPassword != true);
}