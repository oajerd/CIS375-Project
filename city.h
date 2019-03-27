#include<iostream>
  
#ifndef _CITY_H_
#define _CITY_H_
using namespace std;

// TEST' CLASS
// TEST' CLASS
// TEST' CLASS


class City
{
   public:
      City();
      City(string);  // constructor with default radius
      void setName(string);
      string getName() const;
      
      bool operator ==(const City& ) const;
      bool operator !=(const City&) const;
      bool operator <(const City& ) const;
      bool operator >(const City& ) const;
      bool operator <=(const City& ) const;
      bool operator >=(const City& ) const;
   private:
      string name;
};
ostream& operator <<(ostream&, City&);
#endif