
void inplaceHeapSort(int input[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
    int heapIndex = 1;
    while ( heapIndex < n )                //Creating max-heap
    {
        int childIndex = heapIndex - 1;
        while ( childIndex > 0 )
        {
            int parentIndex = (childIndex - 1) / 2;
            
            if ( input[childIndex] < input[parentIndex] )
            {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
        heapIndex++;
    }
    
    while( heapIndex > 0 )
    {
        int temp = input[0];
        input[0] = input[heapIndex-1];
        input[heapIndex-1] = temp;
        heapIndex--;
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        while ( leftChildIndex < heapIndex )
        {
            int minIndex = parentIndex;
            
            if ( input[minIndex] > input[leftChildIndex] )
                minIndex = leftChildIndex;
            
            if ( rightChildIndex < heapIndex && input[minIndex] > input[rightChildIndex] )
                minIndex = rightChildIndex;
            
            if ( minIndex != parentIndex )
            {
                int temp1 = input[minIndex];
                input[minIndex] = input[parentIndex];
                input[parentIndex] = temp1;
            }
            else
                break;
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
    
}
