#include<queue>
int count(int **graph, int V, bool *visited, int sv)
{
    queue<int> q;
    int count = 0;
    while ( 1 )
    {
        q.push(sv);
        count++;
        visited[sv] = true;
        int oldstart = sv;
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
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int **graph = new int*[n];
    for (int i=0; i<n; i++)
    {
        graph[i] = new int[n];
    }
    
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            graph[i][j] = 0;
    }
    bool *visited = new bool[n];
    for (int i=0; i<n; i++)
        visited[i] = false;
    
    for (int j=0; j<m; j++)
    {
        graph[u[j]-1][v[j]-1] = 1;
        graph[v[j]-1][u[j]-1] = 1;
    }
    
    int c = count(graph, n, visited, 0);
    
    for(int i=0; i<n; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;
    return c;
}