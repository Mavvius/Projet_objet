#include "class_agent.hpp"
#include "class_localisation.hpp"
#include "class_Laboratory.hpp"

#include <cassert>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

//--------- Get and Set ---------// 
void Agent::setNom(std::string nom){
    this->nom = nom;
};
void Agent::setContagion(int contagion){
    this->contagion = contagion;
};
void Agent::setIncubation(int incubation){
    this->incubation = incubation;
};
void Agent::setGroup(int group){
    this->group = group;
};
void Agent::setType(std::string type){
    this->type = type;
}; 
void Agent::setReservoir(std::string reservoir){
    this->reservoir = reservoir;
}; 
void Agent::setSource(std::string source){
    this->source = source;
}; 
void Agent::setVecteur(std::string vecteur){
    this->vecteur = vecteur;
}; 
void Agent::setTransmission(std::string transmission){
    this->transmission = transmission;
}; 
void Agent::setDiagnostic(std::string diagnostic){
    this->diagnostic = diagnostic;
}; 
void Agent::setTraitement(std::string traitement){
    this->traitement = traitement;
}; 
void Agent::setImmunite(std::string immunite){
    this->immunite = immunite;
}; 
void Agent::setPop_a_risque(std::string pop_a_risque){
    this->pop_a_risque = pop_a_risque;
};




std::string Agent::getNom(){
    return nom;
};

int Agent::getContagion(){
    return contagion;
};
int Agent::getIncubation(){
    return incubation;
};
int Agent::getGroup(){
    return group;
};
std::string Agent::getType(){
    return type;
}; 
std::string Agent::getReservoir(){
    return reservoir;
}; 
std::string Agent::getSource(){
    return source;
}; 
std::string Agent::getVecteur(){
    return vecteur;
}; 
std::string Agent::getTransmission(){
    return transmission;
}; 
std::string Agent::getDiagnostic(){
    return diagnostic;
}; 
std::string Agent::getTraitement(){
    return traitement;
}; 
std::string Agent::getImmunite(){
    return immunite;
}; 
std::string Agent::getPop_a_risque(){
    return pop_a_risque;
};

void Agent::set_quantity(const std::string& name, const std::string& type, unsigned int quantity) {
    quantityPerLocalisation[&laboratory.getLocalisation(name, type)] = quantity;
};

void Agent::print() {
            for (const auto& [localisation, quantity] : quantityPerLocalisation) {
                assert(localisation != nullptr);
                std::cout << "Agent "
                          << this->nom
                          << " as "
                          << quantity
                          << " in "
                          << localisation->name()
                          << "/" << localisation->type()
                          << " ("
                          << localisation
                          << ")\n";
            }
        };


//constructor
/*Agent::Agent(   std::string nom,
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
                std::string pop_a_risque,
                std::vector<Localisation*> localisations){
                    this->setNom(nom);
                    this->setContagion(contagion);
                    this->setIncubation(incubation);
                    this->setGroup(group);
                    this->setType(type);
                    this->setReservoir(reservoir);
                    this->setSource(source);
                    this->setVecteur(vecteur);
                    this->setTransmission(transmission);
                    this->setDiagnostic(diagnostic);
                    this->setTraitement(traitement);
                    this->setImmunite(immunite);
                    this->setPop_a_risque(pop_a_risque);
                    this->setLocalisations(localisations);
};
*/
//instanciation
/*Agent* nagent(std::string nom,
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
              std::string pop_a_risque,
              vector<Localisation*> localisations){
return new Agent(nom,contagion,incubation,group,type,reservoir,source,vecteur,transmission,diagnostic,traitement,immunite,pop_a_risque,localisations);
};*/



// --------- Methods ---------//

/*int Agent::qt(std::string loc){ // Fonction a améliorer, en utilisant un iterateur pour le match. 
// parcourt le vecteur de localisation 
    std::vector<Localisation*> v = this->localisations;

    for(auto localisation : v){
       if (localisation->getName() == loc) { // cherche un match de nom
        return localisation->getQt();  // S'il trouve renvoit la quantité a l'emplacement donné
        }else{
            cout << "No match for the this localisation";
        }
    }
    return 0;
};*/

/*void Agent::qt(){
    std::vector<Localisation*> v = this->localisations;
    cout <<"\n";
  	for(auto localisation : v){
       cout << localisation->getName() << "|\t" << localisation->getType() << "|" << localisation->getQt() << "\n";
      
    }
};*/

/*int Agent::totalQt(){
    int sum = 0;
    std::vector<Localisation*> v = this->localisations;
  	for(auto localisation : v){
       sum = sum + localisation->getQt(); 
    }
    return(sum);
};
*/
/*int listAgents(){
	int count = 0;
    cout << left << setw(6) << setfill(' ') << "";
    cout << left << setw(10) << setfill(' ') << "Nom";
    cout << left << setw(15) << setfill(' ') << "Quantité totale" << endl;
	for(auto agent : vect_agents ){
        cout << "| " << count << " | ";
		cout << left << setw(10) << setfill(' ') << agent->getNom();
        cout << left << setw(15) << setfill(' ') << agent->totalQt() << " |" << endl;
		count++;
	}
    cout << endl;
	return(count);
}*/