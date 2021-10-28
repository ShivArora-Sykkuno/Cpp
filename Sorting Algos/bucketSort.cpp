#include<bits/stdc++.h>
using namespace std;

void BucketSort(int *arr, int size){
	vector<int> countarr[size];

	for (int i=0; i<size; i++) {
		int m = arr[i];
		countarr[m].push_back(arr[i]);
	}

	for (int i=0; i<size; i++)
		sort(countarr[i].begin(), countarr[i].end());

	int index = 0;
	for (int i=0; i<size; i++)
		for (int j = 0; j < countarr[i].size(); j++)
			arr[index++] = countarr[i][j];
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
    BucketSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}