// class agent déja incluse  dans le fichier class_personnage.hpp
#include <iostream>
#include <string>
#include <vector>
#include "class_personnel.hpp"

using namespace  std; 

void Personnel::setId(string id){
    this->id = id;
}

void Personnel::setNom(string nom) {
    this->nom = nom; 
      
}

void Personnel::setFonction(string fonction) {
    this->fonction = fonction;    
}

void Personnel::setPwd(string pwd) {
    this->pwd = pwd;    
}

string Personnel::getId() {
    return id; 
}

string Personnel::getNom() {
    return nom; 
}

string Personnel::getFonction() {
  return fonction; 
}

string Personnel::getPwd() {
  return pwd; 
}

Personnel::Personnel(std::string id, std::string nom, std::string fonction, std::string pwd){
    this->setId(id); 
    this->setNom(nom);
    this->setFonction(fonction);
    this->setPwd(pwd);
}

Personnel* npersonnel(std::string id,std::string nom,std::string fonction,std::string pwd){
  return new Personnel(id,nom,fonction,pwd); 
}


