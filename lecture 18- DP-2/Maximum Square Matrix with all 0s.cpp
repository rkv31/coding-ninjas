#include<algorithm>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int **S = new int*[row];
    for (int i=0; i<row; i++)
    {
        S[i] = new int[col];
    }
    for (int i=0; i< row; i++)
    {
        if (arr[i][0] == 0)
            S[i][0] = 1;
        else
            S[i][0] = 0;
    }
        
    for (int i=0; i< col; i++)
    {
        if (arr[0][i] == 0)
            S[0][i] = 1;
        else
            S[0][i] = 0;
    }
        
    for (int i=1; i < row; i++)
    {
        for (int j=1; j< col; j++)
        {
            if (arr[i][j] == 0)
                S[i][j] = min(S[i-1][j], min(S[i][j-1], S[i-1][j-1])) + 1;
            else
                S[i][j] = 0;
        }
    }
    
    int max_data = S[0][0];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (max_data < S[i][j])
            {
                max_data = S[i][j];
            }
        }
    }
    delete []S;
    return max_data;
    
}