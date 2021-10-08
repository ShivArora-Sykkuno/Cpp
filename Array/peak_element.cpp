#include<bits/stdc++.h>
using namespace std;

int peak_element(vector<int>& nums) {
    int index = 0, maxi = nums[0];
    
    for(int i = 1; i < nums.size(); i++){
        if(maxi < nums[i]){
            index = i;
            maxi = nums[i];
        }
    }
    
    return index;
}


int main(){
    int size,x;
    cout<<"Size of array"<<endl;
    cin>>size;
    vector<int> vec;
    cout<<"Enter array Elements"<<endl;
    for(int i=0; i<size; i++){
        cin>>x;
        vec.push_back(x);
    }


    int peak = peak_element(vec);
    cout<<"The peak Elemtent in the array is"<<peak<<endl;
    
    return 0;
}