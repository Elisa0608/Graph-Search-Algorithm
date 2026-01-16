#include "Graph.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;

void Graph::readfile(const string& filename){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Error: Couldn't open the file " << filename << endl;
        return; 
    }

    string line;
    while(std::getline(file, line)){
        //folosim ss ca sa putem citi caracter cu caracter mai tarziu
        stringstream ss(line);
        string edgeToken;

        //spargem in caractere si le tinem temporar in edgeToken
        while ((ss >> edgeToken)){
            size_t dash_position = edgeToken.find('-');

            if (dash_position != string::npos){
                string u = edgeToken.substr(0, dash_position);
                string remaining = edgeToken.substr(dash_position + 1);
                //il numim remaining si nu v pt ca inca nu stim daca dupa dash avem pondere
                // sau avem nodul to

                size_t colon_position = edgeToken.find(':');
                if (colon_position != string::npos){
                    //ex A-B:5
                    string v = remaining.substr(0, colon_position);
                    int weight = std::stoi(remaining.substr(colon_position + 1));
                    //acum ca avem toate elementele putem adauga edge
                    addEdge(u, v, weight);
                }else{
                    addEdge(u, remaining, 1);
                    //cazul unui graf neponderat
                }
            }
        }
    }
    file.close();
    cout << "Succesfuly read the graph from the file: " << filename << endl;
}

void Graph::printgraph() const {
    for (const auto& [node, neighbors] : adjList){
        std::cout << node << " -> [";

        for (size_t i = 0; i < neighbors.size(); ++i){
            std::cout << neighbors[i].to;

            if (weighted){
                std::cout << ":" << neighbors[i].weight;
            }
            //punem virgula doar daca nu suntem la ultimul vecin
            if (i < neighbors.size() - 1){
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

