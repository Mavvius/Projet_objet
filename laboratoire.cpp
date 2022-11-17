#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "class_agent.hpp"
#include <boost/algorithm/string.hpp>

using namespace std;

int main() {
    
    ifstream agentsFile;
    agentsFile.open("agents.tsv");
    if (!agentsFile) {
        cerr << "Missing agent file" << endl;
        return 1;
    }

    vector<Agent*> agents;
    string tempAgent;
    while (getline(agentsFile,tempAgent)) {
        vector<string> attributes;
        cout << tempAgent;
        boost::split(attributes, tempAgent, boost::is_any_of("\t"));
        agents.push_back(nagent(    stoi(attributes[0]),
                                    stoi(attributes[1]),
                                    stoi(attributes[2]),
                                    attributes[3],
                                    attributes[4],
                                    attributes[5],
                                    attributes[6],
                                    attributes[7],
                                    attributes[8],
                                    attributes[9],
                                    attributes[10],
                                    attributes[11]));   
    }
  cout << "test";
}
