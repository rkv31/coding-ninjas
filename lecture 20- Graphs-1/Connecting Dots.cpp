int backtrack(char board[][MAXN], int N, int M, int i, int j, int k, bool** visited, int si, int sj, int previ, int prevj)
{
    if (i < 0 || j < 0 || i >= N || j >=M || visited[i][j] == true || board[previ][prevj] != board[i][j])
        return 0;
    if ( i == si && j == sj && k != 1 )
    {
        if (k >= 4)
            return 1;
        else
            return 0;
    }
    if (k != 1)
        visited[i][j] = true;
    int uld = backtrack(board, N, M, i-1, j-1, k+1, visited, si, sj, i, j);
    int u = backtrack(board, N, M, i-1, j, k+1, visited, si, sj, i, j);
    int urd = backtrack(board, N, M, i-1, j+1, k+1, visited, si, sj, i, j);
    int left = backtrack(board, N, M, i, j-1, k+1, visited, si, sj, i, j);
    int right = backtrack(board, N, M, i, j+1, k+1, visited, si, sj, i, j);
    int dld = backtrack(board, N, M, i+1, j-1, k+1, visited, si, sj, i, j);
    int d = backtrack(board, N, M, i+1, j, k+1, visited, si, sj, i, j);
    int drd = backtrack(board, N, M, i+1, j+1, k+1, visited, si, sj, i, j);
    if ((uld || u || urd || left || right || dld || d || drd) != 1)
    {
        visited[i][j] = false;
        return 0;
    }
    else
        return 1;
}


int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    bool** visited = new bool*[n];
    for (int i=0; i<n; i++)
    {
        visited[i] = new bool[m];
    }
    for (int i=0; i<n; i++)
    {
        for(int j=0; j< m; j++)
            visited[i][j] = false;
    }
    int flag = 0;
    for (int i=0; i< n; i++)
    {
        for (int j=0; j< m; j++)
        {
            flag = backtrack(board, n, m, i, j, 1, visited, i, j, i, j);
            if (flag == 1)
                break;
        }
    }
    for (int i=0; i< n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
    return flag;
}