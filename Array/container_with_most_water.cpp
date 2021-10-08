#include<bits/stdc++.h>
using namespace std;

int container_with_most_water(vector<int>& height) {
    int n = height.size(), ans, area, maxim = 0, i = 0, j = n-1;
    while(i < j){
        ans = min(height[i],height[j]);
            
        area = ans * (j-i);
           
        maxim = max(area,maxim);
           
        if(height[i]>height[j])
            j--;
        else
            i++;
    }
    return maxim;
        
}

int main(){
    int size,x;
    cout<<"Size of array"<<endl;
    cin>>size;
    vector<int> height;
    cout<<"Enter array Elements"<<endl;
    for(int i=0; i<size; i++){
        cin>>x;
        height.push_back(x);
    }

    int maximum = container_with_most_water(height);
    cout<<"Container with the maximum amount of water is  "<<maximum;
    return 0;
}