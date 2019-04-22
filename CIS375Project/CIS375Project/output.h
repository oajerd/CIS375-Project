#pragma once
#include "../structure_objects.h"
#include "station.h"
#include<iomanip>
#include<ostream>



void output() {

	ofstream out;
	out.open("output.txt");
	out << "Hello World" << endl;
	out.close();
	
}



