#include "graph.h"
#include <iostream>

using namespace std;

int main() { 
    Graph *g1 = NULL;
    Graph *g2 = NULL;

    try {
        g1 = new Graph (-1);
    } catch (const bad_alloc& ex) {
        cout << "Test_0\tpassed" << endl;
    } catch (...) {
        cout << "Test_0\tfailed" << endl;
    }

    cout << "Test_1_create_graph" << endl;
    try {
        g1 = new Graph();
    } catch (...) {
        cout << "Test_1\tfailed" << endl;
    }
    cout << "Test_1\tpassed" << endl;
    cout << "Test_2_create_graph_with_size" << endl;
    try {
        g2 = new Graph(0);
    } catch (...) {
        cout << "Test_2\tfailed" << endl;
    }
    cout << "Test_2\tpassed" << endl;
    









    
    cout << g1;

    cout << g2;
    g2 = NULL;
    try {
        cout << g2;
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_print_NULL\tpassed\n";
        else
            cout << "Test_print_NULL\tfailed\n";
    } catch (...) {
        cout << "Test_print_NULL\tfailed\n";
    }
    

    delete g1;
    delete g2;



    return 0;
}