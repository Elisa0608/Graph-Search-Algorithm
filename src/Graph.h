#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <map>

struct Edge{
    std::string to;
    int weight;
};

class Graph{
private:
    std::map<std::string, std::vector<Edge>> adjList;
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

