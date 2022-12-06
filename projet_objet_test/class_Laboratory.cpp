// class_Laboratory.cpp

#include "class_localisation.hpp"
#include "class_agent.hpp"
#include "class_Laboratory.hpp"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <list>
#include <boost/algorithm/string.hpp> 
#include <boost/range/algorithm/count.hpp> 




// Le but de cette classe est de servir d'organisateur pour alleger le main


const Localisation& Laboratory::getLocalisation(const std::string& name, const std::string& type) {
    for (auto& localisation : localisations) {
        if ((localisation.name() == name) and (localisation.type() == type)) {
            std::cout << "Existing localisation: "
                        << localisation.name()
                        << "/" << localisation.type()
                        << " ("
                        << &localisation
                        << ")\n";
            return localisation;
        }
    }
    std::cout << "Creating localisation: " << name << "/" << type << "\n";
    return localisations.emplace_back(Localisation(name, type));
}



void Laboratory::print() {
    std::cout << "\n"
              << "Localisations\n"
              << "=============\n";
    for (auto& localisation : localisations) {
        localisation.print();
    }
    std::cout << "\n"
              << "Agents\n"
              << "======\n";
    for (auto& agent : agents) {
        agent.print();
    }
}

void Laboratory::load(){
    auto& agent = agents.emplace_back(*this, "Nom", 4, 3, 1, "type", "reservoir", "source", "vecteur", " transmission", "diagnostic","traitement", "immunité", "Pop_a_risque");
    agent.set_quantity("Frigo", "Stock", 12);
    agent.set_quantity("Frigo", "Stock", 6);
    agent.set_quantity("Pipette", "Tool", 2);
};


/////////////////////////////////////////////////////////////
 // Instanciation du laboratoire
  
void Laboratory::open_agent_tsv(std::string tsv_file){
  
  std::ifstream file_agents;
    file_agents.open(tsv_file);
    if (!file_agents) {
      std::cerr << "Missing AgentsDb file" << std::endl;
    }

  std::string temp_agents;
  std::string temp_loc;
  
  getline(file_agents, temp_agents); // skip the first line
  while (getline(file_agents, temp_agents)) {
    std::vector<std::string> Attributes; // Vecteur où vont être stockées les cellules du tableau *.tsv
 //   std::vector<Localisation*> emplacements; // Initialisation d'un vecteur de localisation pour instancier les agents
    
    boost::algorithm::split(Attributes, temp_agents, boost::is_any_of("\t")); // lecture du tsv par \t separateur
    
    // initialisation des agents dans la liste d'agents du laboratoire. 
    Agent& agent = agents.emplace_back(*this, // laboratory
                            (std::string)Attributes[0], //nom
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
                            Attributes[12]); // pop_a_risque


    localisations_to_agents(agent ,Attributes[13]);
  }
}


///////////////////////////////////////////////////////////////////////////////
void Laboratory::localisations_to_agents(Agent& agent ,std::string localisations_cell){
    std::string locs = localisations_cell;
    int cnt = boost::count(locs, ';');
    auto start = 0U;
    auto end = locs.find(";");

    // Sert a découper les localisations séparées par des ";"
    for (int i = 0; i < cnt+1; ++i)
    {
        std::string locat = locs.substr(start, end - start);
        auto deb = 0U;
        auto fin = locat.find(",");
        std::vector<std::string> temp_emplacement;

      // Découpe une localisation pour différencier ses 3 attributs Nom type et quantité
        for (int i = 0; i < 3; ++i)
        {
          temp_emplacement.push_back(locat.substr(deb, fin - deb)); // stocke la localisation dans un vecteur temporaire
 
          deb = fin + 1; // parce que la longueur du char est de 1.
          fin = locat.find(",", deb);
        }


        // Instanciation du vecteur de localisation qui sera utiliser pour instancier l'Agent pathogène
       agent.set_quantity(temp_emplacement[0], temp_emplacement[1], stoi(temp_emplacement[2]));

        start = end + 1;
        end = locs.find(";", start);
    }

}

