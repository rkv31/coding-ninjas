Merge K sorted arrays
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234

#include<queue>
using namespace std;
class triplet{
    public:
    int element;
    int arrayIndex;
    int elementIndex;
};
class Comp{
    public:
    bool operator()(const triplet& a, const triplet& b)	{
        return a.element > b.element;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> arr){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
    vector<int> output; 
    priority_queue<triplet, vector<triplet>, Comp > pq; 
    
    for (int i = 0; i < arr.size(); i++)
    {
        triplet d;
        vector<int> k = *arr[i];
        d.element = k[0];
        d.arrayIndex = i;
        d.elementIndex = 0;
        pq.push(d);
    }
    while ( !pq.empty() ) 
    { 
        triplet curr = pq.top(); 
        pq.pop(); 
  
        int i = curr.arrayIndex;   
        int j = curr.elementIndex;  
  
        output.push_back(curr.element); 
  
        if (j + 1 < arr[i]->size())
        {
            triplet d;
            vector<int> k = *arr[i];
            d.element = k[j + 1];
            d.arrayIndex = i;
            d.elementIndex = j + 1;
            pq.push(d);
        }
            
    } 
  
    return output;
}
