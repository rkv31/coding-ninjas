#include<algorithm>
using namespace std;

 int lis(int arr[], int n) {
		
				
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/
     int *output = new int[n];
     output[0] = 1;
     for (int i=1; i<n; i++)
     {
         output[i] = 1;
         for(int j= i-1; j >= 0; j--)
         {
             if (arr[j] >= arr[i])
                 continue;
             int possibleAns = output[j] + 1;
             if (possibleAns > output[i])
                 output[i] = possibleAns;
         }
     }
     int best = *max_element(output, output+n);
     delete [] output;
     return best;
}