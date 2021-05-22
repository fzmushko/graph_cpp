#ifndef _GRAPH_H_
#define _GRAPH_H_

#define GRAPH_SIZE 10

using namespace std;

class Graph
{
public:
    enum graph_error {
        EINVARG = 1,
        EEXIST,
        ENEXIST
    };

    Graph();
    Graph (int size);
    ~Graph();

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