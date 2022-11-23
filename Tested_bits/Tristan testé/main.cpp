//main.cpp

#include "class_agent.hpp"
#include "class_localisation.hpp"
#include "class_personnel.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{	
	//load les personnels existants
   	ifstream persoDb;
   	persoDb.open("personnel.tsv"); // FILE MUST BE LF ONLY IF IN WSL!!!!!
   	if (!persoDb){
    	cerr << "Missing personnel.tsv file" << endl;
    	return 1;
   	}

  	string tempPerso;
   	vector<Personnel*> personnel;
   	while(getline(persoDb,tempPerso,'\n')) {
    	vector<string> persoAttributes;
    	boost::split(persoAttributes, tempPerso, boost::is_any_of("\t"));
		personnel.push_back(npersonnel(persoAttributes[0],persoAttributes[1],persoAttributes[2],persoAttributes[3]));
    }


	//Connection segment
	while(1){
		int count = 0;
		cout << endl << "Welcome to the storage managment system ! Navigate as asked by the prompt or enter 'x' to return." << endl;
		cout << "Available accounts: " << endl << endl;
		for(auto individu : personnel ){
			cout << "| " << count << " |" << "\t" << individu->getId() << "\t" << individu->getNom() << "\t" << "|" << endl;
			count++;
		}
		std::string rawInput;
		cout << endl << "Please enter your account's index: ";
		cin >> rawInput;
		if(rawInput == "x"){
			exit(0);
		}
		int input = stoi(rawInput);
		if( input > count || input < 0){
			cout << "\033[2J\033[1;1H"; //clear in WSL, a voir pour autre chose ?
			cout<< "Input is not a valid index."<<endl;			
		}else{
			while(1){
				std::string password;
				cout << "Please enter password for " << personnel[input]->getId() << ": ";
				cin >> password;
				if(password == "x"){
					cout << "\033[2J\033[1;1H";
					break;
				}else if(password.compare(personnel[input]->getPwd()) == 0){
					cout << "\033[2J\033[1;1H";
					while(1){
						cout << "Connected under id "  << personnel[input]->getId() << " !" << endl << endl;
						cout << "| 0 |" << "\t" << "Consulter" << "\t" << "|" << endl;
						cout << "| 1 |" << "\t" << "Deplacer" << "\t" << "|" << endl;
						cout << "| 2 |" << "\t" << "Creer" << "\t" << "|" << endl;
						cout << "| 3 |" << "\t" << "Detruire" << "\t" << "|" << endl;
						std::string rawInput;
						cout << endl << "Please enter the wanted action's index: ";
						cin >> rawInput;
						if(rawInput == "x"){
							break;
						}
					}
				}else{
					cout << "\033[2J\033[1;1H";
					cout << "wrong password, please retry" << endl;
				}
				cout << "\033[2J\033[1;1H";
				break;
			}
		}
	}
}