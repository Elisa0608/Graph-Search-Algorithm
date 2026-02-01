#include <iostream>
#include <string>
#include <vector>
#include "src/Graph.h"
#include "src/Algorithms.h"

int main(int argcount, char* argvector[]){
    std::string filename = "";
    std::string startNode = "";
    std::string endNode = "";
    std::string algo = "";
    std::string checkType = "";
    bool showViz = false;
    bool allPaths = false;
    bool weighted = false;

    for (int i=1; i < argcount; ++i){
        std::string arg = argvector[i];

        //verificam argumentele
        if (arg == "--file" && i + 1 < argcount) filename = argvector[++i];
        else if (arg == "--start" && i + 1 < argcount) startNode = argvector[++i];
        else if (arg == "--end" && i + 1 < argcount) endNode = argvector[++i];
        else if (arg == "--algo" && i + 1 < argcount) algo = argvector[++i];
        else if (arg == "--check" && i + 1 < argcount) checkType = argvector[++i];
        else if (arg == "--viz") showViz = true;
        else if (arg == "--all_paths") allPaths = true;
        else if (arg == "--weighted") weighted = true;
    }

    if (filename.empty()){
            std::cerr << "Error: it seems like the file is missing! Use '--file <file_name>' " << std::endl;
            return 1;
        }

    //initializam si incarcam datele!!
    Graph g(weighted);
    g.readfile(filename);

    if (showViz){
        g.printgraph();
    }

    if (!checkType.empty()){
        if (checkType == "connected"){
            std::cout << "Checking if the graph is connected: loading..." << std::endl;
            if (g.isConnected()){
                std::cout << "The graph is connected." << std::endl;
            }else{
                std::cout << "The graph is not connected." << std::endl;
            }
        }
        else if(checkType == "cycle"){
            std::cout << "Detecting cycles: loading..." <<std::endl;
            if (g.isCyclic()){
                std::cout << "The graph contains cycles." << std::endl;
            }else{
                std::cout << "The graph does not contain cycles." << std::endl;
            }
        }
    }

    if (allPaths && !startNode.empty() && !endNode.empty()){
        std::cout << "Loading all paths between " <<startNode << " and " << endNode << std::endl;
        std::set<std::string> visited;
        std::vector<std::string> currentPath;
        Algorithms::allPaths(g, startNode, endNode, visited, currentPath);
        std::cout << "Done! " << std::endl;
    }

    if (!algo.empty() && !startNode.empty()){
        if (algo == "bfs" && !endNode.empty()){
            auto path = Algorithms::BFS(g, startNode, endNode);
            g.reconstructPath(path, "BFS (shortest path)");
        }
        else if (algo == "dfs"){
            Algorithms::DFS(g, startNode);
        }
        else if (algo == "dijkstra"){
            if (weighted){
                auto path = Algorithms::Dijkstra(g, startNode, endNode);
                g.reconstructPath(path, "Dijkstra result (min-cost path)");
            }else {
                std::cout << "Warning: dijkstra requires a weighted graph! Add '--weighted'. " << std::endl;
            }
        }
    }
    return 0;
}