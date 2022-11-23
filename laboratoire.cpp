//main.cpp

#include "class_agent.hpp"
#include "class_localisation.hpp"
#include <iostream>
#include <fstream> // Pour l'ouverture de fichiers
#include <string> // Pour la lecture de string plutot que char*
#include <vector> 
#include <algorithm> // Pour utiliser boost et les iterateurs sur vecteur
#include <typeinfo> // pour tester sur les types
#include <boost/algorithm/string.hpp> 
#include <boost/range/algorithm/count.hpp> // Pour compter les items dans une string

using namespace std;


int main(int argc, char const *argv[])
{	

  	Localisation* loc1 = nlocalisation("frigo","armoire",2);
  	Localisation* loc2 = nlocalisation("centri","equipe",3);
  	vector<Localisation*> nantes {loc1,loc2};
	Agent* lapin = nagent("nom",1,2,3,"type","reservoir",
						"source","vecteur","transmission","diagnostic",
						"treatment","immunité","pop_a_risque", nantes);

//	cout << lapin->getLocalisations()[0]->getQt() <<"\n" ;

//	lapin->qt();
	cout << "Lapin dans le frigo :" << lapin->qt("frigo") << "\n";
	cout << "----------------------\n";


	ifstream file_agents;
  	file_agents.open("Fichier_Agents.tsv");
  	if (!file_agents) {
      cerr << "Missing AgentsDb file" << endl;
      return 1;
  	}
  string temp_agents;
  string temp_loc;
  vector<Agent*> vect_agents; // Vecteur où on range les différents agents
  getline(file_agents, temp_agents); // skip the first line
  while (getline(file_agents, temp_agents)) {
    vector<string> Attributes; // Vecteur où vont être stockées les cellules du tableau *.tsv
    vector<Localisation*> emplacements; // Initialisation d'un vecteur de localisation pour instancier les agents
    boost::algorithm::split(Attributes, temp_agents, boost::is_any_of("\t")); // lecture du tsv par \t separateur
		cout << "\n Organisme :" << Attributes[0] << "\n";
		//cout << "  vigule " <<Attributes[13].find(";") <<  "\n";    
		string locs = Attributes[13];
		int cnt = boost::count(locs, ';');
//		cout << "nb vir : " << cnt << "\n";
		auto start = 0U;
    auto end = locs.find(";");
    // Sert a découper les localisations séparées par des ";"
    for (int i = 0; i < cnt+1; ++i)
    {
  //      cout << locs.substr(start, end - start) << std::endl;
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
	vect_agents.push_back(nagent((string)Attributes[0], //nom
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
  // Fonctionne mais n'entre aucune valeur pour les Noms
  for (auto agent : vect_agents){
  	cout << agent->getVecteur() <<" \n";
  }
	return 0;
}


/*while (getline(stock,tempStock)) {
		//separer le nom de l'agent de ses localisations
		vector<string> stockAttributes;
		boost::split(stockAttributes, tempStock, boost::is_any_of("\t"));
		//separer chaque loc
		vector<string> locInstances;
		boost::split(locInstances, stockAttributes[2], boost::is_any_of(";"));
		
		vector<Localisations*> trueLocInstances;
		//pour chaque loc
		for (auto instance : locInstances) {
			//separer le nom de la quantité
			vector<string> tempLocInstance;
			boost::split(tempLocInstance, instance, boost::is_any_of(","));
			//instancier la loc depuis son template et l'append au vector de loc de l'agent
			for (auto template : locAvailable) {
				if (template->getName() == tempLocInstance[1]){ // cherche un match de nom
					trueLocInstances.pushback()
				}
			}
		}
}*/