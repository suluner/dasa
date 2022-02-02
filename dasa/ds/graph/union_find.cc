/* Copyright 2022 Hu Ting. All Rights Reserved.
==============================================*/

#include "dasa/ds/graph/union_find.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

namespace dasa {

namespace ds {

UnionFind::UnionFind(int n) : count(n) {
  parent = new int[count];
  size = new int[count];
  for (int i = 0; i < count; ++i) {
    parent[i] = i;
    size[i] = 1;
  }
}

void UnionFind::Union(int p, int q) {
  int root_p = FindRoot(p);
  int root_q = FindRoot(q);
  if (root_p == root_q) {
    return;
  }
  // Merge two tree
  if (size[root_p] < size[root_q]) {
    parent[root_p] = root_q;
    size[root_q] += size[root_p];
  } else {
    parent[root_q] = root_p;
    size[root_p] += size[root_q];
  }
  count--;
}

int UnionFind::FindRoot(int x) {
  while (parent[x] != x) {
    // Compress tree height
    parent[x] = parent[parent[x]];
    x = parent[x];
  }
  return x;
}

int UnionFind::Count() {
  return count;
}

bool UnionFind::Connected(int p, int q) {
  int root_p = FindRoot(p);
  int root_q = FindRoot(q);
  return root_p == root_q;
}

}  // namespace ds

}  // namespace dasa
