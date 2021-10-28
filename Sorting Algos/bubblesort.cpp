#include<bits/stdc++.h>
using namespace std;


void BubbleSort(int *arr, int size){
    int count_swaps;
    for(int i=0; i<size-1; i++){
        count_swaps = 0; 
        for(int j=0; j< size-1-i; j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                count_swaps++;
            }
        }
        if(count_swaps == 0) break;
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
    BubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}