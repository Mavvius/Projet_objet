#include <iostream>
#include <vector>
#include "class_ingenieur.hpp"

using namespace std; 

void Ingenieur::actionMenu(){
    while(1){
        cout << "\033[2J\033[1;1H";
        cout << "Connected under id "  << this->getId() << " !" << endl << endl;
        cout << "| 0 |" << "\t" << "Consulter" << "\t" << "|" << endl;
        cout << "| 1 |" << "\t" << "Deplacer" << "\t" << "|" << endl;
        cout << "| 2 |" << "\t" << "Creer" << "\t\t" << "|" << endl;
        cout << "| 3 |" << "\t" << "Detruire" << "\t" << "|" << endl;
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
                    cout << "test2" << endl;
                    break;
            }
        }
    }
}