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

int Delete(int *arr, int n){

    int val = arr[1];
    int x = arr[n];

    arr[1]= x;
    arr[n] = val;

    int i=1;
    int j=i*2;
    while(j<n-1){
        if(arr[j+1]>arr[j]){
            j = j + 1;
        }

        if(arr[j]>arr[i]){
            swap(arr[i], arr[j]);
           
            
            i = j;
            j = j * 2;
        }else{
            break;
        }
    }
    return val;
}
   
void MaxHeap(int *arr, int size){
    for(int i=2; i<=size; i++){
        Insert(arr, i);
    }
}



int main(){
    int n; cin>>n;
    int arr[n];
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    MaxHeap(arr, n);
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


     cout<<"Heap Sort"<<endl;
    for(int i=n; i>1; i--){
        cout<<Delete(arr, i)<<" ";
    }
    cout<<endl;
    return 0;

}