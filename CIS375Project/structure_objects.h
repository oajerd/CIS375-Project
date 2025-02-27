#ifndef _STRUCTURE_OBJECTS_H_
#define _STRUCTURE_OBJECTS_H_

#include<iostream>
#include <vector>
#include <string>
#include "Route.h"
#include "station.h"
#include "Time.h"


class Node {

public:

	string getName() {

		return name;

	}

protected:

	string name;

};

class Hub : public Node {

	//input 1 in parent class Node

public:

	Hub(string input1 = "") {

		name = input1;

	}

};

class Edge {

	Station node1; //input1

	Station node2; //input2

	int distance; //input3

	Time startTime;

	Time endTime;

	int index;

public:

	Edge() {

		index = -1;

	}

	Edge(Station& input1, Station& input2, string input3 = "", string input4 = "", string input5 = "", int ind = -1) {

		node1 = input1;

		node2 = input2;

		distance = stoi(input3);

		startTime.setTime(stoi(input4.substr(0, 2)), stoi(input4.substr(3, 2)));

		endTime.setTime(stoi(input5.substr(0, 2)), stoi(input5.substr(3, 2)));

	}

	Station getNode1() {

		return node1;

	}

	Station getNode2() {

		return node2;

	}

};

class Locomotive {

	string name;//input1

	Station hub; //input2

	string type; //input3

	int routeIndex;

	Station currentLocation;

	Station nextLocation;

	Route trainRoute;

public:

	void assignRoute(Route r) {
	
		trainRoute.setInfo(r.trainType, r.arrivalTimes, r.type, r.startTime, r.capacity, r.stations);

	}

	void setLocation(Station x) {

		currentLocation = x;

	}
			
			
	Station getLocation() {
		
		return currentLocation;
		
	}

	Station getDestination(){

		return trainRoute.next(routeIndex);
		
	}

	Station nextStation() {
	
		currentLocation = nextLocation;
		nextLocation = trainRoute.next(routeIndex);
	
	}

	Locomotive() {

		name = "";

	}

	Locomotive(string input1, Station input2, string input3, int ri = -1) {

		name = input1;

		hub = input2;

		type = input3;

		routeIndex = ri;

	}

	string getName() {

		return name;

	}

	Station setStation(Station s) {
	
		hub = s;

	}

	Station getStation() {

		return hub;

	}

};

struct Objects {

public:

	vector<Node> nodes;

	vector<Hub> hubs;

	vector<Station> stations;

	vector<Edge> edges;

	vector<Locomotive> locomotives;

	Objects(vector<Node>& n, vector<Hub>& h, vector<Station>& s, vector<Edge>& e, vector<Locomotive>& l) {

		nodes = n;

		hubs = h;

		stations = s;

		edges = e;

		locomotives = l;

	}

	void displayHubs() {

		for (int i = 0; i < hubs.size(); i++) {

			cout << hubs.at(i).getName() << endl;

		}

	}

	void displayStations() {

		for (int i = 0; i < stations.size(); i++) {

			cout << stations.at(i).getName() << endl;

		}

	}

	void displayEdges() {

		for (int i = 0; i < edges.size(); i++) {

			cout << "Edge " << i + 1 << " Source: " << edges.at(i).getNode1().getName() << " Destination: " << edges.at(i).getNode2().getName() << endl;

		}

	}

	void displayLocomotives() {

		for (int i = 0; i < locomotives.size(); i++) {

			cout << locomotives.at(i).getName() << endl;

		}

	}

	void displayData() {

		displayHubs();
		displayStations();
		displayEdges();
		displayLocomotives();
	}

};

#endif