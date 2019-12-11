#include<queue>
int buyTicket (int *arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int my_priority = arr[k];
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++)
    {
        pq.push(arr[i]);
        pair<int,int> p(arr[i], i);
        q.push(p);
    }
    int time = 0;
    while( !q.empty() )
    {
        pair<int,int> p = q.front();
        q.pop();
        if (p.first >= pq.top())
        {
            time++;
            pq.pop();
            if (p.second == k)
                break;
        }
        else
        {
            q.push(p);
        }
    }
    return time;
}
