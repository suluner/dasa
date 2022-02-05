/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include "dasa/ds/graph/adj_matrix_graph.h"

#include <algorithm>
#include <limits>
#include <queue>
#include <functional>
#include <utility>
#include <stack>

namespace dasa {

namespace ds {

constexpr int64_t Inf = 9999999;

AdjMatrixGraph::AdjMatrixGraph(int vertices)
    : vertices_num{vertices},
      matrix{vertices_num, std::vector<int64_t>(vertices_num, Inf)} {
  for (int i = 0; i < vertices_num; ++i) {
    matrix[i][i] = 0;
  }
}

void AdjMatrixGraph::AddEdge(const Edge& edge, bool is_directed) {
  matrix[edge.from][edge.to] = edge.weight;
  if (!is_directed) {
    matrix[edge.to][edge.from] = edge.weight;
  }
}

int AdjMatrixGraph::Dijkstra(int source, int target) {
  std::vector<int64_t> dist(vertices_num, Inf);

  /*creating a min heap using priority queue
  first element of pair contains the distance
  second element of pair contains the vertex
  */
  std::priority_queue<
      std::pair<int64_t, int>,
      std::vector<std::pair<int64_t, int>>,
      std::greater<std::pair<int64_t, int>>>
      pri_queue;

  // pushing the source vertex 's' with 0 distance in min heap
  // pri_queue.push(std::make_pair(0, source));

  // marking the distance of source as 0
  for (int i = 0; i < vertices_num; ++i) {
    if (matrix[source][i] < Inf) {
      pri_queue.push(std::make_pair(matrix[source][i], i));
      dist[i] = matrix[source][i];
    }
  }

  while (!pri_queue.empty()) {
    // first element of pair denotes the distance
    int current_dist = pri_queue.top().first;
    // second element of pair denotes the node / vertex
    int current_vertice = pri_queue.top().second;
    std::cout << current_dist << "|" << current_vertice << std::endl;

    pri_queue.pop();
    // for all the reachable vertex from the currently exploring vertex
    // we will try to minimize the distance
    for (int i = 0; i < vertices_num; ++i) {
      if (current_dist + matrix[current_vertice][i] < dist[i]) {
        dist[i] = current_dist + matrix[current_vertice][i];
        pri_queue.push(std::make_pair(dist[i], i));
      }
    }
  }
  if (dist[target] != Inf) {
    return dist[target];
  }
  return -1;
}

std::vector<std::vector<int64_t>> AdjMatrixGraph::Floyd() {
  std::vector<std::vector<int64_t>> result(matrix);
  for (int k = 0; k < vertices_num; k++) {
    for (int i = 0; i < vertices_num; i++) {
      for (int j = 0; j < vertices_num; j++) {
        result[i][j] = std::min(result[i][j], result[i][k] + result[k][j]);
      }
    }
  }
  return result;
}

std::vector<int> AdjMatrixGraph::DFSTraverseWithRecursion() {
  std::vector<int> result;
  std::vector<bool> visited(vertices_num, false);
  // run times same as connected components in graph
  for (int i = 0; i < vertices_num; ++i) {
    if (!visited[i]) {
      DFS(i, result, visited);
    }
  }
  return result;
}

void AdjMatrixGraph::DFS(int vertice, std::vector<int>& result,
                         std::vector<bool>& visited) {
  result.push_back(vertice);
  visited[vertice] = true;
  for (int i=0; i < vertices_num; ++i) {
    if (matrix[vertice][i] < Inf && matrix[vertice][i] > 0 && !visited[i]) {
      DFS(i, result, visited);
    }
  }
}

std::vector<int> AdjMatrixGraph::DFSTraverseWithStack() {
  std::vector<int> result;
  std::vector<bool> visited(vertices_num, false);
  std::stack<int> stack;
  // run times same as connected components in graph
  for (int i = 0; i < vertices_num; ++i) {
    if (!visited[i]) {
      stack.push(i);
      while (!stack.empty()) {
        int vertice = stack.top();
        stack.pop();
        result.push_back(vertice);
        visited[vertice] = true;
        for (int j = vertices_num; j > 0; --j) {
          if (matrix[vertice][j-1] < Inf &&
              matrix[vertice][j-1] > 0 && !visited[j-1]) {
            stack.push(j-1);
          }
        }
      }
    }
  }
  return result;
}

std::vector<int> AdjMatrixGraph::BFSTraverse() {
  std::vector<int> result;
  std::vector<bool> visited(vertices_num, false);
  std::queue<int> queue;
  // run times same as connected components in graph
  for (int i = 0; i < vertices_num; ++i) {
    if (!visited[i]) {
      result.push_back(i);
      visited[i] = true;
      queue.push(i);
      while (!queue.empty()) {
        int vertice = queue.front();
        queue.pop();
        for (int j = 0; j < vertices_num; ++j) {
          if (matrix[vertice][j] < Inf &&
              matrix[vertice][j] > 0 && !visited[j]) {
            result.push_back(j);
            visited[j] = true;
            queue.push(j);
          }
        }
      }
    }
  }
  return result;
}

}  // namespace ds

}  // namespace dasa
