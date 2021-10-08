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


node* reversing(node* &head){
    node *pre = NULL;
    node *crr = head;
    node *nxt;
    while(crr != NULL){
        nxt = crr->next;
        crr-> next = pre;
        pre =crr;
        crr = nxt;

    }
    return pre;
}
