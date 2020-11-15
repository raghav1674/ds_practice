#include "../graph_adj_helper.c"

typedef struct Graph
{

    int num_vertices;
    int num_edges;
    int *status;
    Vertex **adjacency_linked_list;

} GRAPH;

GRAPH *create_graph(int num_vertex, int num_edges)
{

    GRAPH *new_graph = (GRAPH *)malloc(sizeof(GRAPH));

    new_graph->num_vertices = num_vertex;

    new_graph->num_edges = num_edges;

    new_graph->status = (int *)malloc(sizeof(int) * num_vertex);

    new_graph->adjacency_linked_list = (Vertex **)malloc(sizeof(Vertex *) * num_vertex);

    for (int i = 0; i < num_vertex; i++)
    {
        new_graph->adjacency_linked_list[i] = NULL;
        new_graph->status[i] = -1;
    }
    return new_graph;
}

// void insert(GRAPH *temp_graph)
// {

//     EDGE *pair = (EDGE *)malloc(sizeof(EDGE) * temp_graph->num_edges);
//     printf("Enter the neibhouring vertices (separated by spaces):  \n\n");
//     for (int i = 0; i < temp_graph->num_edges; i++)
//     {
//         printf("Enter the %d pair: ", i + 1);
//         scanf("%d %d", &pair[i].u, &pair[i].v);

//         if (pair[i].u != pair[i].v)
//             insert_vertex(&(temp_graph->adjacency_linked_list[pair[i].u - 1]), (pair[i].v) - 1);
//         insert_vertex(&(temp_graph->adjacency_linked_list[(pair[i].v) - 1]), (pair[i].u) - 1);
//     }
// }

void display_graph(GRAPH *temp_graph)
{

    Vertex *temp_vertex;
    for (int i = 0; i < temp_graph->num_vertices; i++)
    {

        temp_vertex = temp_graph->adjacency_linked_list[i];
        printf("[%d]-->", i + 1);
        while (temp_vertex != NULL)
        {
            printf(" %d -->", temp_vertex->vertex + 1);

            temp_vertex = temp_vertex->next;
        }
        puts("");
    }
}
