#include "city.h"

// TEST' CLASS

City::City()
{
   name = "";
}

City::City(string r)
{
   name = r;
}

void City::setName(string r)
{
   name = r;
}

string City::getName() const
{
   return name;
}

bool City::operator ==(const City& obj)const 
{
    if(getName()==obj.getName())
      return true;
    else
      return false;
}

bool City::operator != (const City & obj)const
{
    return !(*this == obj);
}

bool City::operator<(const City & obj)const
{
    if(getName() < obj.getName())
      return true;
    else
      return false;
}

bool City::operator > (const City & obj)const
{
    return !(*this < obj);
}

bool City::operator <= (const City & obj)const
{
    return *this < obj || *this == obj;
}

bool City::operator >= (const City & obj)const
{
return !(*this < obj);
}

ostream& operator <<(ostream& output, City& cityObj)
{
  output << cityObj.getName();
  
  return output;
}