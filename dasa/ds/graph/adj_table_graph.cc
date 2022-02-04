/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include "dasa/ds/graph/adj_table_graph.h"

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

void AdjTableGraph::SortEdges() {
  std::sort(edges.begin(), edges.end(), SortComparer);
}

void AdjTableGraph::AddEdge(const Edge& edge, bool is_directed) {
  vertices[edge.from].push_back(edge);
  in_degree[edge.to]++;
  if (!is_directed) {
    Edge reverse_edge(edge.to, edge.from, edge.weight);
    vertices[edge.to].push_back(reverse_edge);
  }
  edges.push_back(edge);
}

std::vector<Edge> AdjTableGraph::PrimMst() {
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

std::vector<Edge> AdjTableGraph::KruskalMst() {
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

std::vector<int> AdjTableGraph::TopoSort() {
  std::queue<int> queue;
  for (int i = 0; i < vertices_num; ++i) {
    if (in_degree[i] == 0) {
      queue.push(i);
    }
  }
  std::vector<int> result;
  while (!queue.empty()) {
    int v = queue.front();
    queue.pop();
    result.push_back(v);
    for (auto edge : vertices[v]) {
      if (!(--in_degree[edge.to])) {
        queue.push(edge.to);
      }
      if (vertice_earliest[v] + edge.weight > vertice_earliest[edge.to]) {
        vertice_earliest[edge.to] = vertice_earliest[v] + edge.weight;
      }
    }
  }
  return result;
}

void AdjTableGraph::CriticalPath() {
  std::vector<int> topo_sort_vertices = TopoSort();
  for (int i = 0; i < vertices_num; ++i) {
    vertice_latest[i] = vertice_earliest[vertices_num - 1];
  }

  std::vector<int> reversed_topo_sort_vertices(topo_sort_vertices);
  std::reverse(
      reversed_topo_sort_vertices.begin(), reversed_topo_sort_vertices.end());
  for (int vertice : reversed_topo_sort_vertices) {
    for (Edge edge : edges) {
      if (edge.to == vertice) {
        if (vertice_latest[vertice] - edge.weight < vertice_latest[edge.from]) {
          vertice_latest[edge.from] = vertice_latest[vertice] - edge.weight;
        }
      }
    }
  }
  std::vector<int> edge_earliest(edges_num, 0);
  std::vector<int> edge_latest(edges_num, 0);
  for (int i = 0; i < edges_num; ++i) {
    edge_earliest[i] = vertice_earliest[edges[i].from];
    edge_latest[i] = vertice_latest[edges[i].to] - edges[i].weight;
    const char* tag = edge_earliest[i] == edge_latest[i] ? "*" : "";
    std::cout << "edge: " << i << tag << std::endl;
  }
}

}  // namespace ds

}  // namespace dasa
