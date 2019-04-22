#ifndef _DAILYROUTES_FILE_READER_H_
#define _DAILYROUTES_FILE_READER_H_

#include "file_read_utility.h"

void dailyRoutesFileRead(string fileName, Graph<Station>& structure, Maintenance_Schedule& schedule);

void dailyRoutesFileRead(string fileName, Graph<Station>& structure, Maintenance_Schedule& schedule) {

	string error1 = "Incorrect control structure count.";

	string error2 = " not found.";

	string error3 = "Edge ";

	string error4 = "Edge not found between node1 and node2";

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

		DailyRoute day(dayNumCount);

		lineCount++;

		if (dayCount <= 0 || dayNumCount != (dailyRoutes.size() + 1)) {
			inputError(formatError);
			return;

		}
		else if (controlType == "DAY") {

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
			else if (input2 == "FREIGHT") {

				string input1;

				string input2;

				string input3;

				string input4;

				int node1Index;

				int node2Index;

				controlCount += typeCount;

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

					Route freightRoute("F", "N/A", input3, stoi(input4));
					freightRoute.setRoute(stations);

					day.freightRoutes.push_back(freightRoute);

					typeCount--;

					lineCount++;

				}

			}
			else {

				inputError(typeError);

			}

			getline(inFS, rowInfo);

			istringstream inSS2(rowInfo);

			inSS2 >> input1;

			inSS2 >> input2;

			inSS2 >> input3;

			typeCount = stoi(input3);

			if (input1 != "C") {

				inputError(formatError);
				return;

			}
			else if (input2 == "PASSENGER") {

				controlCount += typeCount;

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

					controlCount += routeCount;

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

										inputError(formatError);

									}

								}

								routeCount--;

								lineCount++;

							}

							Route passengerRoute("P");

							passengerRoute.setRoute(stations);
							passengerRoute.setArrivalTimes(arrivalTimes);

							day.passengerRoutes.push_back(passengerRoute);

						}

					}
					else {

						inputError(typeError);

					}

					typeCount--;

					lineCount++;

				}

			}
			else {

				inputError(typeError);

			}

			lineCount++;

		}
		else {

			inputError(typeError);
			return;

		}

		dailyRoutes.push_back(day);

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

	if (lineCount != tInput1) {
		inputError(formatError);
		return;
	}

	if (controlCount != tInput2) {
		inputError(formatError);
		return;
	}

}

#endif