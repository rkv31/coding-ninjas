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
