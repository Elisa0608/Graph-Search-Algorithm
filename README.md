# Graph-Search-Algorithm

## Project Description
This project contains the implementation of fundamental graph traversal algorithms: Breadth-First Search (BFS) and Depth-First Search (DFS).

The project is developed in C++ and demonstrates the process of reading a graph structure from a file and traversing it using these two distinct methods.

The primary goal of this exercise is to clearly illustrate the differences in behavior and output between BFS (level-by-level exploration) and DFS (branch-by-branch exploration).

## Implemented Algortithms

### 1. Breadth-First Search (BFS)
 - GOAL: To find the shortest path in an unweighted graph.
 - METHODOLOGY: Explores all neighbors at the current depth level before moving on to the nodes at the next depth level.
 - DATA STRUCTURE: Uses a queue data structure to manage the order of nodes to visit.

 ### 2. Depth-First Search (DFS)
  - GOAL: Used for tasks like topological sorting, finding connected components, and cycle detection.
  - METHODOLOGY: Explores as far as possible along each branch before backtracking.
  - DATA STRUCTURE: Uses a stack (implicitly via recursion or explicitly) to track the path of exploration.

  ### Graph Representation
    The graph is implemented using the Adjacency List representation, which is efficient for sparse graphs (graphs with relatively few edges).

## Project Structure
The project is organized into modular files for better separation of concerns:

.
├── src/
│   ├── Graph.cpp         
│   └── Algorithms.cpp    
├── data/
│   └── input.txt        
├── README.md             
└── main.cpp              

## Author
* NAME: Mosoarca Nicoleta-Elisa