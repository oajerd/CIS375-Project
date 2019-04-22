//
//  main.cpp
//  Stations
//
//  Created by Oussama Ajerd on 4/10/19.
//  Copyright © 2019 Oussama Ajerd. All rights reserved.
//

#include<iostream>
#include "graph.h"
#include "station.h"
#include"login.h"
#include"fileReader.h"
#include"CIS375Project/output.h"

using namespace std;
using namespace GraphNameSpace;
int main() {
    
	//login();

	output();

   // Station hub1("hub1");
   // Station hub2("hub2");
    
    //Station station1("station1", 'P', 2, 250, 500, 100, 350, 7.00);
   // Station station2("station2", 'P', 4, 200, 300, 200, 350, 9.00);
    
    Graph<Station> stations(UNWEIGHTED);
    
    //stations.insertVertex(hub1);
    //stations.insertVertex(hub2);
    //stations.insertVertex(station1);
    //stations.insertVertex(station2);
    
    //stations.insertEdge(hub1, station1);
    //stations.insertEdge(station1, station2);
    //stations.insertEdge(station2, hub2);
    
	string str = "structure.txt";

	structureFileRead(str, stations);

	Maintenance_Schedule schedule1;

	str = "dailyRoutes.txt";

	dailyRoutesFileRead(str, stations, schedule1);

	str = "repeatableRoutes.txt"; //"structure.txt";

	rRoutesFileRead(str, stations);

    stations.dump();

	Maintenance_Schedule schedule;

	str = "maintenance.txt";

	maintenanceFileRead(str, stations, schedule);

	cout << endl;

	schedule.displaySchedule();

	config configuration;

	str = "config.txt";

	configFileRead(str, stations, configuration);

	configuration.displayConfig();

    //cout << stations.findVertex(hub1);

	for (int i = 0; i < dailyRoutes.size(); i++) {
	
		cout << "DAY: " << i + 1 << endl;

		dailyRoutes.at(i).displayRoutes();

		cout << endl;

	}

	system("pause");

    return 0;
}
