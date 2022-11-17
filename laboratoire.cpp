#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "class_agent.hpp"
#include <boost/algorithm/string.hpp>

using namespace std;

int main() {

  Localisation* loc1 = nlocalisation("test","test",2);
  Localisation* loc2 = nlocalisation("test2","test",3);
  vector<Localisations*> = {loc1,loc2};
  
  Agent* test = nagent("test",1,2,3,"test","test","test","test","test","test","test","test","test","test","test",);
  cout << test->getContagion();


//   //load les agents possibles
//   ifstream agentsDb;
//   agentsDb.open("agents.tsv");
//   if (!agentsDb) {
//       cerr << "Missing AgentsDb file" << endl;
//       return 1;
//   }

//   vector<string> agentsPossibles;
//   string tempAgent;
//   while (getline(agentsDb,tempAgent)) {
//     agentsPossibles.push_back(tempAgent);
//     }

//   //load les loc possibles
//   ifstream locDb;
//   agentsDb.open("localisations.tsv");
//   if (!locDb) {
//       cerr << "Missing loc file" << endl;
//       return 1;
//   }

// // Liste des localisation 
//   vector<string> locPossibles;
//   string tempLoc;
//   while (getline(locDb,tempLoc)) {
//     locPossibles.push_back(tempLoc);
//     }

//   //load le stock
//   ifstream stock;
//   stock.open("stock.tsv");
//   if (!stock) {
//       cerr << "Missing stock file" << endl;
//       return 1;
//   }
  
//   string tempStock;
//   vector<Agent*> agents;
//   while (getline(stock,tempStock)) {
//     vector<string> stockAttributes;
//     vector<string> locNames;
//     vector<string> locQt;
    
//     boost::split(stockAttributes, tempStock, boost::is_any_of("\t"));
    
//     while()
//     agents.push_back(nagent(stoi(attributes[0]), //nom
//                             stoi(attributes[1]), // contagion
//                             stoi(attributes[2]), // incubation
//                             attributes[3], 
//                             attributes[4],
//                             attributes[5],
//                             attributes[6],
//                             attributes[7],
//                             attributes[8],
//                             attributes[9],
//                             attributes[10],
//                             attributes[11]));
  
    }

// std::string nom,
//               int contagion,
//               int incubation,
//               int group,
//               std::string type,
//               std::string reservoir,
//               std::string source,
//               std::string vecteur,
//               std::string transmission,
//               std::string diagnostic,
//               std::string traitement,
//               std::string immunite,
//               std::string pop_a_risque
//               vector<Localisation> localisations)
