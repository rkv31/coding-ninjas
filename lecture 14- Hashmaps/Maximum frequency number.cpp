#include<unordered_map>
#include<climits>
	int highestFrequency(int *input, int n){	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
         unordered_map<int, int> max;
        for(int i=0; i< n; i++)
        {
            max[input[i]]++;
        }
        int max_count = 0;
        int max_ele = INT_MIN;
        
        for (int i=0; i<n; i++)
        {
            if (max_count == max[input[i]])
            {
                continue;
            }
            else if ( max_count < max[input[i]])
            {
                max_count = max[input[i]];
                max_ele = input[i];
            }
        }
        return max_ele;
 	}

