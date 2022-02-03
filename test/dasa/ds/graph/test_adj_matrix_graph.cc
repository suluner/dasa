/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include <gtest/gtest.h>

#include <iostream>
#include <fstream>
#include <memory>

#include "dasa/ds/graph/adj_matrix_graph.h"

using dasa::ds::AdjMatrixGraph;
using dasa::ds::Edge;

std::unique_ptr<AdjMatrixGraph> BuildGraph() {
  auto graph = std::unique_ptr<AdjMatrixGraph>(new AdjMatrixGraph(9));
  Edge edge = Edge(0, 1, 1);
  graph->AddEdge(edge);
  edge = Edge(0, 2, 5);
  graph->AddEdge(edge);
  edge = Edge(1, 2, 3);
  graph->AddEdge(edge);
  edge = Edge(1, 3, 7);
  graph->AddEdge(edge);
  edge = Edge(1, 4, 5);
  graph->AddEdge(edge);
  edge = Edge(2, 4, 1);
  graph->AddEdge(edge);
  edge = Edge(2, 5, 7);
  graph->AddEdge(edge);
  edge = Edge(3, 4, 2);
  graph->AddEdge(edge);
  edge = Edge(3, 6, 3);
  graph->AddEdge(edge);
  edge = Edge(4, 5, 3);
  graph->AddEdge(edge);
  edge = Edge(4, 6, 6);
  graph->AddEdge(edge);
  edge = Edge(4, 7, 9);
  graph->AddEdge(edge);
  edge = Edge(5, 7, 5);
  graph->AddEdge(edge);
  edge = Edge(6, 7, 2);
  graph->AddEdge(edge);
  edge = Edge(6, 8, 7);
  graph->AddEdge(edge);
  edge = Edge(7, 8, 4);
  graph->AddEdge(edge);
  return graph;
}

TEST(AdjMatrixGraphTest, Dijkstra) {
  auto graph = BuildGraph();
  int min_count = graph->Dijkstra(0, 8);
  std::cout << min_count << std::endl;
}

TEST(AdjMatrixGraphTest, Floyd) {
  auto graph = BuildGraph();
  auto result = graph->Floyd();
  std::cout << result[0][8] << std::endl;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
