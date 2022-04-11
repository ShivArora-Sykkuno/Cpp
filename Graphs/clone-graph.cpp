#include<bits/stdc++.h>
using namespace std;


Node *cloneGraph(Node *node)
{
    unordered_map<Node *, Node *> mp;
    if (node)
    {
        mp[node] = new Node(node->val);
        stack<Node *> stk;
        stk.push(node);
        unordered_set<Node *> seen = {node};
        while (stk.size())
        {
            Node *n = stk.top();
            stk.pop();
            for (auto &nn : n->neighbors)
            {
                if (!mp[nn])
                    mp[nn] = new Node(nn->val);
                mp[n]->neighbors.push_back(mp[nn]);
                if (!seen.count(nn))
                {
                    stk.push(nn);
                    seen.insert(nn);
                }
            }
        }
    }
    return mp[node];
}