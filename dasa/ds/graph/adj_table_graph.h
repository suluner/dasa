/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#ifndef DASA_DS_GRAPH_ADJ_TABLE_GRAPH_H_
#define DASA_DS_GRAPH_ADJ_TABLE_GRAPH_H_

#include <iostream>
#include <vector>
#include <memory>
#include <string>

namespace dasa {

namespace ds {

struct Edge {
  int from;
  int to;
  int weight;
  Edge(int x, int y, int w = 1) : from(x), to(y), weight(w) {}
  bool operator<(const Edge& edge) const {
    return weight >= edge.weight;  // less weight first out
  }
};

class AdjTableGraph {
 public:
  AdjTableGraph(int v, int e)
      : vertices_num{v},
        edges_num{e},
        vertices{vertices_num, std::vector<Edge>()},
        in_degree(vertices_num, 0),
        vertice_earliest(vertices_num, 0),
        vertice_latest(vertices_num, 0) {}

  void AddEdge(const Edge& edge, bool is_directed = false);

  std::vector<Edge> GetEdges() {
    return edges;
  }

  void SortEdges();

  std::vector<Edge> KruskalMst();

  std::vector<Edge> PrimMst();

  std::vector<int> TopoSort();

  void CriticalPath();

 private:
  int vertices_num;  // number of vertices
  int edges_num;  // number of Edges
  std::vector<std::vector<Edge>> vertices;
  std::vector<Edge> edges;
  std::vector<int> in_degree;
  std::vector<int> vertice_earliest;
  std::vector<int> vertice_latest;
};

}  // namespace ds

}  // namespace dasa

#endif  // DASA_DS_GRAPH_ADJ_TABLE_GRAPH_H_
