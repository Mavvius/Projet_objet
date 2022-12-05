#ifndef __CLASS_LOCALISATION_HPP__
#define __CLASS_LOCALISATION_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Laboratory;

class Localisation{
  friend Laboratory;
    private:
      // _ devant les noms pour eviter les confusion avec le constructeur
      std::string _name;
      std::string _type;

      // constructeur de localisation
      Localisation(const std::string& name, const std::string& type) : _name(name), _type(type) {}

    public:

      // Getter 
      const std::string& name() const ;
      const std::string& type() const ;
      void print();


//      static Localisation& getLocalisation(std::string name,std::string type);
};


//int listpotentialLocalisations();


#endif