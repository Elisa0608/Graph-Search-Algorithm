#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

struct Edge{
    std::string to;
    int weight;
};

class Graph{
private:
    std::map<std::string, std::vector<Edge>> adjList;
    bool weighted;

public:
    //constructorul pentru a seta usor isWeighted
    Graph(bool isWeighted = false);

    void addEdge(const std::string& u, const std::string& v, int weight = 1);
    void readfile(const std::string& filename);
    void printgraph() const;
    
    bool isCyclic();
    bool isConnected();

    void reconstructPath(const std::list<std::string>& path, const std::string& description);

    //getter pt listAdj
    const std::map<std::string, std::vector<Edge>>& getAdjList() const;
};


