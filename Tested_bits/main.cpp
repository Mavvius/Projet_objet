//main.cpp

#include "class_agent.hpp"
#include "class_localisation.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{	

  	Localisation* loc1 = nlocalisation("frigo","armoire",2);
  	Localisation* loc2 = nlocalisation("centri","equipe",3);
  	vector<Localisation*> nantes {loc1,loc2};
	Agent* lapin = nagent("nom",1,2,3,"type","reservoir",
						"source","vecteur","transmission","diagnostic",
						"treatment","immunité","pop_a_risque", nantes);

	cout << lapin->getLocalisations()[0]->getQt() <<"\n" ;
	return 0;
}