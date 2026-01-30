#!/bin/bash

echo "Compiling project..."
cd ../build
cmake .. && make

echo "Running Automated Integration Tests..."

RESULT_DIJKSTRA=$(./graph_search --file ../data/input_weighted.txt --start A --end E --algo dijkstra --weighted | grep "Total Cost (Weight): 7")

if [ ! -empty "$RESULT_DIJKSTRA" ]; then
    echo "[PASS] Test 1: Dijkstra optimal path (Cost 7)"
else
    echo "[FAIL] Test 1: Dijkstra failed or incorrect cost."
fi

RESULT_BFS=$(./graph_search --file ../data/input_unweighted.txt --start A --end C --algo bfs | grep "Distance: 1 hops")

if [ ! -empty "$RESULT_BFS" ]; then
    echo "[PASS] Test 2: BFS shortest path (1 hop)"
else
    echo "[FAIL] Test 2: BFS failed or incorrect distance."
fi

RESULT_CONN=$(./graph_search --file ../data/input_unweighted.txt --check connected | grep "The graph is connected.")

if [ ! -empty "$RESULT_CONN" ]; then
    echo "[PASS] Test 3: Connectivity check"
else
    echo "[FAIL] Test 3: Connectivity check failed."
fi

echo "---------------------------------------"
echo "Tests completed."