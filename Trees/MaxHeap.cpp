#include<bits/stdc++.h>
using namespace std;

void Insert(int *arr, int n){
    int i = n; 
    int temp = arr[i];
    while (temp> arr[i/2] && i>1){
        arr[i] = arr[i/2];
        i = i/2; 
    }
    arr[i]= temp;
}




void MaxHeap(int *arr, int size){
    for(int i=2; i<=size; i++){
        Insert(arr, i);
    }
}


int main(){
    int arr[] ={0, 10, 20, 30, 25, 5, 40, 35};

    MaxHeap(arr, 7);
    for(int i=1; i<=7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;


}