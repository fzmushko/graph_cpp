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



    cout << "Test_8_add_edge_from_<_0:\n";
    try {
        g1->add_edge(-1, 0, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_8\t\tpassed\n";
        else
            cout << "Test_8\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_8\t\tfailed\n";
    }
    cout << "Test_9_add_edge_from_>_n:\n";
    try {
        g1->add_edge(15, 0, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_9\t\tpassed\n";
        else
            cout << "Test_9\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_9\t\tfailed\n";
    }
    cout << "Test_10_add_edge_to_<_0:\n";
    try {
        g1->add_edge(0, -1, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_10\t\tpassed\n";
        else
            cout << "Test_10\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_10\t\tfailed\n";
    }
    cout << "Test_11_add_edge_to_>_n:\n";
    try {
        g1->add_edge(0, 15, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_11\t\tpassed\n";
        else
            cout << "Test_11\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_11\t\tfailed\n";
    }
    cout << "Test_12_add_edge_loop:\n";
    try {
        g1->add_edge(0, 0, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_12\t\tpassed\n";
        else
            cout << "Test_12\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_12\t\tfailed\n";
    }
    cout << "Test_13_add_edge_cost_<_1:\n";
    try {
        g1->add_edge(0, 1, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_13\t\tpassed\n";
        else
            cout << "Test_13\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_13\t\tfailed\n";
    }
    cout << "Test_14_add_edge:\n";
    try {
        g1->add_edge(0, 1, 2);
    } catch (...) {
        cout << "Test_14\t\tfailed\n"; 
    }
    cout << "Test_14\t\tpassed\n";
    cout << "Test_15_add_edge_already_exists:\n";
    try {
        g1->add_edge(0, 1, 3);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EEXISTS)
            cout << "Test_15\t\tpassed\n";
        else
            cout << "Test_15\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_15\t\tfailed\n";
    }









    
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