#include <iostream>
#include<queue>
using namespace std;

void print(int **graph, int V, bool *visited, int sv)
{
    queue<int> q;
    while ( 1 )
    {
        q.push(sv);
        visited[sv] = true;
        int oldstart = sv;
        while( !q.empty() )
        {
            cout<<q.front()<<" ";
            for (int i=0; i<V; i++)
            {
                if (graph[q.front()][i] == 1)
                {
                    if (visited[i] == true)
                        continue;
                    else
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            q.pop();   
        }
        for (int i=0; i<V; i++)                //used for finding any non visited vertices, 
        {                                       //this will come in play when there is disconnected graph
            if (visited[i] == false)
            {
                sv = i;
                break;
            }
        }
        if (sv == oldstart)               //if the old start doesn't change, this means graph is completely traversed    
            break;
    }
}


int main() {
    int V, E;
    cin >> V >> E;
    
    bool *visited = new bool[V];        //to marks the visited vertices
    for (int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    
    int **graph = new int*[V];            //Adjacency matrix
    for (int i=0; i<V; i++)
    {
        graph[i] = new int[V];
    }
    for (int i=0; i<V; i++)            //Initialing adjacency matrix to 0
    {
        for (int j=0; j<V; j++)
            graph[i][j] = 0;
    }
    
    for (int i=0; i<E; i++)
    {
        int f,s;
        cin>>f>>s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    
    print(graph, V, visited, 0);         //printing in BFS manner using queue
    
    delete[] visited;                        //deleting visited array
    for(int i=0; i<V; i++)
    {
        delete[] graph[i];                //deleting 2D adjacency matrix
    }
    delete[] graph;
  return 0;
}
