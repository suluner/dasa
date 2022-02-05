/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#ifndef DASA_DS_GRAPH_ADJ_MATRIX_GRAPH_H_
#define DASA_DS_GRAPH_ADJ_MATRIX_GRAPH_H_

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
};

class AdjMatrixGraph {
 public:
  explicit AdjMatrixGraph(int vertices);

  void AddEdge(const Edge& edge, bool is_directed = false);

  int Dijkstra(int source, int target);

  std::vector<std::vector<int64_t>> Floyd();

  std::vector<int> DFSTraverseWithRecursion();

  std::vector<int> DFSTraverseWithStack();

  std::vector<int> BFSTraverse();

 private:
  int vertices_num;
  std::vector<std::vector<int64_t>> matrix;
  void DFS(int vertice, std::vector<int>& result, std::vector<bool>& visited);  // NOLINT
};

}  // namespace ds

}  // namespace dasa

#endif  // DASA_DS_GRAPH_ADJ_MATRIX_GRAPH_H_
