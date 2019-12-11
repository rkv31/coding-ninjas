#include <iostream>
#include<algorithm>
using namespace std;

class edge{
    public:
    int s;
    int d;
    int w;
};

bool comp(edge e1, edge e2)
{
    return e1.w < e2.w;
}

int findParent(int v, int* parent)
{
    if (parent[v] == v)
        return v;
    else
        return findParent(parent[v], parent);
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    edge* input = new edge[E];
    for (int i=0; i<E; i++)
    {
        int s, d, w;
        cin>>s>>d>>w;
        input[i].s = s;
        input[i].d = d;
        input[i].w = w;
    }
    
    sort(input, input + E, comp);
    
    edge* output = new edge[V-1];
    
    int* parent = new int[V];
    for (int i=0; i< V; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i=0;
    while ( count != V-1 )
    {
        int sourceParent = findParent(input[i].s, parent);
        int destParent = findParent(input[i].d, parent);
        
        if (sourceParent == destParent)
        {
            i++;
            continue;
        }
        output[count] = input[i];
        count++;
        parent[sourceParent] = destParent;
        i++;
    }
    
    for (int k=0; k< V-1; k++)
    {
        if (output[k].s < output[k].d)
            cout<<output[k].s<<" "<<output[k].d<<" "<<output[k].w<<endl;
        else
            cout<<output[k].d<<" "<<output[k].s<<" "<<output[k].w<<endl;
    }
    delete[] parent;
    delete[] input;
    delete[] output;

    return 0;
}
