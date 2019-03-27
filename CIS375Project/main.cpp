#include<iostream>
#include "graph.h"
#include "city.h"
using namespace std;
using namespace GraphNameSpace;

int main()
{
  City seattle("Seattle");
  City losAngeles("Los Angeles");
  City phoenix("Phoenix");
  City denver("Denver");
  City fargo("Fargo");
  City minneapolis("Minneapolis");
  City houston("Houston");
  City stLouis("St. Louis");
  City chicago("Chicago");
  City detroit("Detroit");
  City miami("Miami");
  City newYork("New York");
  
  Graph<City> cities(UNWEIGHTED);
  
  cities.insertVertex(seattle);
  cities.insertVertex(losAngeles);
  cities.insertVertex(phoenix);
  cities.insertVertex(denver);
  cities.insertVertex(fargo);
  cities.insertVertex(minneapolis);
  cities.insertVertex(houston);
  cities.insertVertex(stLouis);
  cities.insertVertex(chicago);
  cities.insertVertex(detroit);
  cities.insertVertex(miami);
  cities.insertVertex(newYork);
  
  cities.dump();
  
  cities.insertEdge(seattle, chicago, 2072);
  cities.insertEdge(seattle, denver, 1332);
    
  cities.insertEdge(losAngeles, seattle, 1151);
  cities.insertEdge(losAngeles, denver, 1023);
  cities.insertEdge(losAngeles, phoenix, 381);
  cities.insertEdge(losAngeles, newYork, 2824);
  
  cities.insertEdge(phoenix, losAngeles, 381);
  cities.insertEdge(phoenix, houston, 1186);
  
  cities.insertEdge(denver, losAngeles, 1023);
  cities.insertEdge(denver, minneapolis, 920);
  
  cities.insertEdge(fargo, minneapolis, 240);
  cities.insertEdge(fargo, denver, 909);
  
  cities.insertEdge(minneapolis, fargo, 240);
  cities.insertEdge(minneapolis, chicago, 409);
  cities.insertEdge(minneapolis, denver, 920);
  
  cities.insertEdge(houston, phoenix, 1186);
  cities.insertEdge(houston, stLouis, 780);
  cities.insertEdge(houston, miami, 1190);
  
  cities.insertEdge(stLouis, denver, 861);
  cities.insertEdge(stLouis, detroit, 547);
  
  cities.insertEdge(chicago, minneapolis, 409);
  cities.insertEdge(chicago, detroit, 286);
  cities.insertEdge(chicago, newYork, 821);
  
  cities.insertEdge(detroit, chicago, 286);
  cities.insertEdge(detroit, stLouis, 547);
  cities.insertEdge(detroit, newYork, 640);
  
  cities.insertEdge(miami, houston, 1190);
  cities.insertEdge(miami, newYork, 1281);
  
  cities.insertEdge(newYork, chicago, 821);
  cities.insertEdge(newYork, losAngeles, 2824);
  cities.insertEdge(newYork, miami, 1281);

  cities.dump();
  
  if(cities.isAdjacentTo(newYork, losAngeles) == true)
  {
    cout << "Yes they are adjacent\n";
  }
  else
    cout << " No they aren't adjacent\n";
  
  cout << "edgeWeight(newYork, chicago) = " << cities.edgeWeight(newYork, newYork) << endl;
  cout << "edgeWeight(chicago, minneapolis) = " << cities.edgeWeight(chicago, minneapolis) << endl;
  
  cout << "City graph has " << cities.vertexCount() << " Vertice(s)\n";
  
  cities.deleteEdge(newYork, chicago);
  
  cout << endl;
  cout << endl;
  
  cities.dump();
  
  cout << endl;
  cout << endl;
  
  cities.deleteVertex(newYork);
  
  cities.dump();
  
  cout <<  "Miami is at index: " << cities.findVertex(miami) <<  endl;
  cout <<  "New York is at index: " << cities.findVertex(newYork) <<  endl; // doesnt exist. Should return -1
  
  cities.destroy();

  cities.insertVertex(losAngeles);
  cities.insertVertex(phoenix);
  cities.insertVertex(denver);
  cities.insertVertex(fargo);
  cities.insertVertex(minneapolis);
  cities.insertVertex(houston);
  cities.insertVertex(stLouis);
  cities.insertVertex(chicago);
  cities.insertVertex(detroit);
  cities.insertVertex(miami);
  cities.insertVertex(newYork);
  
  cities.dump();
  
  Graph<City> cities_other(UNWEIGHTED);
  
  cities_other = cities;
  
  cout << endl << endl;
  
  cities_other.dump();

  
  return 0;
}