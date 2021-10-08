#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int>& nums) {        
	int numOfDuplicates = 0;

	for(int i = 1; i < nums.size(); ++i)
	{
		if(nums[i] == nums[i - 1])
			++numOfDuplicates;
		else
			nums[i - numOfDuplicates] = nums[i];
	}
	return nums.size() - numOfDuplicates;
}


int main(){
    int size, x;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    cout<<"Enter the Elements in the array in sorted order"<<endl;
    vector<int> vec;
    for (int i = 0; i < size; i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    
    int new_array_size = remove_duplicates(vec);
    cout<<"The array after removing the duplicates is "<<endl;
    for (int i = 0; i < new_array_size; i++)
    {
        cout<<vec[i]<<" ";
    }
     
}
