#include<bits/stdc++.h>
using namespace std;

int partion(int *arr, int low, int high){
    int m = low;
    int pivot =  high;
    for(int i=low; i<high; i++){
        if(arr[i]< arr[pivot]) {
            swap(arr[i], arr[m]);
            m++;
        }
    }
    swap(arr[m], arr[pivot]);
    return m;
}


int PivotGenerator(int *arr, int low, int high){
    int n = rand();
    int pivot = low + (n% (high - low + 1));
    swap(arr[pivot], arr[high]);
    return partion(arr, low, high);

}


void QuickSort(int *arr, int low, int high){
    if (low < high){
        int pivot = PivotGenerator(arr, low, high);
        QuickSort(arr, low, pivot-1);
        QuickSort(arr, pivot+1, high);
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
    QuickSort(arr, 0, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}