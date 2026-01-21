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
    bool found = false;

    const auto& adjList = g.getAdjList();

    if (adjList.count(startNode) == 0){
        std::cout << "Error: it seems like " << startNode << "does not exist" << std::endl;
        return path;
    }

    q.push(startNode);
    visited[startNode] = true;
    
    while(!q.empty()){
        std::string u = q.front();
        q.pop();
        if (u == targetNode){
            found = true;
            break;
        }

        //aici practic numaram de cate ori apare u in adjList, adica luam vecinii lui u
        if (adjList.count(u)){
            for (const auto& edge : adjList.at(u)){
                if (!visited[edge.to]){
                    visited[edge.to] = true;
                    parent[edge.to] = u;
                    q.push(edge.to);
                }
            }
        }
    }

    if (found) {
        std::string curr = targetNode;
        while ( curr != startNode){
            path.push_front(curr);
            curr = parent[curr];
        }
        path.push_front(startNode);
    }
    return path;
}

// implementare viitoare