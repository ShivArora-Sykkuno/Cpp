#include<bits/stdc++.h>
using namespace std;

int single_number(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i+=3){
        if ( i + 1 >= nums.size()){
            return nums[i];
        }
        if(nums[i+1]!=nums[i]) return nums[i];
        }
    return -1;
}

int main(){
    int size, x;
    vector<int> vec;
    cout<<"Enter Sorted array 1"<<endl;
    for(int i=0; i<size; i++){
        cin>>x;
        vec.push_back(x);
    }

    int solution = single_number(vec);
    cout<<"The element which only comes one time is  "<<solution<<endl;

    return 0;
}