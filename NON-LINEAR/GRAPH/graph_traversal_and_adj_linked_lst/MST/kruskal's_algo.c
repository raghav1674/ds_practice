#include "../GRAPH TRAVERSALS/graph.c"

typedef struct Edge{

    int src,dest,weight;

}EDGE;


void kruskal_algo(GRAPH* temp_graph){


    // set of all the vertices which will store which vertices are connected to each other.
    int* set=(int*)malloc(sizeof(int)*temp_graph->num_vertices);
    for(int i=0;i<temp_graph->num_vertices;i++)
            set[i]=i;


    // array of all edges which is traversed 
    EDGE* edges=(EDGE*)malloc(sizeof(EDGE)*temp_graph->num_edges);
    
    // all the final edges would be in this array.
    EDGE* final_edges=(EDGE*)malloc(sizeof(EDGE)*temp_graph->num_edges);

    // take the edges along with the weight.

    printf("Enter the source , destination and the weight of the edges(separated by spaces):\n");
    for(int i=0;i<temp_graph->num_edges;i++){

            // take the u , v and weight
            printf("Enter the edge %d:\n",i+1);
            scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
        insert_vertex(&temp_graph->adjacency_linked_list[edges[i].src-1],edges[i].dest-1);
        insert_vertex(&temp_graph->adjacency_linked_list[edges[i].dest-1],edges[i].src-1);
        





    }
    // sort the edges array based on the weights given

    // for sorting purpose
    EDGE temp;
    for(int i=0;i<temp_graph->num_edges;i++){


        for(int j=0;j<temp_graph->num_edges-i-1;j++)
            {

                if(edges[j].weight>edges[j+1].weight){

                    temp=edges[j];
                    edges[j]=edges[j+1];
                    edges[j+1]=temp;

                }
            }
    }

    // printing sorted edges array

    // for(int i=0;i<temp_graph->num_edges;i++){

    //     printf("%d ",edges[i].weight);
    // }
    // printf("---------------------\n");


    // now the edges has been sorted.

    // count the umber of edges reuired to form a MST.
    int count=0;
    for(int k=0;k<temp_graph->num_edges;k++){

            int t;
            // find-set
            if(set[edges[k].src-1] != set[edges[k].dest-1]){ // if the edges donot belong to the same group then add it.

                t=set[edges[k].dest-1]; // store the value of set[v] vertex

                // union-set
                set[edges[k].dest-1]=set[edges[k].src-1]; // add the value at u to v in set

                
                for(int j=0;j<temp_graph->num_vertices;j++){ // find all those vertices whose value is v update them as u vertice value.
    
                    if(set[j]==t)
                        set[j]=set[edges[k].src-1];  // IMPORTANT: NOTICE:::we need to replace with the value in the set not with the edge u value.
                }
                // printing the result
                // printf("\t%d w-[%d] ,",k+1,edges[k].weight);

                // adding to the final_edges array
                final_edges[count]=edges[k];
                count++;
            }



            // printing the set for debugging purpose.

             printf("\n");
               for(int i=0;i<temp_graph->num_vertices;i++){

        printf("%d ",set[i]);
    }

    

            }
   
       // actual final edges 
        printf("\n");
       int total_min_distance=0;
       for(int i=0;i<count;i++){

           printf("(%d,%d)  [%d units] ;",final_edges[i].src,final_edges[i].dest,final_edges[i].weight);
           total_min_distance+=final_edges[i].weight;
       }
    
        printf("\nMinimum Cost: %d units",total_min_distance);



    }

int main(){


    GRAPH* my_graph=create_graph(4,5);

    kruskal_algo(my_graph);

    printf("\n");
    display_graph(my_graph);


    return 0;
}






