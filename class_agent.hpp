
#ifndef __CLASS_AGENT_HPP__
#define __CLASS_AGENT_HPP__


class Agent{
    private:
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

    public:
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

        Agent(  int contagion,
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
                std::string pop_a_risque);
};

Agent* nagent(int,int,int,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string,std::string);

#endif