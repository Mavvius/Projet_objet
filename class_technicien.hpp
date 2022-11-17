#ifndef __TECHNICIENS_H__
#define __TECHNICIENS_H__
#include "class_personnel.hpp"
#include "class_agent.hpp"

class Technicien: public Personnel {
/*Définition de la classe Technicien. Cette classe hérite
       des données publiques et protégées de la classe Personnel     */
  public:
      // Le constructeur 
    Technicien(); 
    // la méthode prend en paramètre un objet de type agent, la fonction d'un employé et retoune s'il a le droit ou non d'ajouter ou detrouire un agent pathogène
     bool droits(); 
}; 


#endif
