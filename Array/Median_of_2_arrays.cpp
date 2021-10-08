#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n1 = nums1.size(), n2 = nums2.size();
    int mIdx = (n1+n2) / 2 - 1;
    int i = -1, j = -1, last = 0, current = 0;
    while(i+j<mIdx)
    {
        last = current;
        if(i>=n1-1)
        {
            current = nums2[++j];
        }
        else if(j>=n2-1)
        {
            current = nums1[++i];
        }
        else if(nums1[i+1]>nums2[j+1])
        {
            current = nums2[++j];
        }
        else
        {
            current = nums1[++i];
        }
    }
    if((n1+n2) % 2)
        return current;
    else
        return (current + last) / 2.0;
}


int main(){
    int n1,n2,x;
    cout<<"Enter size of arr 1"<<endl;
    cin>>n1;
    vector<int> vec1;
    cout<<"Enter Sorted array 1"<<endl;
    for(int i=0; i<n1; i++){
        cin>>x;
        vec1.push_back(x);
    }

    cout<<"Enter size of arr 2"<<endl;
    cin>>n2;
    cout<<"Enter Sorted array 2"<<endl;
    vector<int> vec2;
    for(int i=0; i<n2; i++){
        cin>>x;
        vec2.push_back(x);
    }

    double median = findMedianSortedArrays(vec1, vec2);
    cout<<"Meadian is "<<endl;
    cout<<median<<endl;
    return 0;

    
}