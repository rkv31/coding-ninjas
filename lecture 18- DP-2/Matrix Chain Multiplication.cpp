#include<climits>
int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    int m[n+1][n+1]; 
  
    int j,q;
    for (int i = 1; i < n+1; i++) 
        m[i][i] = 0; 
    for (int d = 2; d < n+1; d++) 
    { 
        for (int i = 1; i < n - d + 2; i++) 
        { 
            j = i + d - 1; 
            m[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) 
            { 
                q = m[i][k] + m[k + 1][j] +  p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
    return m[1][n]; 
}
