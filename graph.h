#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <cstring>

#define GRAPH_SIZE 3

using namespace std;

class Graph
{
public:
    enum graph_error {
        EINVARG = 1,
        EEXISTS,
        ENEXISTS
    };

    Graph();
    Graph (int size);
    Graph (const Graph &g);
    ~Graph();
    int edge (int from, int to, int cost, bool true_if_add, bool true_if_replace_or_remove);
    void add_edge (int from, int to, int cost);
    void add_or_replace_edge (int from, int to, int cost);
    void remove_edge (int from, int to);
    int edge_cost (int from, int to);
    int value (int vertex_key, int recieved_value, bool true_if_add, bool true_if_replace_or_remove);
    void add_value (int vertex_key, int recieved_value);
    void add_or_replace_value (int vertex_key, int recieved_value);
    void remove_value (int vertex_key);
    /*int get_value (int vertex_key);
    */

    friend ostream &operator<<(ostream &output, const Graph (*g)) {
        if (g == NULL) {
            throw EINVARG;
        }
        if ((*g).g_size == 0) {
            output << "No vertices in graph" << endl;
            return output;
        }
        output << "Number of vertices - " << (*g).g_size << "\n";
        for (int i = 0; i < (*g).g_size; ++i)
            output <<  "\t" << i;
        output << "\n";
        for (int i = 0; i < (*g).g_size; ++i) {
            output << i << "\t";
            for (int j = 0; j < (*g).g_size; ++j) 
                output << (*g).g_edges[i][j] << "\t";
            output << "\n";
        }
        for (int i = 0; i < (*g).g_size; ++i)
            output << i << "\t" << (*g).g_values[i] << endl;
        return output;
    }


private:
    int **g_edges;
    int *g_values;
    int g_size;
};
/*
typedef struct vertex {
    int *adjacent_vertices;
    int value;
} vertex;

typedef struct graph {
    vertex *key;
    int number_of_vertices;
} graph;

typedef enum {
    ESUCCESS = 0,
    EINVARG,
    EEXIST,
    ENEXIST,
    EMALLOC
} GRAPH_ERR;

graph *create_graph (int n, GRAPH_ERR *err);

void remove_graph (graph **gr, GRAPH_ERR *err);

void print_graph (graph *gr, GRAPH_ERR *err);

int edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err, _Bool true_if_add, _Bool true_if_replace_or_remove);

void add_edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err);

void add_or_replace_edge (graph *gr, int from, int to, int cost, GRAPH_ERR *err);

void remove_edge (graph *gr, int from, int to, GRAPH_ERR *err);

int edge_cost (graph *gr, int from, int to, GRAPH_ERR *err);

int value (graph *gr, int vertex_key, int recieved_value, GRAPH_ERR *err, _Bool true_if_add, _Bool true_if_replace_or_remove);

void add_value (graph *gr, int vertex_key, int recieved_value, GRAPH_ERR *err);

void add_or_replace_value (graph *gr, int vertex_key, int recieved_value, GRAPH_ERR *err);

void remove_value (graph *gr, int vertex_key, GRAPH_ERR *err);

int get_value (graph *gr, int vertex_key, GRAPH_ERR *err);
*/
#endif