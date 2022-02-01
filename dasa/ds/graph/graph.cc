#include "data/ds/graph/graph.h"

#include <queue>

namespace dasa {

namespace ds {

void Graph::build_graph(){
    int v, e;
    std::cout<< "Please enter vertices and edges(format: v e):"
    std::cin >> v >> e;
    Graph G(v, e);
    int from, to, weight;
    for ( int i = 0; i < edges_num; ++i ) {
        std::cout<< "Please enter edge(format: from to weight):"
        std::cin >> from >> to >> weight;
        edge = Edge(from, to, weight)
        vertices[from].push_back(edge);
        vertices[to].push_back(edge);
        edges.push_back(edge);
    }
}

std::vector<Edge> Graph::prim_mst() {
    // priority queue to maintain edges with respect to weights
    std::priority_queue<Edge> pri_queue;
    std::vector<bool> marked(graph.size(), false);
    int minimum_cost = 0;
    std::vector<Edge> mst;

    // start from the first vertice
    for (const Edge &neighbor : graph.vertices[0]) {
        if (marked[neighbor.to] == false) {
            pri_queue.push(neighbor);
        }
    }

    while (!pri_queue.empty()) {
        // Select the edge with minimum weight
        Edge edge = pri_queue.top();
        pri_queue.pop();
        // Checking for cycle
        if (marked[edge.to] == true) {
            continue;
        }
        mst.push_back(edge);
        marked[to] = true;
        for (const Edge &neighbor : graph.vertices[edge.to]) {
            if (marked[neighbor.to] == false) {
                pri_queue.push(neighbor);
            }
        }
    }
    return minimum_cost;
}

}  // namespace ds
    
}  // namespace dasa
