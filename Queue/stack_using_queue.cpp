#include<bits/stdc++.h>
using namespace std;


class stack_using_queue{
    int N;
    queue<int> q1;
    queue<int> q2;
    
    public:
        void Stack(){
        }

        int pop(){
            if(q1.empty()){
                cout<<"Queue is empty"<<endl;
            }
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            int result = q1.front();
            q1.pop();


            queue<int> temp = q2;
            q2 = q1;
            q1 = temp;
            return result;
        }

        void push(int x){
            q1.push(x);
        }

        int top(){
            if(q1.empty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                while(q1.size() != 1){
                    q2.push(q1.front());
                    q1.pop();
                }
                int ans = q1.front();
                queue<int> temp = q2;
                q2 = q1;
                q1 = temp;
                return ans;
            }
        }


};