#include "Algorithms.h"
#include "Graph.h"
#include <queue>
#include <map>
#include <algorithm>

std::list<std::string> Algorithms::BFS(const Graph& g, const std::string& startNode, const std::string& targetNode){
    std::queue<std::string> q;
    std::map<std::string, bool> visited;
    std::map<std::string, std::string> parent;
    std::list<std::string> path;

    const auto& adjList = g.getAdjList();

    if (adjList.count(startNode) == 0){
        std::cout << "Error: seems like " << startNode << "does not exist" << std::endl;
        return path;
    }

    

    
}

// implementare viitoare