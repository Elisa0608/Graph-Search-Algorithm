# Graph-Search-Algorithm
A high-performance C++ command-line application designed for processing and analyzing complex directed and undirected graphs. It provides efficient pathfinding solutions and structural property checks through various algorithmic implementations.

## Author
* Name: Mosoarca Nicoleta-Elisa
* Group: 2.2
* Email: nicoleta-elisa.mosoarca@student.upt.ro
* Academic Year: 2025-2026

## Project Description
This application serves as a versatile tool for graph navigation and structural analysis. It solves common problems in network topology, such as finding the most cost-effective route in weighted networks or ensuring graph integrity by detecting cycles and connectivity. It is particularly useful for students and developers looking to visualize and test graph theory concepts in a CLI environment.

## Technologies
* Language: C++17
* Libraries:
  - STL (map, vector, set, list) - Used for efficient data storage and adjacency list management.
  - fstream / sstream - Utilized for robust file parsing and data input.
* Tools: Git, Docker, CMake.

## System Requirements
* Compiler: g++ or clang with C++17 support.
* Build System: CMake 3.10 or higher.
* Operating System: Windows, Linux, or macOS.

## Installation

* Clone repository
```bash
git clone https://github.com/Elisa0608/Graph-Search-Algorithm.git
cd Graph-Search-Algorithm
```

* Build project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

### Command Flags
* `--file <path>`: Specify the input graph file.
* `--start <node>`: Set the starting node.
* `--end <node>`: Set the target destination node.
* `--algo <bfs|dfs|dijkstra>`: Choose the search algorithm.
* `--check <connected|cycle>`: Perform structural analysis.
* `--weighted`: Enable weighted edge processing.
* `--all_paths`: Find all possible routes between two nodes.

### Usage Examples

**Example 1: Shortest Path (Unweighted) using BFS**
```bash
$ ./graph_search --file ../data/input_unweighted.txt --start A --end C --algo bfs
Path reconstruction for: BFS (shortest path)
A -> C
Distance: 1 hops
```

**Example 2: Minimum Cost Path (Weighted) using Dijkstra**
```bash
$ ./graph_search --file ../data/input_weighted.txt --start A --end E --algo dijkstra --weighted
Path reconstruction for: Dijkstra result (min-cost path)
A -> C -> D -> E
Total Cost (Weight): 7
```

**Example 3: All Possible Routes (A to D)**
```bash
$ ./graph_search --file ../data/input_weighted.txt --start A --end D --all_paths
Finding all paths between A and D:
A -> B -> D
A -> B -> C -> D
A -> C -> D
A -> C -> B -> D
Done!
```

**Example 4: Graph Exploration (DFS)**  
Shows the order in which the algorithm "dives" into the graph's branches
```bash
$ ./graph_search --file ../data/input_unweighted.txt --start A --algo dfs
DFS starts at node: A
Node A has been visited
Node C has been visited
Node F has been visited
Node G has been visited
Node H has been visited
...
Exploration complete. Total nodes visited: 8
```

**Example 5: Structural Integrity Check (Cycles)**  
Verifies if the graph contains any closed loops, which is critical for tree-based logic.
```bash
$ ./graph_search --file ../data/input_unweighted.txt --check cycle
Detecting cycles: loading...
The graph contains cycles.
```

## Implemented Features
- [x] BFS for shortest path discovery in unweighted graphs.
- [x] DFS for exhaustive graph exploration.
- [x] Dijkstra's Algorithm for cost-optimized pathfinding in weighted graphs.
- [x] Backtracking logic to discover all possible paths between two points.
- [x] Connectivity Verification using stack-based traversal.
- [x] Cycle Detection for graph integrity checks.

## Project Structure
```
.
├── src/
│   ├── Graph.cpp  
│   ├── Graph.h   
│   ├── Algorithms.cpp  
│   └── Algorithms.h   
├── data/
│   ├── input_weighted.txt  
│   └── input_unweighted.txt 
├── tests/
│   └── run_tests.sh 
├── main.cpp   
├── CMakeLists.txt   
├── Dockerfile   
├── .gitignore  
└── README.md  
```

## Design Decisions
1. **Adjacency List with std::map**: I chose to use `std::map<std::string, std::vector<Edge>>` to allow for flexible, string-based node naming while maintaining efficient access to neighbor lists.

2. **Simplified Dijkstra**: Instead of a complex priority queue, I implemented a version using `std::set` and `std::map` to prioritize code readability and easier debugging for structural verification.

3. **Recursive Backtracking**: For the `allPaths` functionality, I utilized a recursive approach with a "visit-unvisit" logic to ensure all simple paths are discovered without falling into infinite loops.

## Encountered Problems and Solutions
**Problem**: Circular dependencies in pathfinding caused infinite loops.  
**Solution**: Implemented a `std::set<std::string>` visited tracker to ensure each node is processed only once per path.

**Problem**: Parsing weights from a text file was inconsistent.  
**Solution**: Developed a custom parser using `stringstream` and `substr` to handle formats like `A-B:10` accurately.

## Testing
To run the automated tests, use the provided script:
```bash
cd tests
chmod +x run_tests.sh
./run_tests.sh
```

To test the application, multiple graph configurations were used:

* **Weighted Graphs**: Verified that Dijkstra correctly identifies the lowest cost even if it requires more hops than BFS.
* **Disconnected Graphs**: Confirmed that `isConnected()` accurately identifies graphs with isolated clusters.
* **Cyclic vs Acyclic**: Tested with trees and meshes to ensure `isCyclic()` correctly identifies loops.

## Docker
To run tests via Docker (Cross-platform recommended):
```bash
docker run --rm --entrypoint /bin/bash elisamosoarca/graph-tool ./tests/run_tests.sh
```

* **Pull pre-built image**: 
```bash
docker pull elisamosoarca/graph-tool:latest
```

* **Build Image Locally**: 
```bash
docker build -t graph-tool .
```

* **Usage Example (Run a single command)**: 

This command downloads the image and runs the Dijkstra algorithm as a demo:

```bash
docker run --rm elisamosoarca/graph-tool --file data/input_weighted.txt --algo dijkstra --start A --end E --weighted
```