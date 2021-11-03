#include<bits/stdc++.h>
using namespace std;

# define ll long long int 

// Creating a Node Templete
template<typename T>
class Node{

    public:
    string key;
    T value;
    Node<T>* next;

    Node(string key, T value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

// Creating a HashMap
template<typename T>
class HashTable{
    public:

    int ts; // Total Size
    int cs; // Current Size
    Node<T>**arr;

    HashTable(int ts = 2){
        this->ts = ts;
        this->cs = 0;
        arr = new Node<T>*[this->ts];
        for(int i=0; i<this->ts; i++){
            this->arr[i] = NULL;
        }
    }


    int BuicketIndex(string key){
        ll sum = 0;
        ll factor = 1;
        for(int i=0; i<key.size(); i++){
            // This if to calculate the bucket Index (a+b)%c == (a%c + b%c) %c
            sum = (sum%this->ts) + ((int)key[i]*factor)%this->ts;
            // This is (all)%c
            sum =  sum % this->ts;

            // This is for 37^i where i = 0, 1, 2......
            factor =  ((factor%this->ts) * (37%this->ts)) % this->ts; 
        }
        return (int)sum;

    }

    void ReHash(){
        
        int old_size = this->ts;
        this->ts = 2*old_size;
        Node<T> **old_table = this->arr;
        this->arr = new Node<T>*[this->ts];

        for(int i=0; i<this->ts; i++){
            this->arr[i] = NULL;
        }
        for(int i=0; i<old_size; i++){
            Node<T> *temp = old_table[i];
            while(temp != NULL){
                Insert(temp->key, temp->value);
                temp = temp->next;
            }
        }
    }


    T Search(string key){
        int bi = BuicketIndex(key);
        Node<T> *temp = this->arr[bi];

        while (temp->next != NULL){

            if(temp->key == key){
                return temp->value;
            }else{
                temp = temp->next;
            }
            return NULL;
        }
    }

    void Insert(string key, T value){
        int bi = BuicketIndex(key);
        T result = Search(key);
        if(result!= NULL){
             Node<T> *temp = this->arr[bi];
            while (temp->key != NULL){
                if(temp->key == key){
                    temp->value = value;
                }else{
                    temp = temp->next;
                }
            }
            return;
        }
        
        Node<T> *new_node = new Node<T>(key, value);
        if(this->arr[bi] == NULL){
            this->arr[bi] = new_node;
        }else{
            new_node->next = this->arr[bi];
            this->arr[bi] = new_node;
        }
        this->cs++;
        double load_factor = (double)(this->cs) / (this->ts);
        if(load_factor > 0.5){
            ReHash();
        }
    }

    void Display(){
        for(int i=0; i<this->ts; i++){
            Node<T> *temp = this->arr[i];
            if(temp == NULL){
                cout<<i<<"->NULL";
            }
            while(temp != NULL){
                cout<<i<<"-> ";
                cout<<"("<<temp->key<<", "<<temp->value<<")->   ";
                temp = temp->next;
            }
            cout<<endl<<endl;
        }
    }
};

int main(){
    int n; cin>>n;
    HashTable<int> *hash = new HashTable<int>();
    while(n--){
        string key; cin>>key;
        int value; cin>>value;
        hash->Insert(key, value);
    }   
    hash->Display();

    return 0;


}