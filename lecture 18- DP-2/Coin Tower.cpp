string solve(int n, int x, int y)
{
	// Write your code here .
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=n; i++)
    {
        if (i-1 >=0 && dp[i-1] == 0)
            dp[i] = 1;
        else if (i-x >= 0 && dp[i-x] == 0)
            dp[i] = 1;
        else if (i-y >= 0 && dp[i-y] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    int ans = dp[n];
    delete []dp;
    if (ans == 0)
        return "Whis";
    else
        return "Beerus";
    
}