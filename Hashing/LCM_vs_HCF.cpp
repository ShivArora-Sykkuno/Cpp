#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    unordered_map<int, int> fm;
    while(t--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            fm[x]++;
        }
        int ans = 0;
        for(auto x: fm){
            if(fm.count(2*x.first) != 0){
                ans += fm[x.first] * fm[2*x.first];
            }
        }
        cout<<ans<<endl;
        fm.clear();
    }



    return 0;
}