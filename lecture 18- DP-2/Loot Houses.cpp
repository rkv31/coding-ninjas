#include<algorithm>
using namespace std;
int helper(int arr[], int n, int i)
{
    if (i >= n)
        return 0;
    int a = arr[i] + helper(arr, n, i+2);
    int b = helper(arr, n, i+1);
    return max(a,b);
}

int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    // return helper(arr,n,0);
    
     if (n == 0) 
        return 0; 
    if (n == 1) 
        return arr[0]; 
    if (n == 2) 
        return max(arr[0], arr[1]); 
    int *dp = new int[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i=2; i< n; i++)
    {
        dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
    }
    int ans = dp[n-1];
    delete []dp;
    return ans;
}
