#include "graph.h"
#include <stdlib.h>

Graph::Graph() {
    g_edges = new int* [GRAPH_SIZE];
    for (int i = 0; i < GRAPH_SIZE; ++i)
        g_edges[i] = new int [GRAPH_SIZE];
    g_values = new int [GRAPH_SIZE];
    g_size = GRAPH_SIZE;
}

Graph::Graph(int size) {
    g_edges = new int* [size];
    for (int i = 0; i < size; ++i)
        g_edges[i] = new int [size];
    g_values = new int [size];
    g_size = size;
}
/*
Graph::Graph(const Graph &g) {
    int n = g.g_size;
    g_edges = new int* [n];
    for (int i = 0; i < n; ++i)
        g_edges[i] = new int [n];
    g_values = new int [n];
    g_size = n;
}
*/

Graph::~Graph() {
    delete [] g_values;
    g_values = NULL;
    for (int i = 0; i < g_size; ++i)
        delete [] g_edges[i];
    delete [] g_edges;
    g_edges = NULL;
}