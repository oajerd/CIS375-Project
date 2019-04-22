#ifndef _ROUTE_H_
#define _ROUTE_H_

#include<iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "station.h"
#include "Time.h"

using namespace GraphNameSpace;

using namespace std;

class Route {

public:

	vector<Station> stations;

	vector<Time> arrivalTimes;

	//Freight Information

	string trainType; //Passenger or freight

	string type;

	Time startTime;

	int capacity;

	//Passenger Information

	Route(string tType = "", string t = "", string st = "00:00", int c = 0) {

		//For passenger

		trainType = tType;

		//For frieght

		type = t;

		startTime.setTime(stoi(st.substr(0, 2)), stoi(st.substr(3, 2)));

		capacity = c;

	}

	void setRoute(vector<Station> s) {
	
		stations = s;

	}

	void setArrivalTimes(vector<Time> a) {

		arrivalTimes = a;

	}

	void setInfo(string tType, vector<Time> at, string t, Time st, int c, vector<Station> s) {

		//For passenger

		trainType = tType;

		arrivalTimes = at;

		//For frieght

		type = t;

		startTime = st;

		capacity = c;

		stations = s;

	}

	Station next(int index) {//for cycle true is forward and false is reverse

		if (index >= stations.size()) {
		
			cout << "End of route reached " << endl;

			return stations.at(index);

		}

		return stations.at(index + 1);

	}

	void displayRouteInfo() {
	
		if (trainType == "F") {
		
			for (int i = 0; i < stations.size(); i++) {

				cout << stations.at(i).getName() << " ";

			}

			cout << type << " " << startTime.displayTime() << " " << capacity << endl;

		}
		else if(trainType == "P"){
		
			if (stations.size() != arrivalTimes.size()) {
			
				cout << "File read error: Arrival times don't match station count";

				return;

			}

			for (int i = 0; i < stations.size(); i++) {

				cout << stations.at(i).getName() << " " << arrivalTimes.at(i).displayTime() << endl;

			}

		}
		else {

			for (int i = 0; i < stations.size(); i++) {

				cout << stations.at(i).getName() << " ";

			}

			cout << "(Train route type undefined)" << endl;

		}

	}

};

class DailyRoute {

public:

	int day;

	vector<Route> freightRoutes;

	vector<Route> passengerRoutes;

	DailyRoute(int d = -1) {
	
		day = d;

	}

	DailyRoute(vector<Route> f, vector<Route> p) {

		freightRoutes = f;

		passengerRoutes = p;

	}

	void displayRoutes() {
	
		cout << "Freight Routes:" << endl;

		for (int i = 0; i < freightRoutes.size(); i++) {
		
			freightRoutes.at(i).displayRouteInfo();

		}

		cout << endl << "Passenger Routes:" << endl;

		for (int i = 0; i < passengerRoutes.size(); i++) {

			passengerRoutes.at(i).displayRouteInfo();

		}

	}

};

#endif
