#include "Graph.h"
#include <fstream>
#include <set>
#include <stack>
#include <sstream>

using std::ifstream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;

Graph::Graph(bool isWeighted) : weighted(isWeighted){}

void Graph::addEdge(const std::string& u, const std::string& v, int weight){
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});
}

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

                size_t colon_position = remaining.find(':');
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
    cout << "Succesfully read the graph from the file: " << filename << endl;
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

const std::map<std::string, std::vector<Edge>>& Graph::getAdjList() const {
    return adjList;
}

void Graph::reconstructPath(const std::list<std::string>& path, const std::string& description){
    std::cout << "Path reconstruction for: " << description << endl;

    if (path.empty()){
        std::cout << "No valid path was found" << std::endl;
        return;
    }

    int totalCost = 0;
    auto it = path.begin();
    
    // Afisam primul nod
    std::cout << *it;

    while (std::next(it) != path.end()){
        std::string u = *it;
        std::string v = *std::next(it);
    
        int currentWeight = 0;
        if (adjList.count(u)) {
            for (const auto& edge : adjList.at(u)) {
                if (edge.to == v) {
                    currentWeight = edge.weight;
                    break;
                }
            }
        }
        totalCost += currentWeight;

        std::cout << " -> " << v;
        ++it;
    }
    std::cout << std::endl;

    if (weighted) {
        std::cout << "Total Cost (Weight): " << totalCost << std::endl << std::endl;
    } else {
        std::cout << "Distance: " << (path.size() - 1) << " hops" << std::endl << std::endl;
    }
}

bool Graph::isConnected(){
    std::set<std::string> visited;
    std::stack<std::string> s;

    if (adjList.empty()) return true;

    std::string startNode = adjList.begin()->first;

    s.push(startNode);
    while(!s.empty()){
        std::string curr = s.top();
        s.pop();

        if (visited.find(curr) == visited.end()) {
            visited.insert(curr);
            for (const auto& edge : adjList.at(curr)) {
                if (visited.find(edge.to) == visited.end()) {
                    s.push(edge.to);
                }
            }
        }
    }
    if (visited.size() == adjList.size()) return true;
    else return false;
}

bool Graph::isCyclic(){
    std::set<std::string> visited;

    for (auto const& [node, neighbors] : adjList){
        if (visited.find(node) == visited.end()){
            //cream un stack cu perechile de nod curent si nod parinte
            std::stack<std::pair<std::string, std::string>> s;
            s.push({node, ""});
            visited.insert(node);

            while (!s.empty()){
                auto [curr, parent] = s.top();
                s.pop();

                for (const auto& edge : adjList.at(curr)) {
                    if (edge.to != parent) { 
                        if (visited.find(edge.to) != visited.end()){
                            return true;
                        }
                        visited.insert(edge.to);
                        s.push({edge.to, curr});
                    }
                }
            }
        }
    }
    return false;
}