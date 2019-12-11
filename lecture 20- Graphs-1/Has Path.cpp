#include <iostream>
#include<queue>
using namespace std;

void has_path(int **graph, int V, bool *visited, int sv, int ev)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    int flag = 0;
    while( !q.empty() )
    {
        for (int i=0; i<V; i++)
        {
            if (graph[q.front()][i] == 1)
            {
                if (visited[i] == true)
                    continue;
                else
                {
                    if(i == ev)
                    {
                        flag = 1;
                        break;
                    }
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        if(flag == 1)
            break;
        q.pop();   
    }
    if (flag == 1)
        cout<<"true";
    else
        cout<<"false";
    
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
    int sv,ev;
    cin>>sv>>ev;
    has_path(graph, V, visited, sv, ev);         //printing in BFS manner using queue
    
    delete[] visited;                        //deleting visited array
    for(int i=0; i<V; i++)
    {
        delete[] graph[i];                //deleting 2D adjacency matrix
    }
    delete[] graph;
    return 0;
}
