#pragma once
#include<string>
#include <iostream>

bool checkPassword(std::string p1, std::string p2) {
	if (p1 == p2) { return true; }
	else { return false; }
}


void login() {

	char choice;

	std::cout << "\nA.Director\nB.Manager\nC.Operator\nD.Crew " << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case('A'): case('a'):
	{
		std::string pass = "Director123";
		std::string password;
		while (true) {
			std::cout << "Please Enter Password: ";
			std::cin >> password;
			bool check = checkPassword(pass, password);
			if (check) {
				std::cout << "Success!";
				break;
			}
			else
				std::cout << "Try again.";
		}
		break;
	}


	case('B'): case('b'):
	{
		std::string pass = "Manager123";
		std::string password;
		while (true) {
			std::cout << "Please Enter Password: ";
			std::cin >> password;
			bool check = checkPassword(pass, password);
			if (check) {
				std::cout << "Success!";
				break;
			}
			else
				std::cout << "Try again.";
		}
		break;
	}

	case('C'): case('c'):
	{
		std::string pass = "Operator123";
		std::string password;
		while (true) {
			std::cout << "Please Enter Password: ";
			std::cin >> password;
			bool check = checkPassword(pass, password);
			if (check) {
				std::cout << "Success!";
				break;
			}
			else
				std::cout << "Try again.";
		}
		break;
	}

	case('D'): case('d'):
	{
		std::string pass = "Crew123";
		std::string password;
		while (true) {
			std::cout << "Please Enter Password: ";
			std::cin >> password;
			bool check = checkPassword(pass, password);
			if (check) {
				std::cout << "Success!";
				break;
			}
			else
				std::cout << "Try again.";
		}
		break;
	}

	}

}
