Check Max-Heap
Given an array of integers, check whether it represents max-heap or not.
Return true or false.
Input Format :
Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
true if it represents max-heap and false if it is not a max-heap
Constraints :
1 <= N <= 10^5
1 <= Ai <= 10^5


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
