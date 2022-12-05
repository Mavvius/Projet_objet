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
        void save_data(std::string file_tsv);
        Laboratory open_agent_tsv(std::string tsv_file);
};

#endif


