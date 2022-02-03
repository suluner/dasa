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
  Edge(int x, int y, int w) : from(x), to(y), weight(w) {}
  bool operator<(const Edge& edge) const {
    return weight >= edge.weight;  // less weight first out
  }
};

class AdjTableGraph {
 public:
  AdjTableGraph(int v, int e)
      : vertices_num{v},
        edges_num{e},
        vertices{vertices_num, std::vector<Edge>()} {}

  void AddEdge(const Edge& edge);

  std::vector<Edge> GetEdges() {
    return edges;
  }

  void SortEdges();

  std::vector<Edge> KruskalMst();

  std::vector<Edge> PrimMst();

 private:
  int vertices_num;  // number of vertices
  int edges_num;  // number of Edges
  std::vector<std::vector<Edge>> vertices;
  std::vector<Edge> edges;
};

}  // namespace ds

}  // namespace dasa

#endif  // DASA_DS_GRAPH_ADJ_TABLE_GRAPH_H_
