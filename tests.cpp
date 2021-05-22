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
    cout<<endl;




    cout << "Test_16_add_or_replace_edge_from_<_0:\n";
    try {
        g1->add_or_replace_edge(-1, 0, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_16\t\tpassed\n";
        else
            cout << "Test_16\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_16\t\tfailed\n";
    }
    cout << "Test_17_add_or_replace_edge_from_>_n:\n";
    try {
        g1->add_or_replace_edge(15, 0, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_17\t\tpassed\n";
        else
            cout << "Test_17\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_17\t\tfailed\n";
    }
    cout << "Test_18_add_or_replace_edge_to_<_0:\n";
    try {
        g1->add_or_replace_edge(0, -1, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_18\t\tpassed\n";
        else
            cout << "Test_18\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_18\t\tfailed\n";
    }
    cout << "Test_19_add_or_replace_edge_to_>_n:\n";
    try {
        g1->add_or_replace_edge(0, 15, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_19\t\tpassed\n";
        else
            cout << "Test_19\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_19\t\tfailed\n";
    }
    cout << "Test_20_add_or_replace_edge_loop:\n";
    try {
        g1->add_or_replace_edge(0, 0, 1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_20\t\tpassed\n";
        else
            cout << "Test_20\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_20\t\tfailed\n";
    }
    cout << "Test_21_add_or_replace_edge_cost_<_1:\n";
    try {
        g1->add_or_replace_edge(0, 1, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_21\t\tpassed\n";
        else
            cout << "Test_21\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_21\t\tfailed\n";
    }
    cout << "Test_22_add_or_replace_edge:\n";
    try {
        g1->add_or_replace_edge(0, 2, 2);
    } catch (...) {
        cout << "Test_22\t\tfailed\n"; 
    }
    cout << "Test_22\t\tpassed\n";
    cout << "Test_23_add_or_replace_edge_already_exists:\n";
    try {
        g1->add_or_replace_edge(0, 1, 3);
    } catch (...) {
        cout << "Test_23\t\tfailed\n";
    }
    cout << "Test_23\t\tpassed\n";
    cout<<endl;














    
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