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

int find_intersection(node* &head1, node* &head2){
    node *ptr1;
    node *ptr2;
    int dl = 0;
    int l1 = lenght(head1);
    int l2 = lenght(head2);
    if(l1 > l2){
        dl = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        dl = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(dl){
        ptr1 = ptr1-> next;
        if (ptr1 == NULL)
        return -1;
        dl--;
    }
    while (ptr1!= NULL || ptr2!= NULL)
    {
        if (ptr1 == ptr2){
        cout<< "The Interection is at the number"<<ptr1->data<< endl;
        return 0;
        }
        ptr1 = ptr1-> next;
        ptr2 = ptr2-> next;
    }

    return -1;  
}
