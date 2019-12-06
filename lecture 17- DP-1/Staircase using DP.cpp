
long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long arr[n];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    for (int i = 3; i < n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    return arr[n-1];
}
