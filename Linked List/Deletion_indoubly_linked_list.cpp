#include<bits/stdc++.h>
using namespace std;


class node {
    public:
    int data;
    node *next;
    node *prev;

    node(int val){
        data = val;
        next = NULL;
        prev= NULL;
    }
};

void Insertathead(node* &head, int val){
    node *n = new node(val);
    n-> next = head;
    if (head!= NULL){
        head-> prev = n;
    }
    head = n;

}

void Insertattail(node* &head, int val){
    node *n = new node(val);
    if (head == NULL){
        Insertathead(head, val); 
    }
    else{
        node *temp = head;
        while(temp-> next != NULL){
            temp = temp->next ; 
        }
        temp-> next = n;
        n-> prev = temp;
        
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


int deletion(node* &head, int pos){
    if (head == NULL)
    {
        return 0;
    }
    else if (head-> next == NULL){
        delete head;
    }
    else{
    node* temp = head;
    for(int i=1; i<pos; i++){
        temp = temp-> next;
    }
    temp->prev-> next = temp-> next;
    temp-> next-> prev = temp-> prev;
    delete temp;
    }
    return 0;

}