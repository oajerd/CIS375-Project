#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include<iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "graph.h"
#include "station.h"
#include "maintenance.h"
#include "config.h"

using namespace GraphNameSpace;

void structureFileRead(string fileName, Graph<Station>& structure);

void maintenanceFileRead(string fileName, Graph<Station>& structure, Maintenance_Schedule& schedule);

void configFileRead(string fileName, Graph<Station>& structure, config& configuration);

void HUBinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void HUBinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void STATIONinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void EDGEinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void LOCOMOTIVEinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

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

vector<Station> nodes;

vector<Station> hubs;

vector<Locomotive> locomotives;

vector<Edge> graphEdges;

// Purpose: To read and store info into the graph
// Author: Austin Greear
// Last Modification Date: 4/13/19
void structureFileRead(string fileName, Graph<Station>& structure)
{

	ifstream inFS = readFileName(fileName);

	string formatError = "Invalid input format.";

	string typeError = "Invalid control type.";

	string  rowInfo; //Creates a string to be used in the istringstream 

	string tempCount;

	int controlCount = 0;

	readHeader(inFS, rowInfo, controlCount);

	int controlTempCount = controlCount;

	string controlLine;

	string controlType;

	int typeCount;

	int lineCount = 0;

	while (!inFS.eof()) //Loop that continues until the end of the file is reached
	{

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo); //Creates a string stream named inSS

		inSS >> controlLine;

		if (controlLine != "C") {

			if (controlLine == "T") {
				//cout << "T line" << endl;
				break;

			}

			inputError(formatError);
			return;

		}

		inSS >> controlType;

		inSS >> tempCount;

		typeCount = stoi(tempCount);

		lineCount++;

		lineCount += typeCount;

		if (controlCount <= 0) {
			inputError(formatError);
			return;

		}
		else if (controlType == "HUB") {

			HUBinput(typeCount, inFS, rowInfo, structure);

		}
		else if (controlType == "STATION") {

			STATIONinput(typeCount, inFS, rowInfo, structure);

		}
		else if (controlType == "EDGE") {

			EDGEinput(typeCount, inFS, rowInfo, structure);

		}
		else if (controlType == "LOCOMOTIVE") {

			LOCOMOTIVEinput(typeCount, inFS, rowInfo, structure);

		}
		else {

			inputError(typeError);
			return;

		}

		controlCount--;

	}

	string T;

	int tInput1;

	int tInput2;

	istringstream inSS2(rowInfo);

	inSS2 >> T;

	inSS2 >> tempCount;

	tInput1 = stoi(tempCount);

	inSS2 >> tempCount;

	tInput2 = stoi(tempCount);

	if (lineCount != tInput1) {
		inputError(formatError);
		return;
	}

	if (tInput1 - controlTempCount != tInput2) {
		inputError(formatError);
		return;
	}

}

// Purpose: Displays an error message and exits the program
// Author: Austin Greear
// Last Modification Date: 4/13/19
void inputError(string message) {

	cout << "Error: " << message;

	cin.get();
	exit(EXIT_FAILURE);

	return;
}

void HUBinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure) {

	string error1 = "Incorrect control structure count.";

	string hubInput1;

	while (typeCount != 0) {

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo);

		inSS >> hubInput1;

		if (invalidStructure(hubInput1)) {
			inputError(error1);
		}

		Station hubInput(hubInput1);

		structure.insertVertex(hubInput);

		//hubInput.setIndex(structure.findVertex(hubInput));

		hubs.push_back(hubInput1);

		nodes.push_back(hubInput1);

		typeCount--;

	}

}

void STATIONinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure) {

	string error1 = "Incorrect control structure count.";

	string input1;

	string input2;

	string input3;

	string input4;

	string input5;

	string input6;

	string input7;

	string input8;

	while (typeCount != 0) {

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo);

		inSS >> input1;

		if (invalidStructure(input1)) {
			inputError(error1);
		}

		inSS >> input2;

		inSS >> input3;

		inSS >> input4;

		inSS >> input5;

		inSS >> input6;

		inSS >> input7;

		inSS >> input8;

		Station stationInput(input1, input2.at(0), stoi(input3), stoi(input4), stoi(input5), stoi(input6), stoi(input7), stof(input8));

		//stationInput.setIndex(structure.findVertex(stationInput));

		structure.insertVertex(stationInput);

		nodes.push_back(stationInput);

		typeCount--;

	}

}

void EDGEinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure) {

	string error1 = "Incorrect control structure count.";

	string error2 = " not found. hello";

	string error3 = "Node1 of edge is equal to Node2";

	string input1;

	int node1Index;

	string input2;

	int node2Index;

	string input3;

	string input4;

	string input5;

	while (typeCount != 0) {

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo);

		inSS >> input1;

		if (invalidStructure(input1)) {
			inputError(error1);
		}

		node1Index = findNode(input1);

		if (node1Index == -1) {

			inputError(input1 + error2);

		}

		inSS >> input2;

		node2Index = findNode(input2);

		if (node2Index == -1) {

			inputError(input2 + error2);

		}

		if (node1Index == node2Index) {

			inputError(error3);

		}

		inSS >> input3;

		inSS >> input4;

		inSS >> input5;

		Edge edgeInput(nodes.at(node1Index), nodes.at(node2Index), input3, input4, input5, graphEdges.size());

		structure.insertEdge(nodes.at(node1Index), nodes.at(node2Index));

		graphEdges.push_back(edgeInput);

		typeCount--;

	}

}

void LOCOMOTIVEinput(int typeCount, ifstream & inFS, string rowInfo, Graph<Station> & structure) {

	string error1 = "Incorrect control structure count.";

	string error2 = " not found.";

	string input1;

	string input2;

	int hubIndex;

	string input3;

	while (typeCount != 0) {

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo);

		inSS >> input1;

		if (invalidStructure(input1)) {
			inputError(error1);
		}

		inSS >> input2;

		hubIndex = findHub(input2);

		if (hubIndex == -1) {

			inputError(input2 + error2);

		}

		inSS >> input3;

		Locomotive locomotiveInput(input1, hubs.at(hubIndex), input3);

		locomotives.push_back(locomotiveInput);

		typeCount--;

	}

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

void readHeader(ifstream & inFS, string rowInfo, int& controlCount) {

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

void maintenanceFileRead(string fileName, Graph<Station> & structure, Maintenance_Schedule & schedule)
{

	string error1 = "Incorrect control structure count.";

	string error2 = " not found.";

	string error3 = "Edge ";

	ifstream inFS = readFileName(fileName);

	string formatError = "Invalid input format.";

	string typeError = "Invalid control type.";

	string  rowInfo; //Creates a string to be used in the istringstream 

	string tempCount;

	int dayCount = 0;

	readHeader(inFS, rowInfo, dayCount);

	int controlTempCount = dayCount;

	string controlLine;

	string controlType;

	int dayNumCount = 0;

	int lineCount = 0;

	int controlCount = 0;

	while (!inFS.eof()) //Loop that continues until the end of the file is reached
	{

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo); //Creates a string stream named inSS

		inSS >> controlLine;

		if (controlLine != "C") {

			if (controlLine == "T") {
				break;

			}

			inputError(formatError);
			return;

		}

		inSS >> controlType;

		inSS >> tempCount;

		dayNumCount = stoi(tempCount);

		lineCount++;

		if (dayCount <= 0 || dayNumCount != (schedule.schedule.size() + 1)) {
			inputError(formatError);
			return;

		}
		else if (controlType == "DAY") {

			controlCount++;

			vector<edge_Maintenance> schedule_edges;
			
			vector<locomotive_Maintenance> schedule_Locomotives;

			Maintenance_Day day(schedule_edges, schedule_Locomotives);

			getline(inFS, rowInfo);

			istringstream inSS(rowInfo);

			string input1;

			string input2;

			string input3;

			inSS >> input1;

			inSS >> input2;

			inSS >> input3;

			int typeCount = stoi(input3);

			if (input1 != "C") {
			
				inputError(formatError);
				return;

			}

			if (input2 == "EDGE") {

				controlCount++;

				string input1;

				string input2;

				string input3;

				int edgeIndex;

				while (typeCount != 0) {
				
					getline(inFS, rowInfo);

					istringstream inSS(rowInfo);

					inSS >> input1;

					inSS >> input2;

					edgeIndex = findEdge(input1, input2);

					if (edgeIndex == -1) {
					
						inputError(error3 + input1 + " to " + input2 + " not found");

					}

					inSS >> input3;

					edge_Maintenance edgeInput(graphEdges.at(edgeIndex), stoi(input3));

					day.edges.push_back(edgeInput);

					lineCount++;

					typeCount--;

				}

			}
			else {

				inputError(typeError);
				return;

			}

			getline(inFS, rowInfo);

			istringstream inSS1(rowInfo);

			inSS1 >> input1;

			if (input1 != "C") {

				inputError(formatError);
				return;

			}

			inSS1 >> input2;

			inSS1 >> input3;
			
			typeCount = stoi(input3);

			if (input2 == "LOCOMOTIVE") {

				controlCount++;

				string input1;

				string input2;

				int locomotiveIndex;

				while (typeCount != 0) {
				
					getline(inFS, rowInfo);

					istringstream inSS(rowInfo);

					inSS >> input1;

					locomotiveIndex = findLocomotive(input1);

					if (locomotiveIndex == -1) {

						inputError(error3);

					}

					inSS >> input2;

					locomotive_Maintenance locomotiveInput(locomotives.at(locomotiveIndex), stoi(input2));

					day.locomotives.push_back(locomotiveInput);

					lineCount++;

					typeCount--;

				}

			}
			else {
			
				inputError(typeError);
				return;

			}

			schedule.schedule.push_back(day);

			lineCount++;

		}
		else {

			inputError(typeError);
			return;

		}

		lineCount++;

		dayCount--;

	}

	string T;

	int tInput1;

	int tInput2;

	int tInput3;

	istringstream inSS2(rowInfo);

	inSS2 >> T;

	inSS2 >> tempCount;

	tInput1 = stoi(tempCount);

	inSS2 >> tempCount;

	tInput2 = stoi(tempCount);

	inSS2 >> tempCount;

	tInput3 = stoi(tempCount);

	if (lineCount != tInput1) {
		inputError(formatError);
		return;
	}
	
	if (controlCount != tInput2) {
		inputError(formatError);
		return;
	}

	if (tInput3 != dayNumCount){
		inputError(formatError);
		return;
	}

}

