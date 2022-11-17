#include <iostream>
#include <vector>
#include "class_ingChers.hpp"
using namespace std; 
 // méthodes qui verifie si une localisation existe
bool  IngChers::existe(std::string nom) {
  // on retourne vrai si la localisation existe 
      return (Localisation.getName() == nom)
  
  
}
// méthode permettant de créer un nouvel agent
void IngChers::creer(Agent agent, int qt, std::string localisation) {
  // le vector qui contient la liste des localisation
   if(IngChers::existe(localisation)) {
     agent.creer(agent);
     // on doit ajouter l'agent dans la liste des agents 
     // La méthode ajout doit être  declarée et definie dans la classe agent
     agent.ajout(agent); 
   }
  // le nom de la localisation n'existe pas dans la liste des localisations donc il faudra  l'ajouter dans la liste des localisations
  agent.ajouter(std::string localisation, std::string type, int quantite); 
}

// méthode permettant de détruire un  strock d'agent, c'est à dire le ramener  à 0 la quantité  présente dans toutes les localisations d'un agent
void  IngChers::detruire( Agent agent) {
      // appeler la méthode detruire présente dans la classe d'agent
      agent.detruire(agent); 
   // après il faudra enlèver cet agent dans la liste des agents; 
}
