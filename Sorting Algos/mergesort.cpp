#include<bits/stdc++.h>
using namespace std;


void merge(int *arr, int start, int end, int mid){
    int result[end-start+1];
    int i = start, j = mid+1, k = 0;

    while(i<=mid && j<=end){
        if(arr[i] < arr[j])result[k++] = arr[i++]; 
        else result[k++] = arr[j++];
    }
    // Odd partition on the left hand side
    while(i<=mid) result[k++] = arr[i++];
    
    // Odd partition on the right hand side
    while(j<=end) result[k++] = arr[j++];
    
    k = 0;
    for(int x =start; x<=end; x++){
        arr[x]= result[k];
        k++;

    }
}

void MergeSort(int *arr, int start, int end){
    if (start>= end) return;
    int mid = (start + end) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    merge(arr, start, end, mid);

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
    MergeSort(arr, 0, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
