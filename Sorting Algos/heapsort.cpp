#include<bits/stdc++.h>
using namespace std;

void HeapSort(int *arr, int size){
    
	
}


int main(){
    int n;
    cout<<"Enter the Number of Elements"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter the Elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Before Sorting the array"<<endl;

     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    cout<<"After Sorting the array"<<endl;
    HeapSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}