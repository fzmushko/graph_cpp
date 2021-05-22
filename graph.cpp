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

int Graph::edge (int from, int to, int cost, bool true_if_add, bool true_if_replace_or_remove) {
    if (from < 0 || from  >= g_size) {
        cout << "Invalid argument: vertex 'from'\n";
        throw EINVARG;
        return -1;
    }
    if (to < 0 || to >= g_size) {
        cout << "Invalid argument: vertex 'to'\n";
        throw EINVARG;
        return -1;
    }
    if (from == to) {
        cout << "Invalid argument: loops are not allowed\n";
        throw EINVARG;
        return -1;
    }
    if (cost < 1) {
        cout << "Invalid argument: cost of edge should be more than 0\n";
        throw EINVARG;
        return -1;
    }
    if (true_if_add) {
        if (true_if_replace_or_remove) 
            g_edges[from][to] = cost;
        else {
            if (g_edges[from][to] == 0)
                g_edges[from][to] = cost;
            else {
                cout << "The edge already exists\n";
                throw EEXISTS;
                return -1;
            }
        }
        return 0;
    }
    else {
        if (true_if_replace_or_remove) {
            g_edges[from][to] = 0;
            return 0;
        }
        else {
            if (g_edges[from][to] == 0) {
                cout << "The edge doesn't exist\n";
                throw ENEXISTS;
                return 0;
            }
            else 
                return g_edges[from][to]; 
        }
    }
    return 0;
}

void Graph::add_edge (int from, int to, int cost) {
    int x = edge (from, to, cost, 1, 0);
}

void Graph::add_or_replace_edge (int from, int to, int cost) {
    int x = edge (from, to, cost, 1, 1);
}

void Graph::remove_edge (int from, int to) {
    int x = edge (from, to, 1, 0, 1);
}
 /*
    if (true_if_add) {
        if (true_if_replace_or_remove) {
            gr->key[from].adjacent_vertices[to] = cost;
            if (err != NULL)
                *err = ESUCCESS;
        }
        else {
            if (gr->key[from].adjacent_vertices[to] == 0) {
                if (err != NULL)
                    *err = ESUCCESS;
                gr->key[from].adjacent_vertices[to] = cost;
            }
            else {
                fprintf (stdout, "The edge already exists\n");
                if (err != NULL)
                    *err = EEXIST;
                return -1;
            } 
        }
        return 0;
    }
    else {
        if (true_if_replace_or_remove) {
            gr->key[from].adjacent_vertices[to] = 0;
            if (err != NULL)
                *err = ESUCCESS;
            return 0;
        }
        else {
            if (gr->key[from].adjacent_vertices[to] == 0) {
                fprintf (stdout, "The edge doesn't exist\n");
                if (err != NULL)
                    *err = ENEXIST;
                return 0;
            }
            else {
                if (err != NULL)
                    *err = ESUCCESS;
                return gr->key[from].adjacent_vertices[to];
            }
        }
    }
    return 0;
*/