#include<bits/stdc++.h>
using namespace std;


vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(),nums.end());
        vector<int> res;
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> track(n,-1);
        int maxInd=0;
        int maxLen=0;
        for(int end=1;end<n;end++){
            for(int start=0;start<end;start++){
                if(nums[end]%nums[start]==0 && dp[end]<1+dp[start]){
                    dp[end]=1+dp[start];
                    track[end]=start; // mapping end and start for later finding out the series
                    if(dp[end]>=maxLen){
                        maxLen=dp[end];
                        maxInd=end;
                    }
                }
            }
        }
        while(maxInd>=0){
            res.push_back(nums[maxInd]);
            maxInd=track[maxInd];
        }
        return res;
    }