int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int *dp = new int[value + 1];
    dp[0] = 1;
    for (int i=0; i<numDenominations; i++)
    {
        for (int j=denominations[i]; j<=value; j++)
        {
            dp[j] += dp[j-denominations[i]];
        }
    }
    int ans = dp[value];
    delete []dp;
    return ans;
}
