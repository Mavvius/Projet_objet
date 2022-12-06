//lab hpp
#ifndef __CLASS_LABORATORY_HPP__
#define __CLASS_LABORATORY_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <list>

#include "class_localisation.hpp"
#include "class_agent.hpp"

class Agent;
class Localisation;


class Laboratory {

    private:
        std::list<Localisation> localisations; // Liste de toutes les localisations instanciées
        std::list<Agent> agents;

    public:
        const Localisation& getLocalisation(const std::string& name, const std::string& type);

        void print();

        void load();

        void localisations_to_agents(Agent& agent ,std::string localisations_cell);
        void print_agent(const std::string name);

        void show_agent_loc(const std::string name);
        
        Agent& find_agent(const std::string name);
        void fill_loc_per_agent(Agent& agent);



// Creer un nouvel agent pathogène
        void add_agent(std::string nom,
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
                std::string pop_a_risque, std::string localisations);

// Fonctions d'ouverture et de sauvegarde de la DB
        void open_agent_tsv(std::string tsv_file);
        void save_data(std::string name_tsv);
       

};

#endif
