#ifndef _MAINTENANCE_H_
#define _MAINTENANCE_H_

#include "structure_objects.h"

struct edge_Maintenance {

	Edge edge;

	int daysUnavailable;

	edge_Maintenance(Edge e, int days) {

		edge = e;

		daysUnavailable = days;

	}

};

struct locomotive_Maintenance {

	Locomotive locomotive;

	int daysUnavailable;

	locomotive_Maintenance(Locomotive l, int days) {

		locomotive = l;

		daysUnavailable = days;

	}

};

struct Maintenance_Day {

public:

	vector<edge_Maintenance> edges;

	vector<locomotive_Maintenance> locomotives;

	Maintenance_Day(vector<edge_Maintenance> e, vector<locomotive_Maintenance> l) {

		edges = e;

		locomotives = l;

	}

};

class Maintenance_Schedule {

public:

	vector<Maintenance_Day> schedule;

	void displaySchedule() {

		for (int i = 0; i < schedule.size(); i++) {

			cout << "DAY " << i + 1 << ":" << endl;

			for (int j = 0; j < schedule.at(i).edges.size(); j++) {

				cout << "EDGE " << j << " Source: " << schedule.at(i).edges.at(j).edge.getNode1().getName();
				cout << " Destination: " << schedule.at(i).edges.at(j).edge.getNode2().getName() << endl;

			}

			for (int j = 0; j < schedule.at(i).locomotives.size(); j++) {

				cout << schedule.at(i).locomotives.at(j).locomotive.getName() << endl;

			}

			cout << endl << endl;

		}

	}

};
#endif