#include <iostream>
#include<climits>
using namespace std;

int findMinVertex(int* weights, bool* visited, int V)
{
    int minVertex = -1;
    for (int i=0; i < V; i++)
    {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void prim(int** graph, int V)
{
    bool* visited = new bool[V];
    int* weights = new int[V];
    int* parent = new int[V];
    for (int i=0; i<V; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;
    
    for(int i=0; i<V; i++)
    {
        int minVertex = findMinVertex(weights, visited, V);
        visited[minVertex] = true;
        for(int j=0; j < V; j++)
        {
            if ( graph[minVertex][j] != 0 && !visited[j] )
            {
                if ( graph[minVertex][j] < weights[j])
                {
                    weights[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i=1; i< V; i++)
    {
        if (parent[i] < i)
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        else
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
    }
    delete[] visited;
    delete[] weights;
    delete[] parent;
    
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    int** graph = new int*[V];
    for (int i=0; i<V; i++)
    {
        graph[i] = new int[V];
        for (int j=0; j<V; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i=0; i<E; i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[v1][v2] = w;
        graph[v2][v1] = w;
    }
    
    prim(graph, V);
    
    for (int i=0; i<V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}
