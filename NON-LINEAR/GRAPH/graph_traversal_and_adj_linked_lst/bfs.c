#include "graph.c"
#include "queue_helper.c"

void breadth_first_search(GRAPH *temp_graph,int start_vertex)
{

    QNODE *front = NULL;
    QNODE *rear = NULL;

    enqueue(&front, &rear, start_vertex-1); // inserted the start vertex
    temp_graph->status[start_vertex-1] = 0; // in queue

    int u, v;
    while (!isEmpty(rear))
    {   
       
        u = peek(front, rear); // checking the first vertex at the front

        while (temp_graph->adjacency_linked_list[u] != NULL) // finding it's adjacent nodes and insert in the queue.
        {
            v = temp_graph->adjacency_linked_list[u]->vertex;
            
            if (temp_graph->status[v] == -1) // if  the vertex is not visited then only needed to be inserted in the queue.
            {
                enqueue(&front, &rear, v);
                temp_graph->status[v] = 0; // status: in queue.
            }
            temp_graph->adjacency_linked_list[u] = temp_graph->adjacency_linked_list[u]->next;
        }
        printf("%d ", u); //process
        temp_graph->status[u] = 1; // processed 
        dequeue(&front, &rear); // dequeue that vertex
    }
}

int main()
{
    int num_vertices = 5;
    int num_edges =5;
    GRAPH *my_graph = create_graph(num_vertices, num_edges);
    // for (int i = 0; i < 5; i++)
    //     printf("%d \n", my_graph->status[i]);

    insert(my_graph);
    display_graph(my_graph);
    breadth_first_search(my_graph,2);
}