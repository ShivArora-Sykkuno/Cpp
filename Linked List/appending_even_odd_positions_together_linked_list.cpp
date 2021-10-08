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

int lenght(node *head){
    node *temp=head;
    int count = 0;
    while (temp != NULL){
        count = count+1;
        temp = temp->next;
    }
    return count;

}

void oddeven(node* &head){
    node *odd = head;
    node *even = head-> next;
    node *evenstop = even;
    int l = lenght(head);
    if(l%2 == 0){
        while(even->next != NULL){
            odd-> next = even-> next;
            odd = even-> next;
            even-> next = odd-> next;
            even = odd-> next;
        }
        odd-> next = evenstop;
    }
    else{
        while (odd-> next = NULL)
        {
            odd-> next = even-> next;
            odd = even-> next;
            even-> next = odd-> next;
            even = odd-> next;
        }
        odd-> next = evenstop;
        even-> next = NULL;
        
    }

}