#ifndef _FILE_READ_UTILITY_H_
#define _FILE_READ_UTILITY_H_

#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "graph.h"
#include "station.h"
#include "maintenance.h"
#include "config.h"
#include "route.h"

using namespace GraphNameSpace;

vector<Station> nodes;

vector<Station> hubs;

vector<Locomotive> locomotives;

vector<Edge> graphEdges;

vector<DailyRoute> dailyRoutes;

vector<Route> repeatableFRoutes;

vector<Route> repeatablePRoutes;

void inputError(string message);

bool endOfString(string str);

bool invalidStructure(string str);

int findNode(string str);

int findHub(string str);

void readHeader(ifstream& inFS, string rowInfo, int& controlCount);

ifstream readFileName(string str);

int findGraphNode(string str, Graph<Station>& structure);

int findEdge(string str1, string str2);

int findLocomotive(string str);

void inputError(string message) {

	cout << "Error: " << message;

	cin.get();
	exit(EXIT_FAILURE);

	return;
}

bool endOfString(string str) {

	if (str == "") {

		return true;

	}

	return false;

}

bool invalidStructure(string str) {

	if (str == "C" || str == "T") {

		return true;

	}

	return false;

}

int findNode(string str) {

	for (int i = 0; i < nodes.size(); i++) {

		if (nodes.at(i).getName() == str) {

			return i;

		}

	}

	return -1;

}

int findHub(string str) {

	for (int i = 0; i < hubs.size(); i++) {

		if (hubs.at(i).getName() == str) {

			return i;

		}

	}

	return -1;

}

void readHeader(ifstream& inFS, string rowInfo, int& controlCount) {

	string formatError = "Invalid input format.";

	string input1; //First line of the text file

	string tempCount;

	string input2;

	string month;

	string day;

	string year;

	//For very first line of input
	getline(inFS, rowInfo);

	istringstream inSS(rowInfo); //Creates a string stream named inSS

	inSS >> input1; //Stores all values accordingly

	inSS >> input2;

	if (input1.at(0) != 'H') {
		inputError(formatError);
		return;

	}

	tempCount = input1.substr(1, input1.size() - 1);//Stores value after H 

	controlCount = stoi(tempCount);

	month = input2.substr(0, 2);//Stores month

	day = input2.substr(3, 2);//Stores day

	year = input2.substr(6, 4);//Stores year

}

ifstream readFileName(string str) {

	ifstream inFS;

	inFS.open(str);

	while (!inFS.is_open()) //Loop that continues until the file is opened
	{
		inFS.open(str);

		cout << "Sorry " << str << " could not be opened." << endl;
		cout << "Check the source files and press any key to try again.";
		cout << endl << endl;
		cin.get();
	}

	return inFS;

}

int findGraphNode(string str, Graph<Station>& structure) {

	int index = findNode(str);

	if (index == -1) {

		return index;

	}

	return structure.findVertex(nodes.at(index));

}

int findEdge(string str1, string str2) {

	for (int i = 0; i < graphEdges.size(); i++) {

		if ((graphEdges.at(i).getNode1().getName() == str1) && (graphEdges.at(i).getNode2().getName() == str2)) {

			return i;

		}

		if ((graphEdges.at(i).getNode1().getName() == str2) && (graphEdges.at(i).getNode2().getName() == str1)) {

			return i;

		}

	}

	return -1;

}

int findLocomotive(string str) {

	for (int i = 0; i < locomotives.size(); i++) {

		if (locomotives.at(i).getName() == str) {

			return i;

		}

	}

	return -1;

}

#endif
