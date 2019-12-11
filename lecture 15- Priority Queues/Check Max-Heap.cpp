bool checkMaxHeap(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
    for(int i=0; i<n; i++)
    {
        if ( (2*i)+1 <= n && arr[i] < arr[(2*i)+1])
            return false;
        if ( (2*i)+2 <= n && arr[i] < arr[(2*i)+2])
            return false;
    }
    return true;
}
