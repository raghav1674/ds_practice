#include "graph.c"
#include "stack_helper.c"

void depth_first_search(GRAPH *temp_graph, int start_vertex)
{

    SNODE *top = NULL;

    push(&top, start_vertex - 1);

    temp_graph->status[start_vertex - 1] = 0; // in queue

    int u, v;
    while (!isEmpty(top))
    {

        u = peek(top); // the top element in the queue.

        // push its adjacent vertices in the stack.

        while (temp_graph->adjacency_linked_list[u] != NULL)
        { // it's neibhour

            v = temp_graph->adjacency_linked_list[u]->vertex;
            if (temp_graph->status[v] != -1)
            {

                push(&top, v);
                temp_graph->status[v] = 0;
            }
            temp_graph->adjacency_linked_list[u] = temp_graph->adjacency_linked_list[u]->next;
        }
        // process it and mark it as -1.
        printf("%d ", u);

        temp_graph->status[u] = -1;

        pop(&top);
    }
}

int main()
{
    int num_vertices = 6;
    int num_edges =9;
    GRAPH *my_graph = create_graph(num_vertices, num_edges);
    // for (int i = 0; i < 5; i++)
    //     printf("%d \n", my_graph->status[i]);

    insert(my_graph);
    display_graph(my_graph);
    depth_first_search(my_graph,1);
}