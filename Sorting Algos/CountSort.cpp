#include<bits/stdc++.h>
using namespace std;


int FindMax(int *arr, int size){
    int max = INT32_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
void CountSort(int *arr, int size){ 
    
    int max = FindMax(arr, size) + 1;

    int countarr[max];
    for(int i=0; i<max; i++){
        countarr[i] = 0;
    }
    
    for(int i=0; i<size; i++){
        int  m = arr[i]; 
        countarr[m]++;
    }

    int i=0;
    for(int j=0; j<max; j++){
        if(countarr[j]>0){

            if(countarr[j]>1){
                int count = countarr[j];
                for(int x=0; x<count;x++){
                    arr[i++]= j;
                }
            }else{ 
                arr[i++] = j;
            }

        }     
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
    CountSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}