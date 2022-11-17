#ifndef __INGCHERS_H__
#define __INGCHERS_H__
#include "class_personnel.hpp"
#include "class_agent.hpp"
#include <iostream>


class IngChers: public|protected Personnel {
/*Définition de la classe Technicien. Cette classe hérite
       des données publiques et protégées de la classe Personnel     */
  public:
      // Le constructeur 
    IngChers(Personnel); 
    // la méthode prend en paramètre un objet de type agent, la fonction d'un employé et retoune s'il a le droit ou non d'ajouter ou detrouire un agent pathogène
     void detruire( Agent agent); 
      bool existe(Localisation nom); 
      void  creer(Agent agent, int qt, std::string endroit); 
      // Cette méthode permet de recupérer les attributs de la classe Agent; 
      void getValue( Agent *obj); 

}; 


#endif