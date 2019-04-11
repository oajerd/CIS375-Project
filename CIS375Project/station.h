#include<iostream>

#ifndef _STATION_
#define _STATION_
using namespace std;

// TEST' CLASS
// TEST' CLASS
// TEST' CLASS


class Station
{
public:
	Station();
	Station(string);  // constructor with default radius
	Station(string, char, int, int, int, int, int, float);
	void setName(string);
	string getName() const;

	void setStationInfo(string, char, int, int, int, int, int, float);
	string getStationInfo() const;

	bool operator ==(const Station&) const;
	bool operator !=(const Station&) const;
	bool operator <(const Station&) const;
	bool operator >(const Station&) const;
	bool operator <=(const Station&) const;
	bool operator >=(const Station&) const;
private:
	string name;
	char type;
	int capcity;
	int lowBoard;
	int highBoard;
	int lowUnboard;
	int highUnboard;
	float ticketPrice;
};
ostream& operator <<(ostream&, Station&);
#endif