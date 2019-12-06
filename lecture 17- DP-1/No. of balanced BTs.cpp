#include<cmath>
int helper(int h, int mod)
{
    if (h == 0 || h == 1)
        return 1;
    int x = helper(h-1, mod);
    int y = helper(h-2, mod);
    long res1 = (long)x*x;
    long res2 = (long)x*y*2;
    int value1 = (int)(res1 % mod);
    int value2 = (int)(res2 % mod);
    return (value1 + value2) % mod;
}



int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    int mod = pow(10,9) + 7;
    return helper(h, mod);
}
