#include <stdio.h>
#include <stdlib.h>

struct graph_head
{
    int no_of_nodes;
    int no_of_edges;

    struct adjlist *nodelist;
};

struct adjlist
{
    int d,f;

    struct adjnodelist *adjnode;
};

struct adjnodelist
{
    int id;
    struct adjnodelist *nextnode;
};


struct graph_head*
create_graph(int nodes, int edges)
{
    int i = 0;
    struct graph_head* Graph = (struct graph_head*) malloc(sizeof(struct graph_head));
    if(! Graph)
    {
        fprintf(stderr,"MEMORY ALLOCATION FAILED @ %s", __func__);
        exit(0);
    }
    Graph->no_of_nodes = nodes;
    Graph->no_of_edges = edges;
    Graph->nodelist = (struct adjlist*)malloc(nodes * sizeof(struct adjlist));
    if( !Graph->nodelist)
    {
        fprintf(stderr,"MEMORY ALLOCATION FAILED @ %s", __func__);
        exit(0);
    }

    for( ; i < nodes; ++i)
    {
        Graph->nodelist[i].adjnode = NULL;
        Graph->nodelist[i].d = 0;
        Graph->nodelist[i].f = 0;

    }

    return Graph;
}


void
add_edge(struct graph_head* Graph, int source, int dest)
{ 
    struct adjnodelist *dest_node = (struct adjnodelist *) malloc(sizeof(struct adjnodelist));
    dest_node->id = dest;
    dest_node->nextnode = Graph->nodelist[source].adjnode;
    Graph->nodelist[source].adjnode = dest_node;

    struct adjnodelist *source_node = (struct adjnodelist *) malloc(sizeof(struct adjnodelist));
    source_node->id = source;
    source_node->nextnode = Graph->nodelist[dest].adjnode;
    Graph->nodelist[dest].adjnode = source_node;

}


int time;
int* visited;



void
DFS(struct graph_head* g, int current_node)
{
    time ++;
    g->nodelist[current_node].d = time;
    struct adjnodelist* current = g->nodelist[current_node].adjnode;

    while(current)
    {
        if(! visited[current->id])
        {
            visited[current->id] = 1;
            DFS(g, current->id);
        }
        current = current->nextnode;
    }
    time ++;
    g->nodelist[current_node].f = time;

}


int
main(void)
{
    int no_of_nodes,no_of_edges;
    int i = 0, source, dest;
    int count = 0;
    struct graph_head* g = NULL;

    scanf("%d %d",&no_of_nodes,&no_of_edges);
     g = create_graph( no_of_nodes, no_of_edges);

    visited = (int *)calloc(no_of_nodes, sizeof(int));
    for( ; i < no_of_nodes; visited[i] = 0,++i);

    for(i = 0; i < no_of_edges; ++i)
    {
        scanf("%d %d",&source, &dest);
        add_edge(g,source - 1, dest - 1);
    }
    time = 0;
    for(i = 0; i < no_of_nodes; ++i)
    {
        if(! visited[i])
        {
            visited[i] = 1;
            DFS(g, i);
        }
    }

    for( i = 0; i < no_of_nodes; ++i)
    {
        if(((g->nodelist[i].f - g->nodelist[i].d + 1) / 2) %2 == 0)
            count ++;

    }
    
    printf("%d\n",count - 1);

    return 0;
}
