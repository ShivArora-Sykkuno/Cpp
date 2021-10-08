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

node* merging(node* &head1, node* &head2){
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* Dummynode = new node(-1);
    node* ptr3 = Dummynode;

  
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1-> data < ptr2-> data)
        {
            ptr3-> next = ptr1;
            ptr1 = ptr1-> next;  
        }
      
        else
        {
            ptr3-> next = ptr2;
             ptr2 = ptr2-> next;
        }
        ptr3 = ptr3-> next;

    }
    while (ptr1 != NULL){
        ptr3-> next = ptr1;
        ptr1 = ptr1-> next;
        ptr3 = ptr3-> next;

    }

    while (ptr2 != NULL){
        ptr3-> next = ptr2;
        ptr2 = ptr2-> next;
        ptr3 = ptr3-> next;

    }

 return Dummynode->next;
}