///////////////////////////////////////////////////////////////////////////////
// fonction qui trouve un agent dans la liste des agents
void Laboratory::print_agent(const std::string name){
        for (auto& agent : agents) {
            if (agent.getNom() == name) {
                agent.print();
            }  
            
    }
}

Agent& Laboratory::find_agent(const std::string name){ 
        for (auto& agent : agents) {
            if (agent.getNom() == name) {
                return agent;
            }
    }
    throw std::invalid_argument("Agent " + name + " should exists");
}




void Laboratory::add_agent(std::string nom,
                int contagion,
                int incubation,
                int group,
                std::string type,
                std::string reservoir,
                std::string source,
                std::string vecteur,
                std::string transmission,
                std::string diagnostic,
                std::string traitement,
                std::string immunite,
                std::string pop_a_risque, std::string localisations){

    Agent& agent = agents.emplace_back(*this, // laboratory
                            nom, contagion, incubation,
                            group, type, reservoir,
                            source, vecteur, transmission,
                            diagnostic, traitement,immunite,
                            pop_a_risque);

    localisations_to_agents(agent ,localisations);

}



/*
void Laboratory::print(Agent& agent){
    std::cout << agent.print();
}*/

void Laboratory::show_agent_loc(const std::string name){
    auto& agent = find_agent(name);
    agent.show_loc();
};



void Laboratory::save_data(std::string name_tsv){
std::ofstream myFile(name_tsv);
// Le header du fichier
myFile << "Nom\tint_contagion\tint_incubation\tint_group\ttype_org\tReservoir\tSource\tVecteur\tTransmission\tDiagnostic\tTraitement\tImmunité\tPop_a_risque\tLocalisations\n";  

    // Send data to the stream
  for (auto& agent : agents){
    myFile << agent.getNom() <<" \t";
    myFile << agent.getContagion() <<" \t";
    myFile << agent.getIncubation() <<" \t";
    myFile << agent.getGroup() <<" \t";
    myFile << agent.getType() <<" \t";
    myFile << agent.getReservoir() <<" \t";
    myFile << agent.getSource() <<" \t";
    myFile << agent.getVecteur() <<" \t";
    myFile << agent.getTransmission() <<" \t";
    myFile << agent.getDiagnostic() <<" \t";
    myFile << agent.getTraitement() <<" \t";
    myFile << agent.getImmunite() <<" \t";
    myFile << agent.getPop_a_risque() <<" \t";
    
    for(const auto& loc : agent.quantityPerLocalisation()){
        myFile << loc.first->name() << ",";
        myFile << loc.first->type() << ",";
        myFile << loc.second << ";";
    }
    myFile << "\n";
  }

// Close the file
myFile.close();

};



/*    std::string locs = Attributes[13];
    int cnt = boost::count(locs, ';');
    auto start = 0U;
    auto end = locs.find(";");

    // Sert a découper les localisations séparées par des ";"
    for (int i = 0; i < cnt+1; ++i)
    {
        std::string locat = locs.substr(start, end - start);
        auto deb = 0U;
        auto fin = locat.find(",");
        std::vector<std::string> temp_emplacement;

      // Découpe une localisation pour différencier ses 3 attributs Nom type et quantité
        for (int i = 0; i < 3; ++i)
        {
          temp_emplacement.push_back(locat.substr(deb, fin - deb)); // stocke la localisation dans un vecteur temporaire
 
          deb = fin + 1; // parce que la longueur du char est de 1.
          fin = locat.find(",", deb);
        }


        // Instanciation du vecteur de localisation qui sera utiliser pour instancier l'Agent pathogène
       // emplacements.push_back(nlocalisation(temp_emplacement[0], temp_emplacement[1], stoi(temp_emplacement[2])));

        start = end + 1;
        end = locs.find(";", start);
    }
*/
