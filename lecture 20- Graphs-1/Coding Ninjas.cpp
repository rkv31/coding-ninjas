#include<string>
int backtrack(char Graph[][MAXN], int N, int M, int i, int j, string str, bool** visited)
{
     if (str.size() == 0)
        return 1;
    if (i < 0 || j < 0 || i >= N || j >= M || Graph[i][j] != str[0] || visited[i][j] == true)
        return 0;
    if (Graph[i][j] == str[0])
    {
        visited[i][j] = true;
        int lud = backtrack(Graph, N, M, i-1, j-1, str.substr(1), visited);
        int u = backtrack(Graph, N, M, i-1, j, str.substr(1), visited);
        int rud = backtrack(Graph, N, M, i-1, j+1, str.substr(1), visited);
        int left = backtrack(Graph, N, M, i, j-1, str.substr(1), visited);
        int right = backtrack(Graph, N, M, i, j+1, str.substr(1), visited);
        int ldd = backtrack(Graph, N, M, i+1, j-1, str.substr(1), visited);
        int d = backtrack(Graph, N, M, i+1, j, str.substr(1), visited);
        int rdd = backtrack(Graph, N, M, i+1, j+1, str.substr(1), visited);
        visited[i][j] = false;
        return lud || u || rud || left || right || ldd || d || rdd;
    }
}

int solve(char Graph[][MAXN],int N, int M)
{
	// Write your code here.
    string str = "CODINGNINJA";
    bool** visited = new bool*[N];
    for (int i=0; i<N; i++)
    {
        visited[i] = new bool[M];
    }
    for (int i=0; i<N; i++)
    {
        for(int j=0; j< M; j++)
            visited[i][j] = false;
    }
    int flag = 0;
    for (int i=0; i< N; i++)
    {
        for (int j=0; j< M; j++)
        {
            if (Graph[i][j] == 'C')
            {
                flag = backtrack(Graph, N, M, i, j, str, visited);
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
    }
    for (int i=0; i< N; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
    return flag;
}