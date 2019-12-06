// int knapsack_helper(int *weights, int* values, int n, int maxWeight, int **output)
// {
//     if (n == 0 || maxWeight <= 0)
//         return 0;
//     if (output[n][maxWeight] != -1)
//         return output[n][maxWeight];
//     int ans;
//     if (weights[0] > maxWeight)
//         ans = knapsack_helper(weights + 1, values + 1, n - 1, maxWeight, output);
//     else
//     {
//         int inc = values[0] + knapsack_helper(weights + 1, values + 1, n-1, maxWeight-weights[0], output);
//         int not_inc = knapsack_helper(weights + 1, values + 1, n-1, maxWeight, output);
//         ans =  max(inc, not_inc);
//     }
//     output[n][maxWeight] = ans;
//     return ans;
// }

// int knapsack(int* weights, int* values, int n, int maxWeight){

//   /* Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//   */
//     int **output = new int*[n+1];
//     for (int i=0; i<=n; i++)
//     {
//         output[i] = new int[maxWeight + 1];
//         for (int j=0; j<= maxWeight; j++)
//             output[i][j] = -1;
//     }
//     return knapsack_helper(weights, values, n, maxWeight, output);
// }

int knapsack(int* weights, int* values, int n, int maxWeights)
{
//     int **output = new int*[n+1];                    using 2D arry
//     for (int i = 0; i<= n; i++)
//     {
//         output[i] = new int[maxWeights + 1];
//     }
    
    
//     for (int i = 0; i <= n; i++) 
//    { 
//        for (int j = 0; j <= maxWeights; j++) 
//        { 
//            if (i == 0 || j == 0) 
//                output[i][j] = 0; 
//            else if (weights[i-1] <= j) 
//                  output[i][j] = max(values[i-1] + output[i-1][j-weights[i-1]],  output[i-1][j]); 
//            else
//                  output[i][j] = output[i-1][j]; 
//        } 
//    } 
//     return output[n][maxWeights];
    
    
    int dp[maxWeights + 1];                //using 1D array
    for (int i=0; i <= maxWeights; i++)
        dp[i] = 0;
  
    for(int i=0; i < n; i++)  
    {
        //traverse dp array from right to left 
        for(int j = maxWeights; j>=weights[i]; j--) 
            dp[j] = max(dp[j] , values[i] + dp[j-weights[i]]); 
    }
    /*above line finds out maximum of  dp[j](excluding ith element value) 
      and val[i] + dp[j-wt[i]] (including ith element value and the 
      profit with "KnapSack capacity - ith element weight") */
        
    return dp[maxWeights];
}