
#ifndef __CLASS_PERSONNEL_H__
#define __CLASS_PERSONNEL_H__

#include "global.hpp"

class Personnel{
  protected:
    // attributs accessibles aux classes filles, class tehniciens et class ingénieurs
    std::string id; 
    std::string nom;
    std::string fonction;
    bool droit;
    std::string pwd;  
  public:
    // le constructeur
    Personnel(std::string id, std::string nom, std::string fonction, bool droit, std::string pwd); 

    // les geteurs 
    std::string getId();
    std::string getNom();  
    std::string getFonction();
    bool getDroit(); 
    std::string getPwd(); 

    // les setteurs
    void setId(std::string id);
    void setNom(std::string nom); 
    void setDroit(bool droit); 
    void setFonction(std::string fonction);
    void setPwd(std::string pwd);

    virtual void actionMenu();
    virtual void consulter();
}; 

Personnel* npersonnel(std::string,std::string,std::string,bool,std::string);

extern std::vector<Personnel*> personnel;
extern std::regex numericReg;

int listPersonnels();

#endif