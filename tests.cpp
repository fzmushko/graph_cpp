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







    cout << "Test_24_remove_edge_from_<_0:\n";
    try {
        g1->remove_edge(-1, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_24\t\tpassed\n";
        else
            cout << "Test_24\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_24\t\tfailed\n";
    }
    cout << "Test_25_remove_edge_from_>_n:\n";
    try {
        g1->remove_edge(15, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_25\t\tpassed\n";
        else
            cout << "Test_25\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_25\t\tfailed\n";
    }
    cout << "Test_26_remove_edge_to_<_0:\n";
    try {
        g1->remove_edge(0, -1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_26\t\tpassed\n";
        else
            cout << "Test_26\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_26\t\tfailed\n";
    }
    cout << "Test_27_remove_edge_to_>_n:\n";
    try {
        g1->remove_edge(0, 15);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_27\t\tpassed\n";
        else
            cout << "Test_27\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_27\t\tfailed\n";
    }
    cout << "Test_28_remove_edge_loop:\n";
    try {
        g1->remove_edge(0, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_28\t\tpassed\n";
        else
            cout << "Test_28\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_28\t\tfailed\n";
    }
    cout << "Test_29_remove_edge:\n";
    try {
        g1->remove_edge(0, 2);
    } catch (...) {
        cout << "Test_29\t\tfailed\n"; 
    }
    cout << "Test_29\t\tpassed\n";
    cout << "Test_30_remove_edge_already_not_exists:\n";
    try {
        g1->remove_edge(1, 0);
    } catch (...) {
        cout << "Test_30\t\tfailed\n";
    }
    cout << "Test_30\t\tpassed\n";
    cout<<endl;





    int x;
    cout << "Test_31_edge_cost_from_<_0:\n";
    try {
        x = g1->edge_cost(-1, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_31\t\tpassed\n";
        else
            cout << "Test_31\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_31\t\tfailed\n";
    }
    cout << "Test_32_edge_cost_from_>_n:\n";
    try {
        x = g1->edge_cost(15, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_32\t\tpassed\n";
        else
            cout << "Test_32\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_32\t\tfailed\n";
    }
    cout << "Test_33_edge_cost_to_<_0:\n";
    try {
        x = g1->edge_cost(0, -1);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_33\t\tpassed\n";
        else
            cout << "Test_33\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_33\t\tfailed\n";
    }
    cout << "Test_34_edge_cost_to_>_n:\n";
    try {
        x = g1->edge_cost(0, 15);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_34\t\tpassed\n";
        else
            cout << "Test_34\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_34\t\tfailed\n";
    }
    cout << "Test_35_edge_cost_loop:\n";
    try {
        x = g1->edge_cost(0, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::EINVARG) 
            cout << "Test_35\t\tpassed\n";
        else
            cout << "Test_35\t\tfailed\n"; 
    } catch (...) {
        cout << "Test_35\t\tfailed\n";
    }
    cout << "Test_36_edge_cost:\n";
    try {
        x = g1->edge_cost(0, 1);
    } catch (...) {
        cout << "Test_36\t\tfailed\n";
    }
    if (x == 3)
        cout << "Test_36\t\tpassed\n";
    else 
        cout << "Test_36\t\tfailed\n";
    cout << "Test_37_edge_cost_not_exists:\n";
    try {
        x = g1->edge_cost(1, 0);
    } catch (Graph::graph_error &ex) {
        if (ex == Graph::ENEXISTS)
            cout << "Test_37\t\tpassed\n";
        else
            cout << "Test_37\t\tfailed\n";
    } catch (...) {
        cout << "Test_37\t\tfailed\n";
    }
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