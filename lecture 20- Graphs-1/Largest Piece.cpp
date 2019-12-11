int backtrack(char cake[NMAX][NMAX], int n, int i, int j, bool** visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n || cake[i][j] != '1' || visited[i][j] == true )
        return 0;
    if (cake[i][j] == '1')
        visited[i][j] = true;
    int up = backtrack(cake, n, i-1, j, visited);
    int left = backtrack(cake, n, i, j-1, visited);
    int right = backtrack(cake, n, i, j+1, visited);
    int down = backtrack(cake, n, i+1, j, visited);
    return up + left + right + down + 1;
}


int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    bool** visited = new bool*[n];
    for (int i=0; i<n; i++)
    {
        visited[i] = new bool[n];
    }
    for (int i=0; i<n; i++)
    {
        for(int j=0; j< n; j++)
            visited[i][j] = false;
    }
    int max = 0;
    int max1 = 0;
    for (int i=0; i< n; i++)
    {
        for (int j=0; j< n; j++)
        {
            if (cake[i][j] == '1' && visited[i][j] == false)
                max1 = backtrack(cake, n, i, j, visited);
            if (max1 > max)
                max = max1;
        }
    }
    for (int i=0; i< n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
    return max;
}
