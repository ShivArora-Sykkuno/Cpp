#include<bits/stdc++.h>
using namespace std;


class queue_using_stack{
    stack<int> s1;
    stack<int> s2;
    
    public:
        void push(int x){
            s1.push(x);
            return;
        }
        int pop(){
            if(s1.empty() && s2.empty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        int intvalue = s2.top();
        s2.pop();
        return intvalue;
        }
        bool empty(){
            if(s1.empty() && s2.empty()){
                return -1;
                
                }
        }
};
