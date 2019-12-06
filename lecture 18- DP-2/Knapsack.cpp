#include <iostream>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight){

	/* Don't write main().
	*  Don't read input, it is passed as function argument.
	*  Return output and don't print it.
	*  Taking input and printing output is handled automatically.
	*/

	//write your code here
    if (n == 0 || maxWeight == 0)
        return 0;
    if (weights[0] > maxWeight)
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    else
    {
        int inc = values[0] + knapsack(weights + 1, values + 1, n-1, maxWeight-weights[0]);
        int not_inc = knapsack(weights + 1, values + 1, n-1, maxWeight);
        return max(inc, not_inc);
    }
}

