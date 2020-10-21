#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// a graph will have a count of vertex and the count of the edges and the adjanency matrix of 2 -d square matrix which would contain the info abut connections with the vertices.
typedef struct Graph
{

    int vertices;
    int edges;
    int **adjanency_matrix;

} GRAPH;

// we need to store the number of edges and the two points of the edges
typedef struct edges
{

    int u, v;

} EDGE;

// creates a graph.

GRAPH *create_graph(int num_vertices, int num_edges)
{

    GRAPH *new_graph = (GRAPH *)malloc(sizeof(GRAPH));
    new_graph->vertices = num_vertices;
    new_graph->edges = num_edges;
    // now we need to create an adjanency which would be of the size of the num of vertices and then each element of the array would be apointer which stores all the vertices neighbour info.

    new_graph->adjanency_matrix = (int **)malloc(sizeof(int *) * num_vertices); // creating an array which would contain num of vertices times pointers.
    for (int i = 0; i < num_vertices; i++)
    {
        // now each pointer will be of num of vertices array
        new_graph->adjanency_matrix[i] = (int *)malloc(sizeof(int) * num_vertices);
        for (int j = 0; j < num_vertices; j++)
            new_graph->adjanency_matrix[i][j] = 0; //initially stroing zero in all places.
    }
    return new_graph;
}

// will return the edges array.

EDGE *_take_edges(GRAPH *temp_graph)
{
    printf("Enter the neighbour vertex pair (separated with space)\n");
    int num_edges = temp_graph->edges;

    EDGE *array = (EDGE *)malloc(sizeof(EDGE) * num_edges);
    for (int i = 0; i < num_edges; i++)
    {

        printf("Enter the Edge Pair Number %d: ", i + 1);
        scanf("%d %d", &array[i].u, &array[i].v); //array[i] is a edge (so &array[i].u ==&e.u)
    }
    return array;
}

// will insert  1 where there is an edge

void insert(GRAPH **temp_graph)
{

    EDGE *temp_edges_Array = _take_edges(*temp_graph);

    for (int i = 0; i < (*temp_graph)->edges; i++)
    {
        if (temp_edges_Array[i].u != temp_edges_Array[i].v)//if both are not equal then only insert it in both arr[u][v] and arr[v][u]

            (*temp_graph)->adjanency_matrix[temp_edges_Array[i].u - 1][temp_edges_Array[i].v - 1] = 1; // storing in arr[i][j]=1 and arr[j][i]=1 as it is undirected graph.

        (*temp_graph)->adjanency_matrix[temp_edges_Array[i].v - 1][temp_edges_Array[i].u - 1] = 1;
    }
}

// displays the graph in adj matrix format
void display(GRAPH *temp_graph)
{

    for (int k = 0; k < temp_graph->vertices; k++)
        printf("\t[v%d]", k + 1);
    printf("\n\n");
    for (int i = 0; i < temp_graph->vertices; i++)
    {
        printf("[v%d]", i + 1);

        for (int j = 0; j < temp_graph->vertices; j++)
        {

            printf("\t %d ",  temp_graph->adjanency_matrix[i][j]);

           
        }
        printf("\n\n");
    }
}

int main()
{

    int num_edges;
    int num_vertices;
    printf("Enter the number of vertices and the edges: ");
    scanf("%d %d", &num_vertices, &num_edges);
    GRAPH *my_graph = create_graph(num_vertices, num_edges);

    printf("\n");
    insert(&my_graph);
    printf("\nPrinting the Graph: \n\n");
    display(my_graph);

    return 0;
}