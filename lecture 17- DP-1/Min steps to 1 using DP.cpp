
#include<climits>
int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */
    int *arr = new int[n+1];
    for (int i = n; i>= 0; i--)
        arr[i] = i-1;
    for (int i = 2; i < n+1; i++)
    {
        int a = INT_MAX, b = INT_MAX;
        if (i % 2 == 0)
        {
            a =  arr[i/2] + 1;
        }
        if (i % 3 == 0)
        {
            b =  arr[i/3] + 1;
        }
        arr[i] = min(arr[arr[i]] + 1, min(a,b) );
    }
    return arr[n];
}
