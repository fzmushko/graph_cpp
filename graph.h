#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <cstring>

#define GRAPH_SIZE 3

using namespace std;

template <class T>
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
    Graph (const Graph<T> &g1);
    ~Graph();
    int edge (int from, int to, int cost, bool true_if_add, bool true_if_replace_or_remove);
    void add_edge (int from, int to, int cost);
    void add_or_replace_edge (int from, int to, int cost);
    void remove_edge (int from, int to);
    int edge_cost (int from, int to);
    T value (int vertex_key, T recieved_value, bool true_if_add, bool true_if_replace_or_remove);
    void add_value (int vertex_key, T recieved_value);
    void add_or_replace_value (int vertex_key, T recieved_value);
    void remove_value (int vertex_key);
    T get_value (int vertex_key);
    Graph<T>& operator=(const Graph<T> &g1);
    
    friend ostream &operator<<(ostream &output, const Graph &g) {
        if (g.g_size == 0) {
            output << "No vertices in graph" << endl;
            return output;
        }
        output << "Number of vertices - " << g.g_size << "\n";
        for (int i = 0; i < g.g_size; ++i)
            output <<  "\t" << i;
        output << "\n";
        for (int i = 0; i < g.g_size; ++i) {
            output << i << "\t";
            for (int j = 0; j < g.g_size; ++j) 
                output << g.g_edges[i][j] << "\t";
            output << "\n";
        }
        for (int i = 0; i < g.g_size; ++i)
            output << i << "\t" << g.g_used_values[i] << "\t\t" <<g.g_values[i] << endl;
        return output;
    }

private:
    int **g_edges;
    T *g_values;
    int g_size;
    bool *g_used_values;
};

#endif