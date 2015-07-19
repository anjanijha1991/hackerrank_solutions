#include <stdio.h>
#include <stdlib.h>


struct nodelist
{
  int d;
  int v;
  struct adjnode *nextnode;
};


struct adjnode
{
  int id;
  struct adjnode *nextnode;
};


void
addEdge (struct nodelist *graph, int source, int dest)
{
  struct adjnode *edge1 = (struct adjnode *) malloc (sizeof (struct adjnode));
  struct adjnode *edge2 = (struct adjnode *) malloc (sizeof (struct adjnode));
  struct adjnode *temp = NULL;

  edge1->id = dest;
  edge2->id = source;
  edge1->nextnode = NULL;
  edge2->nextnode = NULL;


  temp = graph[source].nextnode;
  graph[source].nextnode = edge1;
  edge1->nextnode = temp;

  temp = graph[dest].nextnode;
  graph[dest].nextnode = edge2;
  edge2->nextnode = temp;



  return;
}


void
initGraph (struct nodelist *graph, int no_of_nodes)
{
  int i = 0;

  for (i = 0; i < no_of_nodes; i++)
    {
      graph[i].d = 0;
      graph[i].v = 0;
      graph[i].nextnode = NULL;

    }

}

void
dfs (struct nodelist *graph, int source_id, int no_of_nodes)
{
  int *queue = (int *) malloc (sizeof (int)* no_of_nodes);

  int head = 0, tail = 0;
  int temp_parent;
  struct adjnode *temp_node = NULL;

  queue[tail++] = source_id;
  graph[source_id].v = 1;

  while (head != tail)
    {
      // extract element
      temp_parent = queue[head++];

      temp_node = graph[temp_parent].nextnode;

      // add adjacent element ids in the queue if not visited
      while (temp_node)
	{
	  if (graph[temp_node->id].v == 0)
	    {
	      queue[tail++] = temp_node->id;

	      graph[temp_node->id].v = 1;
	      graph[temp_node->id].d = (graph[temp_parent].d) + 1;
	    }
	  temp_node = temp_node->nextnode;
	}

    }

  for (head = 0; head < no_of_nodes; ++head)
    {
      if (head != source_id)
	{
	  printf ("%d ", (graph[head].d > 0) ? (6 * graph[head].d) : (-1));

	}
    }
  printf ("\n");

  free (queue);

}

int
main (void)
{

  int no_of_nodes, no_of_edges;
  int test;
  int i, j;
  int source, dest;
  struct nodelist *nodes = NULL;

  scanf ("%d", &test);
  while (test--)
    {
      scanf ("%d %d", &no_of_nodes, &no_of_edges);

      nodes = (struct nodelist *) malloc (sizeof (struct nodelist) * no_of_nodes);
      initGraph (nodes, no_of_nodes);

      for (i = 0; i < no_of_edges; ++i)
	{
	  scanf ("%d %d", &source, &dest);
	  addEdge (nodes, source - 1, dest - 1);
	}
      scanf ("%d", &source);
      dfs (nodes, source - 1, no_of_nodes);
      free (nodes);

    }
  return EXIT_SUCCESS;
}
