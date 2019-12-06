#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int **input, int i, int j, int m, int n)
{
    if (i > m-1 || j > n-1)
        return INT_MAX;
    else if( i == m-1 && j == n-1)
        return input[i][j];
    else
    {
        int down = helper(input, i+1, j, m, n);
        int side = helper(input, i, j+1, m, n);
        int diag = helper(input, i+1, j+1, m, n);
    
        return input[i][j] + min(diag, min(side, down));    
    }
    
}


int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return helper(input, 0, 0, m, n);
}
