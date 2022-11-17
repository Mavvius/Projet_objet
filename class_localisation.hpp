#ifndef __CLASS_LOCALISATION_HPP__
#define __CLASS_LOCALISATION_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Localisation{
    private:
      std::string name;
      std::string type;
      int qt;
    public:
      void setName(std::string name);
      void setType(std::string type);
      void setQt(int qt);
      std::string getName();
      std::string getType();
      int get_qt();
      Localisation(std::string name,std::string type,int qt);
};

Localisation* nlocalisation(std::string,std::string,int);
#endif