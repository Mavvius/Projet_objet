// class agent déja incluse  dans le fichier class_personnage.hpp
#include <iostream>
#include <string>
#include <vector>
#include "class_personnel.hpp"
 using namespace  std; 
// class agent déja incluse  dans le fichier class_personnage.hpp
using namespace std; 
void Personnel::setid(string id){
    this->id = id;
}
void Personnel::setfonction(string fonction) {
    this->fonction = fonction; 
      
}

void Personnel::seteffectif(int effectif) {
  this->effectif = effectif; 
}

string Personnel::getid() {
    return id; 
 }
string Personnel::getfonction() {
  return fonction; 
}
int Personnel::geteffectif() {
  return effectif; 
}
 Personnel::Personnel(std::string id, std::string fonction, int effectif){
    this->setid(id); 
    this->setfonction(fonction);
    this->seteffectif(effectif); 
 }


