#ifndef __READCSVFILE_H__
#define __READCSVFILE_H__

class Personnel{
  protected:
    // attributs accessibles aux classes filles, class tehniciens et calss ingénieurs
    std::string id; 
    std::string fonction; 
    int effectif; 

  public:
 // le constructeur
   Personnel(std::string id, std::string fonction, int effectif); 

// le getteurs 
    std::string getid(); 
    std::string getfonction(); 
    int geteffectif();
  // les setteurs
    void setid(std::string id); 
    void setfonction(std::string fonction);
    void seteffectif(int effectif); 

// les méthodes 
  std::string deplacer(); 

}; 

#endif