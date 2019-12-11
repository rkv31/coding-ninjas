#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int* weight, bool* visited, int V)
{
    int minVertex = -1;
    for(int i=0; i<V; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]) )
            minVertex = i;
    }
    return minVertex;
}


void dijkstra(int** graph, int V)
{
    bool* visited = new bool[V];
    int* weight = new int[V];
    
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    
    weight[0] = 0;
    
    for (int i=0; i<V-1; i++)
    {
        int minVertex = findMinVertex(weight, visited, V);
        visited[minVertex] = true;
        for (int j=0; j<V; j++)
        {
            if ( graph[minVertex][j] != 0 && !visited[j] )
            {
                int dist = weight[minVertex] + graph[minVertex][j];
                if (dist < weight[j])
                {
                    weight[j] = dist;
                }
            }
        }
    }
    for (int i=0; i<V; i++)
        cout<<i<<" "<<weight[i]<<endl;
    
    delete[] visited;
    delete[] weight;
}


int main()
{
    int V, E;
    cin >> V >> E;
    
    int** graph = new int*[V];
    for(int i=0; i<V; i++)
    {
        graph[i] = new int[V];
        for (int j=0; j<V; j++)
            graph[i][j] = 0;
    }
    
    for(int i=0; i<E; i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        graph[s][d] = w;
        graph[d][s] = w;
    }
    
    dijkstra(graph,V);
    
    for(int i=0; i<V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
