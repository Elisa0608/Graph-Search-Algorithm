#include "Graph.h"
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <list>
#include <string>
#include <set>
#include <vector>

namespace Algorithms {
    std::list<std::string> BFS(const Graph& g, const std::string& startNode, const std::string& targetNode = "");
    std::list<std::string> DFS(const Graph& g, const std::string& startNode);
    std::list<std::string> Dijkstra(const Graph& g, const std::string& startNode, const std::string& targetNode);
    void allPaths(const Graph& g, const std::string& curr, const std::string& target, std::set<std::string>& visited, std::vector<std::string>& path);
};

#endif