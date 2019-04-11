#include "station.h"
#include<string>

// TEST' CLASS

Station::Station()
{
	name = "";
}

Station::Station(string r)
{
	name = r;
}

Station::Station(string r, char type, int capacity, int lowBoard, int highBoard, int lowUnboard, int highUnboard, float ticketPrice) {
	name = r;
	type = type;
	capcity = capacity;
	lowBoard = lowBoard;
	highBoard = highBoard;
	highUnboard = highUnboard;
	lowUnboard = lowUnboard;
	ticketPrice = ticketPrice;

}

void Station::setName(string r)
{
	name = r;
}

string Station::getName() const
{
	return name;
}

void Station::setStationInfo(string r, char type, int capacity, int lowBoard, int highBoard, int lowUnboard, int highUnboard, float ticketPrice) {
	name = r;
	type = type;
	capcity = capacity;
	lowBoard = lowBoard;
	highBoard = highBoard;
	highUnboard = highUnboard;
	lowUnboard = lowUnboard;
	ticketPrice = ticketPrice;
}

bool Station::operator ==(const Station& obj)const
{
	if (getName() == obj.getName())
		return true;
	else
		return false;
}

bool Station::operator != (const Station & obj)const
{
	return !(*this == obj);
}

bool Station::operator<(const Station & obj)const
{
	if (getName() < obj.getName())
		return true;
	else
		return false;
}

bool Station::operator > (const Station & obj)const
{
	return !(*this < obj);
}

bool Station::operator <= (const Station & obj)const
{
	return *this < obj || *this == obj;
}

bool Station::operator >= (const Station & obj)const
{
	return !(*this < obj);
}

ostream& operator <<(ostream& output, Station& StationObj)
{
	output << StationObj.getName();

	return output;
}
