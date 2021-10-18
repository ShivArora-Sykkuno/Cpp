#include<bits/stdc++.h>
using namespace std;


 bool SameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        } else if(!p || !q) {
            return false;
        }
        
        bool ans = (p->val == q->val);
        
        ans = ans && (SameTree(p->left, q->left));
        ans = ans && (SameTree(p->right, q->right));
        return ans;
    }