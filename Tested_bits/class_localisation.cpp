#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "class_localisation.hpp"

using namespace std;

void Localisation::setName(std::string name){
    this->name = name;
};

void Localisation::setType(std::string type){
    this->type = type;
};

void Localisation::setQt(int qt){
    this->qt = qt;
};

std::string Localisation::getName(){
    return name;
};

std::string Localisation::getType(){
    return type;
};

int Localisation::getQt(){
    return qt;
};

Localisation::Localisation(std::string name, std::string type, int qt){
  this->setName(name);
  this->setType(type);
  this->setQt(qt);
}

Localisation* nlocalisation(std::string name,std::string type,int qt){
  return new Localisation(name,type,qt); 
}