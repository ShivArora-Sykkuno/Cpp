#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    priority_queue<long> minHeap;
    minHeap.push(-1 * 1);
    int nth = 0;
    long val = 1;
    while (!minHeap.empty() && nth < n)
    {
        val = -1 * minHeap.top();
        minHeap.pop();
        while (!minHeap.empty() && val == (-1 * minHeap.top()))
        {
            minHeap.pop();
        }
        nth++;
        minHeap.push(-1 * val * 2);
        minHeap.push(-1 * val * 3);
        minHeap.push(-1 * val * 5);
    }

    return val;
}