#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> all_connected_components(int **graph, int V, bool *visited, int sv)
{
    queue<int> q;
    vector<vector<int>> output;
    while ( 1 )
    {
        q.push(sv);
        visited[sv] = true;
        int oldstart = sv;
        vector<int> arr;
        arr.push_back(sv);
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
                        arr.push_back(i);
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            q.pop();   
        }
        sort(arr.begin(), arr.end());          //given in question to print in ascending order 
        output.push_back(arr);
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
    return output;
}


int main() {
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> output;
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
    
    output = all_connected_components(graph, V, visited, 0);
    
    for(int i=0; i< output.size(); i++)
    {
        for (int j=0; j < output[i].size(); j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    
    delete[] visited;                        //deleting visited array
    for(int i=0; i<V; i++)
    {
        delete[] graph[i];                //deleting 2D adjacency matrix
    }
    delete[] graph;
  return 0;
}
