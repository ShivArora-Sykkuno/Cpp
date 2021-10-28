#include<bits/stdc++.h>
using namespace std;

class node{
    int data;
    node * left;
    node * right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};


void PreOrder(node * root){
    if (root == NULL) return;

    cout<<root<<" ";
    PreOrder(root->left);
    PreOrder(root-> right);
}