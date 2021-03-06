/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include <gtest/gtest.h>

#include <iostream>
#include <fstream>
#include <memory>

#include "dasa/ds/graph/adj_table_graph.h"

using dasa::ds::AdjTableGraph;
using dasa::ds::Edge;

std::unique_ptr<AdjTableGraph> BuildGraph() {
  auto graph = std::unique_ptr<AdjTableGraph>(new AdjTableGraph(9, 15));
  Edge edge = Edge(0, 1, 10);
  graph->AddEdge(edge);
  edge = Edge(0, 5, 11);
  graph->AddEdge(edge);
  edge = Edge(1, 2, 18);
  graph->AddEdge(edge);
  edge = Edge(1, 6, 16);
  graph->AddEdge(edge);
  edge = Edge(1, 8, 12);
  graph->AddEdge(edge);
  edge = Edge(2, 3, 22);
  graph->AddEdge(edge);
  edge = Edge(2, 8, 8);
  graph->AddEdge(edge);
  edge = Edge(3, 4, 20);
  graph->AddEdge(edge);
  edge = Edge(3, 6, 24);
  graph->AddEdge(edge);
  edge = Edge(3, 7, 16);
  graph->AddEdge(edge);
  edge = Edge(3, 8, 21);
  graph->AddEdge(edge);
  edge = Edge(4, 5, 26);
  graph->AddEdge(edge);
  edge = Edge(4, 7, 7);
  graph->AddEdge(edge);
  edge = Edge(5, 6, 17);
  graph->AddEdge(edge);
  edge = Edge(6, 7, 19);
  graph->AddEdge(edge);
  return graph;
}

std::unique_ptr<AdjTableGraph> BuildDAG() {
  auto graph = std::unique_ptr<AdjTableGraph>(new AdjTableGraph(6, 6));
  Edge edge = Edge(5, 0);
  graph->AddEdge(edge, true);
  edge = Edge(4, 0);
  graph->AddEdge(edge, true);
  edge = Edge(5, 2);
  graph->AddEdge(edge, true);
  edge = Edge(4, 1);
  graph->AddEdge(edge, true);
  edge = Edge(2, 3);
  graph->AddEdge(edge, true);
  edge = Edge(3, 1);
  graph->AddEdge(edge, true);
  return graph;
}

std::unique_ptr<AdjTableGraph> BuildAOE() {
  auto graph = std::unique_ptr<AdjTableGraph>(new AdjTableGraph(9, 11));
  Edge edge = Edge(0, 1, 6);
  graph->AddEdge(edge, true);
  edge = Edge(0, 2, 4);
  graph->AddEdge(edge, true);
  edge = Edge(0, 3, 5);
  graph->AddEdge(edge, true);
  edge = Edge(1, 4, 1);
  graph->AddEdge(edge, true);
  edge = Edge(2, 4, 1);
  graph->AddEdge(edge, true);
  edge = Edge(3, 5, 2);
  graph->AddEdge(edge, true);
  edge = Edge(4, 6, 9);
  graph->AddEdge(edge, true);
  edge = Edge(4, 7, 7);
  graph->AddEdge(edge, true);
  edge = Edge(5, 7, 4);
  graph->AddEdge(edge, true);
  edge = Edge(6, 8, 2);
  graph->AddEdge(edge, true);
  edge = Edge(7, 8, 4);
  graph->AddEdge(edge, true);
  return graph;
}

TEST(AdjTableGraphTest, PrimMst) {
  auto graph = BuildGraph();
  std::vector<Edge> edges = graph->PrimMst();
  std::cout << edges.size() << std::endl;
  int min_count = 0;
  for (auto edge : edges) {
    min_count += edge.weight;
  }
  std::cout << min_count << std::endl;
  EXPECT_EQ(min_count, 99);
}

TEST(AdjTableTest, KruskalMst) {
  auto graph = BuildGraph();
  std::vector<Edge> edges = graph->KruskalMst();
  std::cout << edges.size() << std::endl;
  int min_count = 0;
  for (auto edge : edges) {
    min_count += edge.weight;
  }
  std::cout << min_count << std::endl;
  EXPECT_EQ(min_count, 99);
}

TEST(AdjTableTest, TopoSort) {
  auto graph = BuildDAG();
  std::vector<int> vertices = graph->TopoSort();
  std::cout << "vertices num: " << vertices.size() << std::endl;
  EXPECT_EQ(vertices.size(), 6);
  for (int node : vertices) {
    std::cout << node << std::endl;
  }
}

TEST(AdjTableTest, CriticalPath) {
  auto graph = BuildAOE();
  graph->CriticalPath();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
