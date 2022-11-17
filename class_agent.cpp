#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "class_agent.hpp"

using namespace std;

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
Agent::Agent(   int contagion,
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
                std::string pop_a_risque){
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
};

//instanciation
Agent* nagent(  
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
            std::string pop_a_risque){
return new Agent(contagion,incubation,group,type,reservoir,source,vecteur,transmission,diagnostic,traitement,immunite,pop_a_risque);
};



