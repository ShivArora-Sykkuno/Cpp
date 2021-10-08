#include<bits/stdc++.h>
using namespace std;


class node {
    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};


void Insertattail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
        head = n;
    else{
        node *temp = head;
        while (temp-> next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
}


void display(node *head){
    node *temp=head;
    while (temp != NULL){
        cout<< temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;

}

node* reversingk(node* &head,int k){
    node *pre = NULL;
    node *crr = head;
    node *nxt;
    int count = 0;
    while(crr != NULL && count != k){
        nxt = crr->next;
        crr-> next = pre;
        pre =crr;
        crr = nxt;
        count++;

    }
    if (crr != NULL){
    head->next= reversingk(crr, k);
    }
    return pre;
}
