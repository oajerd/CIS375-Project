//
//  station.hpp
//  Stations
//
//  Created by Oussama Ajerd on 4/10/19.
//  Copyright © 2019 Oussama Ajerd. All rights reserved.
//

//
//  city.h
//  GraphTwo
//
//  Created by Oussama Ajerd on 3/20/19.
//  Copyright © 2019 Oussama Ajerd. All rights reserved.
//

#include<iostream>

#ifndef _STATION_H_
#define _STATION_H_
using namespace std;

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
    
    bool operator ==(const Station& ) const;
    bool operator !=(const Station&) const;
    bool operator <(const Station& ) const;
    bool operator >(const Station& ) const;
    bool operator <=(const Station& ) const;
    bool operator >=(const Station& ) const;
private:
    string name;
    char type;
    int capacity;
    int lowBoard;
    int highBoard;
    int lowUnboard;
    int highUnboard;
    float ticketPrice;
    
};
ostream& operator <<(ostream&, Station&);

#endif /* city_h */

