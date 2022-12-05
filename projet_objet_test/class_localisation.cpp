#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "class_localisation.hpp"


// Getter
const std::string& Localisation::name() const { return _name; };
const std::string& Localisation::type() const { return _type; };

void Localisation::print() {
    std::cout << "Localisation "
                  << _name
                  << "/"
                  << _type
                  << " ("
                  << this
                  << ")\n";
        }




/*Localisation& getLocalisation(std::string name,std::string type) {
    for (auto& localisation : localisations) {
        if ((localisation->name == name) && (localisation->getType() == type)) {
            return *localisation.get();
        }
    }
    return localisations.emplace_back(std::make_unique<Localisation>(name, type));
}
*/





























/*void Localisation::setName(std::string name){
    this->name = name;
};

void Localisation::setType(std::string type){
    this->type = type;
};

void Localisation::setQt(int qt){
    this->qt = qt;
};

std::string Localisation::getName(){
    return name;
};

std::string Localisation::getType(){
    return type;
};

int Localisation::getQt(){
    return qt;
};*/


/*int listpotentialLocalisations(){
    int count = 0;
    cout << left << setw(6) << setfill(' ') << "";
    cout << left << setw(20) << setfill(' ') << "Nom";
    cout << left << setw(20) << setfill(' ') << "Type" << endl;
	for(auto localisation : localisations ){
        cout << "| " << count << " | ";
        cout << left << setw(20) << setfill(' ') << localisation->getName();
		cout << left << setw(20) << setfill(' ') << localisation->getType() << " |" << endl;
		count++;
	}
    cout << endl;
	return(count);
}*/