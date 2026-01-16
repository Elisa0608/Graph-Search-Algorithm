#include <iostream>
#include "src/Graph.h"

int main(){
   //graf neponderat
    Graph g(false);
    std::cout << "Trying to read the Graph from data/input_unweighted.txt.." << std::endl;
    g.readfile("../data/input_unweighted.txt");

    std::cout<< "/n Here's the Graph: " << std::endl;
    g.printgraph();
    
    return 0;
}