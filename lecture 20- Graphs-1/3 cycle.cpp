int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int** graph = new int*[n];
    for (int i=0; i<n; i++)
    {
        graph[i] = new int[n];
    }
    for (int i=0; i<m; i++)
    {
        graph[u[i]-1][v[i]-1] = 1;
        graph[v[i]-1][u[i]-1] = 1;
    }
    int count = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (graph[i][j] == 1)
            {
                for (int k=0; k<n; k++)
                {
                    if (k == i)
                        continue;
                    if (graph[j][k] == 1)
                    {
                        if (graph[i][k] == 1)
                            count++;
                    }
                }
            }
        }
    }
    return count/6;
}