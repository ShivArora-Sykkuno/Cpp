#include<bits/stdc++.h>
using namespace std;
#define ll long long int




ll robber(int *rob, int size){
    int dp[size];
    memset(dp, 0, size);
    dp[0] = rob[0];
    dp[1] = max(rob[1], rob[0]);

    for(int i=2; i<size; i++){
        int with = dp[i-2] + rob[i];
        int without = dp[i-1];
        dp[i] = max(with , without);
    }
    return dp[size-1];
}

int main(){
    int size; cin>>size;
    int rob[size];
    for(int i=0; i<size; i++){
        cin>>rob[i];
    }
    int ans = robber(rob, size);
    cout<<ans<<endl;
    return 0;
}