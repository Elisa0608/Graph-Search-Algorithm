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
    Graph(bool isWeighted = false) : weighted(isWeighted) {}

    void addEdge(const std::string& u, const std::string& v, int weight = 1);
    void readfile(const std::string& filename);
    void printgraph() const;

    std::list<std::string> BFS(const std::string& startNode, const std::string& targetNode = "");
    std::list<std::string> DFS(const std::string& startNode, const std::string& targetNode = "");
    void Dijkstra(const std::string& startNode);

    bool isCyclic();
    bool isConnected();

    std::list<std::string> reconstructPath(const std::string& start, const std::string& target, const std::map<std::string, std::string>& parent);

};


