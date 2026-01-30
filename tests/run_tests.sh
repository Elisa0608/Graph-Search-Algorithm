#!/bin/bash
set -e 

cd "$(dirname "$0")/.."

echo "--- Step 1: Compiling project ---"
mkdir -p build && cd build
cmake ..
cmake --build .

EXECUTABLE="./graph_search"
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    EXECUTABLE="./graph_search.exe"
fi

echo "--- Step 2: Running Full Integration Tests ---"

# Test 1: Dijkstra (Weighted)
RES1=$($EXECUTABLE --file ../data/input_weighted.txt --start A --end E --algo dijkstra --weighted | grep "Total Cost (Weight): 7")
[ -n "$RES1" ] && echo "[PASS] Dijkstra" || echo "[FAIL] Dijkstra"

# Test 2: BFS (Shortest Path)
RES2=$($EXECUTABLE --file ../data/input_unweighted.txt --start A --end C --algo bfs | grep "Distance: 1 hops")
[ -n "$RES2" ] && echo "[PASS] BFS" || echo "[FAIL] BFS"

# Test 3: DFS (Exploration)
RES3=$($EXECUTABLE --file ../data/input_unweighted.txt --start A --algo dfs | grep "Exploration complete")
[ -n "$RES3" ] && echo "[PASS] DFS" || echo "[FAIL] DFS"

# Test 4: Cycle Detection
RES4=$($EXECUTABLE --file ../data/input_unweighted.txt --check cycle | grep "The graph contains cycles.")
[ -n "$RES4" ] && echo "[PASS] Cycle Detection" || echo "[FAIL] Cycle Detection"

# Test 5: All Paths
RES5=$($EXECUTABLE --file ../data/input_weighted.txt --start A --end D --all_paths | grep "Done!")
[ -n "$RES5" ] && echo "[PASS] All Paths Logic" || echo "[FAIL] All Paths Logic"

# Test 6: Connectivity
RES6=$($EXECUTABLE --file ../data/input_unweighted.txt --check connected | grep "The graph is connected.")
[ -n "$RES6" ] && echo "[PASS] Connectivity" || echo "[FAIL] Connectivity"

# Test 7: Error Handling (Negative Test)
RES7=$($EXECUTABLE --file non_existent.txt 2>&1 | grep "Error: it seems like the file is missing!")
[ -n "$RES7" ] && echo "[PASS] Error Handling" || echo "[FAIL] Error Handling"

echo "---------------------------------------"
echo "All features verified."