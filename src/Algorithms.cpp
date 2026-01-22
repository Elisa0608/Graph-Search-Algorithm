#include "Algorithms.h"
#include "Graph.h"
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

std::list<std::string> Algorithms::DFS(const Graph& g, const std::string& startNode){
    std::stack<std::string> s;
    //in cazul dfs folosim set
    std::set<std::string> visited;
    std::map<std::string, std::string> parent;
    std::list<std::string> path;
    
    const auto& adjList = g.getAdjList();

    if (adjList.count(startNode) == 0){
        std::cout << "Error: it seems like " << startNode << "does not exist" << std::endl;
    }

    s.push(startNode);
    std::cout << "DFS starts at node: " << startNode << std::endl;

    while(!s.empty()){
        //stocam in current valoarea de deasupra
        std::string curr = s.top();
        //scoatem valoarea de deasupra din stack
        s.pop();

        //practic verifica daca e vizitat deja sau nu, visited.end() e special
        //daca conditia e adev inseamna ca nu e vizitat
        if(visited.find(curr) == visited.end()){
            std::cout << "Node " << curr << " has been visited" << std::endl;
            visited.insert(curr);

            const auto& neighbors = adjList.at(curr);
            //folosim rbegin si rend pentru ca vrem sa iteram de la sf la inceput
            for (auto i = neighbors.rbegin(); i != neighbors.rend(); i++ ){
                if (visited.find(i->to) == visited.end()){
                    s.push(i->to);
                }
            }
        }
    }
    std::cout << "Exploration complete. Total nodes visited: " << visited.size() << std::endl;
    return path;
}

std::list<std::string> Algorithms::BFS(const Graph& g, const std::string& startNode, const std::string& targetNode){
    std::queue<std::string> q;
    //in cazul bfs e mai folositor sa folosim map
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