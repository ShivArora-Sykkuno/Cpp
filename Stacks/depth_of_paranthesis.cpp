#include<bits/stdc++.h>
using namespace std;



int maxDepth(string s) {
    int nest = 0;
    int answer = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='('){
            nest++;
            answer = max(answer,nest);
        } else if(s[i]==')'){
            nest--;
        }
    }
    return answer;
}