void configFileRead(string fileName, Graph<Station>& structure, config& configuration) {

	ifstream inFS = readFileName(fileName);

	string formatError = "Invalid input format.";

	string typeError = "Invalid control type.";

	string  rowInfo; //Creates a string to be used in the istringstream 

	string tempCount;

	int controlCount = 0;

	readHeader(inFS, rowInfo, controlCount);

	int controlTempCount = controlCount;

	string controlLine;

	string controlType;

	int typeCount;

	int lineCount = 0;

	while (!inFS.eof()) //Loop that continues until the end of the file is reached
	{

		getline(inFS, rowInfo);

		istringstream inSS(rowInfo); //Creates a string stream named inSS

		inSS >> controlType;

		if (controlType == "T") {
			//cout << "T line" << endl;
			break;

		}

		int locomotiveIndex = findLocomotive(controlType);

		lineCount++;

		string input1;

		string input2;

		string input3;

		string input4;

		string input5;

		if (locomotiveIndex != -1) {

			inSS >> input1;

			inSS >> input2;

			inSS >> input3;

			inSS >> input4;

			inSS >> input5;

			LocoConfig locomotiveInput(locomotives.at(locomotiveIndex), input1.at(0), stoi(input2), stoi(input3), stoi(input4), stoi(input5));

			configuration.locomotives.push_back(locomotiveInput);

		}
		else if (controlType == "CREWS") {

			inSS >> input1;

			configuration.crewsAtEachHub = stoi(input1);

		}
		else if (controlType == "FUEL") {

			inSS >> input1;

			configuration.fuelCapacityAtHub = stoi(input1);

		}
		else if (controlType == "RUN") {

			inSS >> input1;

			configuration.run = stoi(input1);

		}
		else {

			inputError(typeError);
			return;

		}

		controlCount--;

	}

	string T;

	int tInput1;

	istringstream inSS2(rowInfo);

	inSS2 >> T;

	inSS2 >> tempCount;

	tInput1 = stoi(tempCount);

	if (lineCount != tInput1) {
		inputError(formatError);
		return;
	}

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