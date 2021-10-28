#include<bits/stdc++.h>
using namespace std;


void SelectionSort(int *arr, int size){ 
    for(int i=0; i<size-1; i++){
        int k=i;
        for(int j=i; j<size; j++){
            if(arr[j]<arr[k]) k=j;
        }
        swap(arr[i], arr[k]);
    }      
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
    SelectionSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}