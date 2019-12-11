#include <iostream>
#include<vector>
using namespace std;

vector<int> get_path_DFS(int **graph, int V, bool* visited, int sv, int ev)
{
    visited[sv] = true;
    if (sv == ev)
    {
        vector<int> arr;
        arr.push_back(sv);
        return arr;
    }
    for (int i=0; i<V; i++)
    {
        if (graph[sv][i] == 1)
        {
            if (visited[i] == true)
                continue;
            else
            {
                vector<int> arr = get_path_DFS(graph, V, visited, i, ev);
                if (arr.size() > 0)
                {
                    arr.push_back(sv);
                    return arr;
                }
                    
            }
        }
    }
    vector<int> arr;
    return arr;
}

int main()
{
    vector<int> arr;
    int V, E, tempX, tempY;
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
    
    arr = get_path_DFS(graph, V, visited, sv, ev);
    
    for (int i=0; i< arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    delete[] visited;                        //deleting visited array
    for(int i=0; i<V; i++)
    {
        delete[] graph[i];                //deleting 2D adjacency matrix
    }
    delete[] graph;

    return 0;
}
