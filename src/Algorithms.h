#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <list>
#include <string>

namespace Algorithms {
    std::list<std::string> BFS(const std::string& startNode, const std::string& targetNode = "");
    std::list<std::string> DFS(const std::string& startNode, const std::string& targetNode = "");

};

#endif