#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "structure_objects.h"
#include <vector>

struct LocoConfig {

public:

	Locomotive locomotive;

	char type;
	int fuelCapacity;
	int fuelCost;
	int speed;
	int capacity;

	LocoConfig(Locomotive l, char t = ' ', int fuelCap = 0, int fuelC = 0, int s = 0, int cap = 0) {
	
		locomotive = l;

		type = t;
		
		fuelCapacity = fuelCap;
		
		fuelCost = fuelC;
		
		speed = s;
		
		capacity = cap;

	}

};

struct config {

public:

	vector<LocoConfig> locomotives;
	
	int crewsAtEachHub;
	int fuelCapacityAtHub;
	int run;

	config() {

		crewsAtEachHub = 0;

		fuelCapacityAtHub = 0;

		run = 0;

	}

	config(vector<LocoConfig> l, int cAtHub = 0, int fuelAtHub = 0, int r = 0) {
	
		locomotives = l;

		crewsAtEachHub = cAtHub;

		fuelCapacityAtHub = fuelAtHub;

		run = r;

	}

	void displayConfig() {
	
		cout << "Locomotives" << endl;

		for (int i = 0; i < locomotives.size(); i++) {
		
			cout << locomotives.at(i).locomotive.getName() << " ";

			cout << locomotives.at(i).type << " ";

			cout << locomotives.at(i).fuelCapacity << " ";

			cout << locomotives.at(i).fuelCost << " ";

			cout << locomotives.at(i).speed << " ";

			cout << locomotives.at(i).capacity << endl;

		}

		cout << "# of crews at each hub: " << crewsAtEachHub << endl;

		cout << "Fuel capacity at each hub: " << fuelCapacityAtHub << endl;

		cout << "Simulation run time: " << run << endl;

		return;

	}

};

#endif