// class agent déja incluse  dans le fichier class_personnage.hpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "class_ingenieur.hpp"
#include "class_personnel.hpp"
#include "class_agent.hpp"

using namespace  std; 

void Personnel::setId(string id){
    this->id = id;
}

void Personnel::setNom(string nom) {
    this->nom = nom;      
}

void Personnel::setFonction(string fonction) {
    this->fonction = fonction;    
}

void Personnel::setDroit(bool droit) {
    this->droit = droit;    
}

void Personnel::setPwd(string pwd) {
    this->pwd = pwd;    
}

string Personnel::getId() {
    return id; 
}

string Personnel::getNom() {
    return nom; 
}

string Personnel::getFonction() {
  return fonction; 
}

bool Personnel::getDroit() {
  return droit; 
}

string Personnel::getPwd() {
  return pwd; 
}

Personnel::Personnel(std::string id, std::string nom, std::string fonction, bool droit, std::string pwd){
    this->setId(id); 
    this->setNom(nom);
    this->setFonction(fonction);
    this->setDroit(droit);
    this->setPwd(pwd);
}

Personnel* npersonnel(std::string id,std::string nom,std::string fonction,bool droit,std::string pwd){
    if(droit){
        return new Ingenieur(id,nom,fonction,droit,pwd); 
    }else{
        return new Personnel(id,nom,fonction,droit,pwd);
    }
}

void Personnel::actionMenu(){
    while(1){
        cout << "\033[2J\033[1;1H";
        cout << "Connected under id "  << this->getId() << " !" << endl << endl;
        cout << "| 0 |" << "\t" << "Consulter" << "\t" << "|" << endl;
        cout << "| 1 |" << "\t" << "Deplacer" << "\t" << "|" << endl;
        std::string rawInput;
        cout << endl << "Please enter the wanted action's index: ";
        cin >> rawInput;
        if(rawInput == "x"){
            break;
        }else if(stoi(rawInput) < 0 || stoi(rawInput) > 1){
            cout << "Wrong input" << endl;
        }else{
            switch(stoi(rawInput)) {
                case 0:
                    this->consulter();
                    break;
                case 1:
                    cout << "lol2" << endl;
                    break;
            }
        }
    }
}

void Personnel::consulter(){
    cout << "\033[2J\033[1;1H";
    while(1){
        cout << "Connected under id "  << this->getId() << " !" << endl << endl;
        cout << "| 0 |" << "\t" << "Agents" << "\t\t" << "|" << endl;
        cout << "| 1 |" << "\t" << "Personnels" << "\t" << "|" << endl;
        cout << "| 2 |" << "\t" << "Localisations" << "\t" << "|" << endl;
        std::string rawInput;
        cout << endl << "Please enter the wanted database's index: ";
        cin >> rawInput;
        if (std::regex_match(rawInput, numericReg)){
		    int input = stoi(rawInput);
            if(stoi(rawInput) < 0 || stoi(rawInput) > 2){
                cout << "\033[2J\033[1;1H";
                cout << "Wrong input" << endl;
            }else{
                switch(stoi(rawInput)) {
                    case 0:
                        cout << "\033[2J\033[1;1H";
                        listAgents();
                        cout << "Enter any key to return: ";
                        cin >> rawInput;
                        cout << "\033[2J\033[1;1H";
                        break;
                    case 1:
                        cout << "\033[2J\033[1;1H";
                        listPersonnels();
                        cout << "Enter any key to return: ";
                        cin >> rawInput;
                        cout << "\033[2J\033[1;1H";
                        break;
                    case 2:
                        cout << "\033[2J\033[1;1H";
                        listpotentialLocalisations();
                        cout << "Enter any key to return: ";
                        cin >> rawInput;
                        cout << "\033[2J\033[1;1H";
                        break;
                }
            }
        }else if(rawInput == "x"){
            break;
        }else{
            cout << "Wrong input" << endl;
        }
            
    }
}    


int listPersonnels(){
    int count = 0;
    cout << left << setw(6) << setfill(' ') << "";
    cout << left << setw(10) << setfill(' ') << "Id";
    cout << left << setw(10) << setfill(' ') << "Nom";
    cout << left << setw(20) << setfill(' ') << "Fonction" << endl;
	for(auto individu : personnel ){
        cout << "| " << count << " | ";
        cout << left << setw(10) << setfill(' ') << individu->getId();
		cout << left << setw(10) << setfill(' ') << individu->getNom();
        cout << left << setw(20) << setfill(' ') << individu->getFonction() << " |" << endl;
		count++;
	}
    cout << endl;
	return(count);
}