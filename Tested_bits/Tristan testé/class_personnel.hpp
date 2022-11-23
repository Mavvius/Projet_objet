#ifndef __CLASS_PERSONNEL_H__
#define __CLASS_PERSONNEL_H__

class Personnel{
  protected:
    // attributs accessibles aux classes filles, class tehniciens et class ingénieurs
    std::string id; 
    std::string nom;
    std::string fonction;
    std::string pwd;  
  public:
    // le constructeur
    Personnel(std::string id, std::string nom, std::string fonction, std::string pwd); 

    // les geteurs 
    std::string getId();
    std::string getNom();  
    std::string getFonction();
    std::string getPwd(); 

    // les setteurs
    void setId(std::string id);
    void setNom(std::string nom); 
    void setFonction(std::string fonction);
    void setPwd(std::string pwd);
}; 

Personnel* npersonnel(std::string,std::string,std::string,std::string);

#endif