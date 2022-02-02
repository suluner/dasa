/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#ifndef DASA_DS_GRAPH_UNION_FIND_H_
#define DASA_DS_GRAPH_UNION_FIND_H_

#include <iostream>
#include <vector>
#include <memory>
#include <string>

namespace dasa {

namespace ds {

class UnionFind {
 public:
  explicit UnionFind(int n);

  void Union(int p, int q);

  bool Connected(int p, int q);

  int Count();

  int FindRoot(int x);

 private:
  int count;
  int* parent;
  int* size;
};

}  // namespace ds

}  // namespace dasa

#endif  // DASA_DS_GRAPH_UNION_FIND_H_
