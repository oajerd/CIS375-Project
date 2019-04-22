#ifndef _CONFIG_FILE_READER_H_
#define _CONFIG_FILE_READER_H_

#include "file_read_utility.h"

void configFileRead(string fileName, Graph<Station>& structure, config& configuration);

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

#endif