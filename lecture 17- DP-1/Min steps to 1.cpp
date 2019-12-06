#include<climits>
int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */
    if (n <= 1)
        return 0;
    int a = countStepsTo1(n-1);
    int b = INT_MAX;
    int c = INT_MAX;
    if (n % 2 == 0)
        b = countStepsTo1(n/2);
    if (n % 3 == 0)
        c = countStepsTo1(n/3);
    return min(a, min(b,c)) + 1;
}
