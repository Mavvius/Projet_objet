
#ifndef __CLASS_AGENT_HPP__
#define __CLASS_AGENT_HPP__

#include "class_agent.hpp"
#include "class_localisation.hpp"
#include "class_Laboratory.hpp"

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


class Agent{
    private:
        // Attributs
        std::string nom;
        int contagion;
        int incubation;
        int group;        
        std::string type;
        std::string reservoir;
        std::string source;
        std::string vecteur;
        std::string transmission;
        std::string diagnostic;
        std::string traitement;
        std::string immunite;
        std::string pop_a_risque;

        //Mapping quantity of agents per localisation  
        std::map<const Localisation*, unsigned int> _quantityPerLocalisation;
        Laboratory& laboratory;

    public:
// Sets        
        void setNom(std::string nom);
        void setContagion(int contagion);
        void setIncubation(int incubation);
        void setGroup(int group);
        void setType(std::string type);
        void setReservoir(std::string reservoir);
        void setSource(std::string source);
        void setVecteur(std::string vecteur);
        void setTransmission(std::string transmission);
        void setDiagnostic(std::string diagnostic);
        void setTraitement(std::string traitement);
        void setImmunite(std::string immunite);
        void setPop_a_risque(std::string pop_a_risque);
// Gets
        std::string getNom();
        int getContagion();
        int getIncubation();
        int getGroup();
        std::string getType();
        std::string getReservoir();
        std::string getSource();
        std::string getVecteur();
        std::string getTransmission();
        std::string getDiagnostic();
        std::string getTraitement();
        std::string getImmunite();
        std::string getPop_a_risque();
        const std::map<const Localisation*, unsigned int>& quantityPerLocalisation();



        void show_loc();

        void set_quantity(const std::string& name, const std::string& type, unsigned int quantity);
        void print();
        Agent(  Laboratory& laboratory,
                std::string nom,
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
                std::string pop_a_risque) : laboratory (laboratory), nom(nom), contagion(contagion),
                incubation(incubation), group(group), type(type), reservoir(reservoir),
                source(source), vecteur(vecteur), transmission(transmission), diagnostic(diagnostic),
                traitement(traitement), immunite(immunite), pop_a_risque(pop_a_risque){}
//---------Methodes---------// 
// méthode pour ajouter une localisation dans la liste des localisations

};

//Agent* nagent(std::string,int,int,int,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::vector<Localisation*>);

//  Agent(Laboratory& laboratory, int a) : a(a), laboratory(laboratory) {}

/*        void ajouterLocalisation(Localisation localisations); 
        // compte le la quantité dans une l
        int qt(string loc);
        void qt(); 
        int totalQt();
*/

//int listAgents();

#endif