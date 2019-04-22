#ifndef _MAINTENANCE_FILE_READER_H_
#define _MAINTENANCE_FILE_READER_H_

#include "file_read_utility.h"

void maintenanceFileRead(string fileName, Graph<Station>& structure, Maintenance_Schedule& schedule);

void maintenanceFileRead(string fileName, Graph<Station>& structure, Maintenance_Schedule& schedule)
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

	if (tInput3 != dayNumCount) {
		inputError(formatError);
		return;
	}

}

#endif