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

    for (int i=0; i < argcount; ++i){
        std::string arg = argvector[i];

        if (arg == "--file" && i + 1 < argcount) filename = argvector[++i];
        //continuam pentru fiecare caz in parte
    }
    /*
    EX TEST CODE
    Graph g(false);
    std::cout << "Trying to read the Graph from data/input_unweighted.txt.." << std::endl;
    g.readfile("../data/input_unweighted.txt");

    std::cout<< "/n Here's the Graph: " << std::endl;
    g.printgraph();
    */

    return 0;
}