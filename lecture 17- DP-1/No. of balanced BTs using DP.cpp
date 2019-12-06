#include<cmath>
int binaryTreesOfHeightH(int h) {
    // Write your code here
    if (h == 0)
        return 1;
    int *ans = new int[h+1];
    ans[0] = ans[1] = 1;
    int mod = (int)pow(10,9) + 7;
    for(int i = 2; i <= h; i++)
    {
        // Cast to long 
        long temp1 = (long) (ans[i - 1]) * ans[i - 1];
        temp1 = temp1 % mod; 
        // Cast to long
        long temp2 = 2 * (long) (ans[i - 1]) * ans[i - 2]; 
        temp2 = temp2 % mod;
        ans[i] = (int) (temp1 + temp2) % mod; 
    }
    return ans[h]; 
}

