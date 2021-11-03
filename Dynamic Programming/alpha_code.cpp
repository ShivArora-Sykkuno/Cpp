#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

vector<ll> dp(10005, -1);
ll alphacode(string &str, int n){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    ll ans = 0;
    if(str[n-1]- '0' > 0){
        ans += alphacode(str, n-1);
    }
    if(str[n-2]-'0' > 0 && n-2 >= 0 && (str[n-2]-'0')*10 + (str[n-1]- '0') <= 26){
        ans += alphacode(str, n-2);
    }
    return dp[n] = ans;
}


int main(){
    string s;
    cout<<"Enter a number for the code"<<endl;
    cin>>s;
    int x =alphacode(s, s.size());
    cout<<x<<endl;



    return 0;
}