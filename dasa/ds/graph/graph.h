#ifndef DASA_DS_GRAPH_GRAPH_H_
#define DASA_DS_GRAPH_GRAPH_H_

#include<iostream>
#include<vector>


namespace dasa {

namespace ds{

struct Edge {
    int from;
    int to;
    int weight;
    Edge( int x, int y, int w) : from(x), to(y), weight(w) {}
    bool operator<(const Edge& edge) const {
      return weight > edge.weight;     // less weight first out
    }
};

class Graph{
  public:
    Graph(int v, int e) : vertices_num(v), edges_num(e) {}
    void build_graph();
    void get_edges();
    void sort_edges();
    int num_of_vertices() {return vertices_num;}
    int num_Of_edges() {return edges_num;}
    std::vector<Edge> kruskal_mst();
    std::vector<Edge> prim_mst();
  private:
    int vertices_num;  //number of vertices
    int edges_num;  //number of Edges
    std::vector<std::vector<Edge>> vertices;
    std::vector<Edge> edges;
};

}

}

#endif
