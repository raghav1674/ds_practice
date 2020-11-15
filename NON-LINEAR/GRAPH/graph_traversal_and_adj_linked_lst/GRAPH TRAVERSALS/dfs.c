#include "graph.c"
#include "../stack_helper.c"

void depth_first_search(GRAPH *temp_graph)
{

    SNODE *top = NULL;

    push(&top, 0);

    temp_graph->status[0] = 0; // in queue

    int u, v;
    u = peek(top); // the top element in the stack

    while (!isEmpty(top))
    {
        printf("%d ", u); // process first
        temp_graph->status[u] = 1;
        pop(&top); // pop

        while (temp_graph->adjacency_linked_list[u] != NULL)
        { // it's neibhour

            v = temp_graph->adjacency_linked_list[u]->vertex;
            if (temp_graph->status[v] == -1)
            {

                push(&top, v);
                temp_graph->status[v] = 0;
            }
            temp_graph->adjacency_linked_list[u] = temp_graph->adjacency_linked_list[u]->next;
        }

        u = peek(top); // the top element in the stack
    }
}

int main()
{
    int num_vertices = 5;
    int num_edges = 7;
    GRAPH *my_graph = create_graph(num_vertices, num_edges);
   

    insert(my_graph);
    display_graph(my_graph);
    depth_first_search(my_graph);
}