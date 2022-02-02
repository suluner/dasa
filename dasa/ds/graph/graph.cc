/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include "dasa/ds/graph/graph.h"

#include <queue>
#include <memory>
#include <fstream>
#include <algorithm>

#include "dasa/ds/graph/union_find.h"

namespace dasa {

namespace ds {

bool SortComparer(Edge a, Edge b) {
  if (a.weight < b.weight) {
    return true;
  } else if (a.weight > b.weight) {
    return false;
  }
  return (a.from + a.to + a.weight <= b.from + b.to + b.weight);
}

std::shared_ptr<Graph> Graph::Build() {
  std::shared_ptr<Graph> graph = std::shared_ptr<Graph>(new Graph(9, 15));
  Edge edge_0(0, 1, 10);
  graph->AddEdge(edge_0);
  Edge edge_1(0, 5, 11);
  graph->AddEdge(edge_1);
  Edge edge_2(1, 2, 18);
  graph->AddEdge(edge_2);
  Edge edge_3(1, 6, 16);
  graph->AddEdge(edge_3);
  Edge edge_4(1, 8, 12);
  graph->AddEdge(edge_4);
  Edge edge_5(2, 3, 22);
  graph->AddEdge(edge_5);
  Edge edge_6(2, 8, 8);
  graph->AddEdge(edge_6);
  Edge edge_7(3, 4, 20);
  graph->AddEdge(edge_7);
  Edge edge_8(3, 6, 24);
  graph->AddEdge(edge_8);
  Edge edge_9(3, 7, 16);
  graph->AddEdge(edge_9);
  Edge edge_10(3, 8, 21);
  graph->AddEdge(edge_10);
  Edge edge_11(4, 5, 26);
  graph->AddEdge(edge_11);
  Edge edge_12(4, 7, 7);
  graph->AddEdge(edge_12);
  Edge edge_13(5, 6, 17);
  graph->AddEdge(edge_13);
  Edge edge_14(6, 7, 19);
  graph->AddEdge(edge_14);
  return graph;
}

void Graph::SortEdges() {
  std::sort(edges.begin(), edges.end(), SortComparer);
}

void Graph::AddEdge(const Edge& edge) {
  vertices[edge.from].push_back(edge);
  Edge reverse_edge(edge.to, edge.from, edge.weight);
  vertices[edge.to].push_back(reverse_edge);
  edges.push_back(edge);
}

std::vector<Edge> Graph::PrimMst() {
  // priority queue to maintain edges with respect to weights
  std::priority_queue<Edge> pri_queue;
  std::vector<bool> marked(vertices_num, false);
  std::vector<Edge> mst;

  // start from the first vertice
  marked[0] = true;
  for (const Edge& neighbor : vertices[0]) {
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
    marked[edge.to] = true;
    for (const Edge& neighbor : vertices[edge.to]) {
      if (marked[neighbor.to] == false) {
        pri_queue.push(neighbor);
      }
    }
  }
  return mst;
}

std::vector<Edge> Graph::KruskalMst() {
  SortEdges();
  UnionFind uf(vertices_num);
  int e = 0;
  int i = 0;
  std::vector<Edge> mst;
  while (e < vertices_num - 1) {
    Edge next_edge = edges[i++];
    int root_from = uf.FindRoot(next_edge.from);
    int root_to = uf.FindRoot(next_edge.to);
    if (root_from != root_to) {
      mst.push_back(next_edge);
      uf.Union(root_from, root_to);
      ++e;
    }
  }
  return mst;
}

}  // namespace ds

}  // namespace dasa
