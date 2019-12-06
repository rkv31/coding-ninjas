#include<cmath>
int res = 0;
int checkRecursive(int num, int x, int k, int n) 
{ 
    if (x == 0)  
        res++; 
      
    int r = (int)floor(pow(num, 1.0 / n)); 
  
    for (int i = k + 1; i <= r; i++)  
    { 
        int a = x - (int)pow(i, n); 
        if (a >= 0) 
            checkRecursive(num, a, i, n); 
    } 
    return res; 
} 







int allWays(int x, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return checkRecursive(x, x, 0, n);
}

