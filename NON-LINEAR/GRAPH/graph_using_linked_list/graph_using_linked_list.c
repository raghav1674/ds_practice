//ADJACENCY LIST REPRESENTATION.

#include "nodes.c"

void print_one_node_neighbours(NODE *head)
{

    if (head)
    {
        printf("%s --> ", head->data);

        head = head->next;
        print_one_node_neighbours(head);
    }
}




int main()
{

    NODE *GRAPH_EDGES[6];

    // initializing with NULL at the begining all the head pointers we have created.

    for (int i = 0; i < 6; i++)
        GRAPH_EDGES[i] = NULL;


    push_back(&GRAPH_EDGES[0], "v1");
    push_back(&GRAPH_EDGES[0], "v4");

    // printf("%s", (GRAPH_EDGES[0])->data);

    // push_back(&GRAPH_EDGES[0], "v3"); 
    // we need to pass the address of the node as it is pass by reference and GRAPH_EDGES[0] is equal to headpointer and &head we are passing ..
    push_back(&GRAPH_EDGES[1], "v2");


    // push_back(&GRAPH_EDGES[1], "v1");
    // push_back(&GRAPH_EDGES[1], "v3");
    // push_back(&GRAPH_EDGES[1], "v4");
    push_back(&GRAPH_EDGES[2], "v3");


    // push_back(&GRAPH_EDGES[2], "v1");
    // push_back(&GRAPH_EDGES[2], "v2");
    // push_back(&GRAPH_EDGES[2], "v4");
    // push_back(&GRAPH_EDGES[2], "v5");
    // push_back(&GRAPH_EDGES[2], "v6");
    push_back(&GRAPH_EDGES[3], "v4");
    // push_back(&GRAPH_EDGES[3], "v2");
    // push_back(&GRAPH_EDGES[3], "v3");
    // push_back(&GRAPH_EDGES[3], "v6");
    push_back(&GRAPH_EDGES[4], "v4");
    push_back(&GRAPH_EDGES[4], "v1");
    // push_back(&GRAPH_EDGES[5], "v6");
    // push_back(&GRAPH_EDGES[5], "v3");
    // push_back(&GRAPH_EDGES[5], "v4");

    print_one_node_neighbours(GRAPH_EDGES[0]);
    printf("\n");
    print_one_node_neighbours(GRAPH_EDGES[1]);
    printf("\n");
    print_one_node_neighbours(GRAPH_EDGES[2]);
    printf("\n");
    print_one_node_neighbours(GRAPH_EDGES[3]);
    printf("\n");
    print_one_node_neighbours(GRAPH_EDGES[4]);
    printf("\n");
    print_one_node_neighbours(GRAPH_EDGES[5]);

    return 0;
}