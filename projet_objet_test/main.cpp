//main.cpp

#include "class_agent.hpp"
#include "class_localisation.hpp"
#include "class_personnel.hpp"
#include "global.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // Pour utiliser boost et les iterateurs sur vecteur
#include <typeinfo>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <boost/range/algorithm/count.hpp>
#include <boost/format.hpp>
#include <regex>

using namespace std;

///global variables containing available items
std::vector<Personnel*> personnel;
std::vector<Localisation*> localisations;
std::vector<Agent*> vect_agents; // Vecteur où on range les différents agents
std::regex numericReg("^[0-9]{1,10}$");

int main(int argc, char const *argv[])
{	
	ifstream file_agents;
	file_agents.open("Fichier_Agents.tsv");
	if (!file_agents) {
		cerr << "Missing AgentsDb file" << endl;
		return 1;
	}
  	string temp_agents;
  	string temp_loc;

  	getline(file_agents, temp_agents); // skip the first line
 	 while (getline(file_agents, temp_agents)) {
		vector<string> Attributes; // Vecteur où vont être stockées les cellules du tableau *.tsv
		vector<Localisation*> emplacements; // Initialisation d'un vecteur de localisation pour instancier les agents
		boost::algorithm::split(Attributes, temp_agents, boost::is_any_of("\t")); // lecture du tsv par \t separateur   
			string locs = Attributes[13];
			int cnt = boost::count(locs, ';');
		//cout << "nb vir : " << cnt << "\n";
			auto start = 0U;
		auto end = locs.find(";");
		// Sert a découper les localisations séparées par des ";"
		for (int i = 0; i < cnt+1; ++i){
  		//cout << locs.substr(start, end - start) << std::endl;
        string locat = locs.substr(start, end - start);
        auto deb = 0U;
    		auto fin = locat.find(",");
    		std::vector<string> temp_emplacement;
      	// Découpe une localisation pour différencier ses 3 attributs Nom type et quantité
        for (int i = 0; i < 3; ++i)
        {
        	temp_emplacement.push_back(locat.substr(deb, fin - deb)); // stocke la localisation dans un vecteur temporaire
 
  //  			cout << " locn :" << locat.substr(deb, fin - deb) << std::endl;
    			deb = fin + 1; // parce que la longueur du char est de 1.
    			fin = locat.find(",", deb);
        }
 //       cout << "----------" << typeid(stoi(temp_emplacement[2])).name() << "\n ---------------\n";
      	// Instanciation du vecteur de localisation qui sera utiliser pour instancier l'Agent pathogène
      	emplacements.push_back(nlocalisation(temp_emplacement[0], temp_emplacement[1], stoi(temp_emplacement[2])));

        start = end + 1;
        end = locs.find(";", start);
    }

  //load les agents possibles
	vect_agents.push_back(nagent(Attributes[0], //nom
 	                          stoi(Attributes[1]), // contagion
                            stoi(Attributes[2]), // incubation
                            stoi(Attributes[3]), // group
                            Attributes[4], // type
                            Attributes[5], // reservoir
                            Attributes[6], // source
                            Attributes[7], // vecteur
                            Attributes[8], // transmission
                            Attributes[9], // diagnostic
                            Attributes[10], // traitement
                            Attributes[11], // immunite
                            Attributes[12], // pop_a_risque
                            emplacements)); // localisation


  }
	//load les personnels existants
   	ifstream persoDb;
   	persoDb.open("personnel.tsv"); // FILE MUST BE LF ONLY IF IN WSL!!!!!
   	if (!persoDb){
    	cerr << "Missing personnel.tsv file" << endl;
    	return 1;
   	}

  	string tempPerso;
   	while(getline(persoDb,tempPerso,'\n')) {
    	vector<string> persoAttributes;
    	boost::split(persoAttributes, tempPerso, boost::is_any_of("\t"));
		personnel.push_back(npersonnel(persoAttributes[0],persoAttributes[1],persoAttributes[2],stoi(persoAttributes[3]),persoAttributes[4]));
    }

	//load les localisations existantes
   	ifstream locDb;
   	locDb.open("localisations.tsv"); // FILE MUST BE LF ONLY IF IN WSL!!!!!
   	if (!locDb){
    	cerr << "Missing localisations.tsv file" << endl;
    	return 1;
   	}

  	string tempLoc;
   	while(getline(locDb,tempLoc,'\n')) {
    	vector<string> locAttributes;
    	boost::split(locAttributes, tempLoc, boost::is_any_of("\t"));
		localisations.push_back(nlocalisation(locAttributes[0],locAttributes[1],0));
    }

	//Connection segment
	while(1){
		cout << endl << "Welcome to the storage managment system ! Navigate as asked by the prompt or enter 'x' to return." << endl;
		cout << "Available accounts: " << endl << endl;
		int count = listPersonnels(); //imprime la liste des personnels et retourne sa longueur
		std::string rawInput;
		cout << "Please enter your account's index: ";
		cin >> rawInput;
		if (std::regex_match(rawInput, numericReg)){
			int input = stoi(rawInput);
			if( input >= count || input < 0){
				cout << "\033[2J\033[1;1H"; //clear in WSL, a voir pour autre chose ?
				cout<< "Input is not a valid index."<<endl;			
			}else{
				while(1){
					std::string password;
					cout << "Please enter password for " << personnel[input]->getId() << ": ";
					cin >> password;
					if(password == "x"){
						cout << "\033[2J\033[1;1H";
						break;
					}else if(password.compare(personnel[input]->getPwd()) == 0){
						cout << "\033[2J\033[1;1H";
						personnel[input]->actionMenu(); //afficher le menu
					}else{
						cout << "\033[2J\033[1;1H";
						cout << "wrong password, please retry" << endl;
						break;
					}
					cout << "\033[2J\033[1;1H";
					break;
				}
			}
		}else if(rawInput == "x"){
			exit(0);
		}else{
			cout << "\033[2J\033[1;1H";
			cout << "Wrong input" << endl;
		}
	}
}