//main.cpp

#include "class_agent.hpp"
#include "class_localisation.hpp"
#include "class_Laboratory.hpp"

#include <iostream>
#include <fstream> // Pour l'ouverture de fichiers
#include <string> // Pour la lecture de string plutot que char*
#include <vector> 
#include <algorithm> // Pour utiliser boost et les iterateurs sur vecteur
#include <typeinfo> // pour tester sur les types
#include <boost/algorithm/string.hpp> 
#include <boost/range/algorithm/count.hpp> 

using namespace std;


int main(int argc, char const *argv[])
{	


	 std::cout << "tout s'est bien passé \n";
	 Laboratory lab;
	 lab.open_agent_tsv("Fichier_Agents.tsv");
	 //lab.print();

	 //lab.find_agent("E.coli");

	 lab.add_agent("C.virus", 2, 12, 2, "type", "humain", "Humain", " goutellettes" , "aerienne", " prelevement pharyngé", "isolement/repos", "non", "habituelle", "Frigo1,Armoire,2;Eppendorf,Equipement,8;Cfroide,placard,5");

	 lab.show_agent_loc("C.virus");

	 lab.save_data("foo.tsv");


	return 0;
}

