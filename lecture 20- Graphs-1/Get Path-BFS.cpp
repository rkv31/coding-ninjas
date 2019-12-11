#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> get_path_BFS(int** graph, int V, bool* visited, int sv, int ev)
{
    queue<int> q;
    unordered_map<int, int> ump;
    vector<int> arr;
    int flag = 0;
    visited[sv] = true;
    q.push(sv);
    while ( !q.empty() )
    {
        sv = q.front();
        for(int i=0 ;i< V; i++)
        {
            if (graph[sv][i] == 1)
            {
                if (visited[i] == true)
                    continue;
                else
                {
                    q.push(i);
                    visited[i] = true;
                    ump[i] = sv;
                    if (i == ev)
                    {
                        arr.push_back(ev);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1)
            break;
        q.pop();
    }
    while(ump.find(ev) != ump.end())
    {
        ev = ump.at(ev);
        arr.push_back(ev);
    }
    
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
    arr = get_path_BFS(graph, V, visited, sv, ev);
    for(int i=0; i< arr.size(); i++)
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
