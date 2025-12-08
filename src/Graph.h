#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <stack>
#include <queue>

//cream un alias pt WE folosisnd un container ce stocheaza 2 val
//in pair avem ddestinatia si ponderea
using WeightedEdge = std::pair<int, int>;

class Graph{
private:
    int nodes;
    //vectorul de liste
    std::vector<std::list<WeightedEdge>> adj;
    //primeste un nod, starea visited si calea curenta
    void DFSutil(int nodes, std::vector<bool>& visited, std::list<int>&path);
    //primeste un nod, starea visited si stiva de recursivitate
    bool isCyclicUtil(int nodes, std::vector<bool>& visited, std::vector<bool>& recursionStack);
public:
    Graph(int nodes);

    void addEdge(int u, int v, int weight = 1);
    void readfile(std::string& filename);
    void printgraph();
    std::list<int> BFS(int startNode, int targetNode = -1);
    std::list<int> DFS(int startNode, int targetNode = -1);
    void Dijkstra(int startNode);
    bool isCyclic();
    bool isConnected();
    std::list<int> reconstructPath(int start, int target, const std::vector<int>& parent);
    void exportPath(const std::list<int>& path, const std::string& description);

};

