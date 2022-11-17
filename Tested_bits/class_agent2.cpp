#include "class_agent.hpp"
#include "class_localisation.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
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

//constructor
Agent::Agent(   std::string nom,
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

//instanciation
Agent* nagent(std::string nom,
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
};

// --------- Methods ---------//
//void qt() {}; // format tableau
int qt(string loc){
  vector <string> v = this localisations;
  match = find(v.begin(, v.end(), loc));
  
  if (match != v.end()){
   // there is a match
    auto index = distance(v.begin(), match)
    return v[index].qt
  } else {
    cout << "There is no sample in this localisation ";
  };
  //localisation.get_qt();
};

void qt(){
  vector<string> v = this localisation;
  	for(auto localisation : v){
		cout << localisation.name << "|\t" << localisation.qt << "|\t" << localisation.type << "\n";
	}
};
// ajouter une localisation dans la liste des localisations
void Agent::ajouterLocalisation(Localisation localisations) {
     getLocalisations().push_back(localisations); 
    
  }
