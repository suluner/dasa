/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include <gtest/gtest.h>

#include <iostream>
#include <fstream>
#include <memory>

#include "dasa/ds/graph/graph.h"

using dasa::ds::Edge;
using dasa::ds::Graph;

TEST(GraphTest, PrimMst) {
  std::shared_ptr<Graph> graph = Graph::Build();
  std::vector<Edge> edges = graph->PrimMst();
  std::cout << edges.size() << std::endl;
  int min_count = 0;
  for (auto edge : edges) {
    min_count += edge.weight;
  }
  std::cout << min_count << std::endl;
  EXPECT_EQ(min_count, 99);
}

TEST(GraphTest, KruskalMst) {
  std::shared_ptr<Graph> graph = Graph::Build();
  std::vector<Edge> edges = graph->KruskalMst();
  std::cout << edges.size() << std::endl;
  int min_count = 0;
  for (auto edge : edges) {
    min_count += edge.weight;
  }
  std::cout << min_count << std::endl;
  EXPECT_EQ(min_count, 99);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
