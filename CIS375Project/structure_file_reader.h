#ifndef _STRUCTURE_FILE_READER_H_
#define _STRUCTURE_FILE_READER_H_

#include "file_read_utility.h"

void structureFileRead(string fileName, Graph<Station>& structure);

void HUBinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void STATIONinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void EDGEinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

void LOCOMOTIVEinput(int typeCount, ifstream& inFS, string rowInfo, Graph<Station>& structure);

// Purpose: To read and store info into the graph
// Author: Austin Greear
// Last Modification Date: 4/13/19
void structureFileRead(string fileName, Graph<Station>& structure)
{

	ifstream inFS = readFileName(fileName);

	string formatError = "Invalid structure file input format.";

	string typeError = "Invalid structure file control type.";

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

		//cout << controlLine;

		if (controlLine != "C") {

			if (controlLine == "T") {
				//cout << "T line" << endl;
				break;

			}

			inputError("Hello" + formatError);
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

#endif