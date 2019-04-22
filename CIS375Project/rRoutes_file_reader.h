#ifndef _RROUTES_FILE_READER_H_
#define _RROUTES_FILE_READER_H_

#include "file_read_utility.h"

void rRoutesFileRead(string fileName, Graph<Station>& structure);

void rRoutesFileRead(string fileName, Graph<Station>& structure) {

	ifstream inFS = readFileName(fileName);

	string formatError = "Invalid input format.";

	string typeError = "Invalid control type.";

	string error1 = "Incorrect control structure count.";

	string error2 = " not found.";

	string error3 = "Node1 of edge is equal to Node2";

	string error4 = "Edge not found between node1 and node2";

	string  rowInfo; //Creates a string to be used in the istringstream 

	string tempCount;

	int controlCount = 0;

	readHeader(inFS, rowInfo, controlCount);

	int controlTempCount = controlCount;

	int controlCountSum = 0;

	string controlLine;

	string controlType;

	string routeType;

	int typeCount;

	int lineCount = 0;

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

		typeCount = stoi(tempCount);

		controlCountSum += typeCount;

		lineCount++;

		lineCount += typeCount;

		if (controlCount <= 0) {
			inputError(formatError);
			return;

		}
		else if (controlType == "FREIGHT") {

			string input1;

			string input2;

			string input3;

			string input4;

			string input5;

			int node1Index;

			int node2Index;

			while (typeCount != 0) {

				vector<Station> stations;

				getline(inFS, rowInfo);

				istringstream inSS(rowInfo);

				inSS >> input1;

				if (invalidStructure(input1)) {
					inputError(formatError);
				}

				node1Index = findNode(input1);

				if (node1Index == -1) {

					inputError(input1 + error2);

				}
				stations.push_back(nodes.at(node1Index));

				inSS >> input2;

				node2Index = findNode(input2);

				if (node2Index == -1) {

					inputError(input2 + error2);

				}

				stations.push_back(nodes.at(node2Index));

				if (!structure.isAdjacentTo(nodes.at(node1Index), nodes.at(node2Index))) {

					inputError(error4);

				}

				inSS >> input3;

				inSS >> input4;

				inSS >> input5;

				Route freightRoute("F", input3, input4, stoi(input5));
				freightRoute.setRoute(stations);

				repeatableFRoutes.push_back(freightRoute);

				typeCount--;

			}

		}
		else if (controlType == "PASSENGER") {

			while (typeCount != 0) {

				int node1Index;

				getline(inFS, rowInfo);

				istringstream inSS(rowInfo);

				string input1;

				inSS >> input1;

				string input2;

				inSS >> input2;

				string input3;

				int routeCount;

				inSS >> input3;

				routeCount = stoi(input3);

				controlCountSum += routeCount;

				string input4;

				inSS >> input4;

				if (input1 == "C") {

					if (input2 == "ROUTE") {

						vector<Station> stations;
						vector<Time> arrivalTimes;

						while (routeCount != 0) {

							getline(inFS, rowInfo);

							istringstream inSS(rowInfo);

							inSS >> input1;

							if (invalidStructure(input1)) {
								inputError(formatError);
							}

							node1Index = findNode(input1);

							if (node1Index == -1) {

								inputError(input1 + error2);

							}

							inSS >> input2;

							stations.push_back(nodes.at(node1Index));

							Time input2Time;

							input2Time.setTime(stoi(input2.substr(0, 2)), stoi(input2.substr(3, 2)));

							arrivalTimes.push_back(input2Time);

							if (stations.size() > 1) {

								if (!structure.isAdjacentTo(stations.at(stations.size() - 2), nodes.at(node1Index))) {

									inputError(error4);

								}

							}

							routeCount--;

							lineCount++;

						}

						Route passengerRoute("P");

						passengerRoute.setRoute(stations);
						passengerRoute.setArrivalTimes(arrivalTimes);

						repeatablePRoutes.push_back(passengerRoute);

					}

				}
				else {

					inputError(typeError);

				}



				typeCount--;

			}

		}
		else {

			inputError(typeError);

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

	if (controlCountSum != tInput2) {
		inputError(formatError);
		return;
	}

}

#endif