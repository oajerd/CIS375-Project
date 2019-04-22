#ifndef _TIME_H
#define _TIME_H

#include <iomanip>

struct Time {

public:

	int hours;

	int minutes;

	Time(int h = 0, int m = 0) {

		hours = h;

		minutes = m;

	}

	void setTime(int h = 0, int m = 0) {

		hours = h;

		minutes = m;

	}

	void operator =(const Time& obj)
	{
		
		hours = obj.hours;

		minutes = obj.minutes;

	}

	string displayTime() {

		string m = "";

		if (minutes < 10) {
		
			m = "0";

		}

		return to_string(hours) + ":" + m + to_string(minutes);

	}

};

#endif