#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node (int val){
        data = val;
        next = NULL;
    }
};

void Insertathead(node* &head, int val){
    node *n = new node(val);
    if (head== NULL){
        n->next = n;
        head =n;
    }
    else{
    node *temp = head;
    while(temp-> next != head){
        temp = temp-> next;
    }
    temp->next = n;
    n-> next = head;
    head = n;
    } 
}

void  Insertattail(node* &head, int val){
     node* n = new node(val);
    if (head == NULL){
        Insertathead(head, val);
    }
    else{
       
        node *temp = head;
        while(temp-> next != head){
            temp = temp-> next;
        }
        temp-> next = n;
        n -> next = head;
    }
}

void deletion(node* &head , int pos){
    node *temp = head; 
    if (pos = 1){
        node *todelete= head;
        while(temp->next!= head){
            temp= temp->next;
        }
        temp-> next = head-> next;
        head = head-> next;
        delete todelete;
    } 

    else{
        for(int i = 1; i < pos-1; i++){
            temp = temp-> next;
        }
        node *todelete= temp->next;
        temp-> next = temp-> next->next;
        delete todelete;
    }    
}

void display(node * head){
    node *temp = head;
    do {
        cout<<temp->data<<" -> "; 
        temp = temp->next;
    }while(temp!= NULL);
}