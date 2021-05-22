#include "graph.h"
#include <stdlib.h>

const int vertex_without_value = 0;

Graph::Graph() {
    g_edges = new int* [GRAPH_SIZE];
    for (int i = 0; i < GRAPH_SIZE; ++i)
        g_edges[i] = new int [GRAPH_SIZE];
    g_values = new int [GRAPH_SIZE];
    for (int i = 0; i < GRAPH_SIZE; ++i)
        g_values[i] = vertex_without_value;
    for (int i = 0; i < GRAPH_SIZE; ++i) {
        for (int j = 0; j < GRAPH_SIZE; ++j)
            g_edges[i][j] = 0;
    }
    g_size = GRAPH_SIZE;
}

Graph::Graph(int size) {
    g_edges = new int* [size];
    for (int i = 0; i < size; ++i)
        g_edges[i] = new int [size];        
    g_values = new int [size];
    for (int i = 0; i < size; ++i)
        g_values[i] = vertex_without_value;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            g_edges[i][j] = 0;
    }
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
    }
    if (to < 0 || to >= g_size) {
        cout << "Invalid argument: vertex 'to'\n";
        throw EINVARG;
    }
    if (from == to) {
        cout << "Invalid argument: loops are not allowed\n";
        throw EINVARG;
    }
    if (cost < 1) {
        cout << "Invalid argument: cost of edge should be more than 0\n";
        throw EINVARG;
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

int Graph::edge_cost (int from, int to) {
    return edge(from, to, 1, 0, 0);
}

int Graph::value (int vertex_key, int recieved_value, bool true_if_add, bool true_if_replace_or_remove) {
    if (vertex_key < 0 || vertex_key >= g_size) {
        cout << "Invalid argument: vertex key\n";
        throw EINVARG;
    }
    if (recieved_value < 1) {
        cout << "Invalid argument: value should be more than 0\n";
        throw EINVARG;
    }
    if (true_if_add) {
        if (!true_if_replace_or_remove && g_values[vertex_key] != 0) {
            cout << "The value already exists\n";
            throw EEXISTS;
        }
        else {
            g_values[vertex_key] = recieved_value;
            return 0;
        }
    }
    else {
        if (true_if_replace_or_remove) {
            g_values[vertex_key] = 0;
            return 0;
        }
        else {
            if (g_values[vertex_key] == 0) {
                cout << "The value doesn't exist\n";
                throw ENEXISTS;
            }
            else 
                return g_values[vertex_key];
        }
    }
    return 0;
}

void Graph::add_value (int vertex_key, int recieved_value) {
    int x = value (vertex_key, recieved_value, 1, 0);
}

void Graph::add_or_replace_value (int vertex_key, int recieved_value) {
    int x = value(vertex_key, recieved_value, 1, 1);
}

void Graph::remove_value (int vertex_key) {
    int x = value(vertex_key, 1, 0, 1);
}


/*
    if (true_if_add) {
        if (!true_if_replace_or_remove && gr->key[vertex_key].value != -1) {
            fprintf (stdout, "The value already exists\n");
            if (err != NULL)
                *err = EEXIST;
            return -1;
        }
        else {
            gr->key[vertex_key].value = recieved_value;
            if (err != NULL)
                *err = ESUCCESS;
            return 0;
        }
    }
    else {
        if (true_if_replace_or_remove) {
            gr->key[vertex_key].value = vertex_without_value;
            if (err != NULL)
                *err = ESUCCESS;
            return 0;
        }
        else {
            if (gr->key[vertex_key].value == vertex_without_value) {
                fprintf (stdout, "The value doesn't exist\n");
                if (err != NULL)
                    *err = ENEXIST;
                return -2;
            }
            else {
                if (err != NULL)
                    *err = ESUCCESS;
                return gr->key[vertex_key].value;
            }
        }
    }
    return 0;
*/