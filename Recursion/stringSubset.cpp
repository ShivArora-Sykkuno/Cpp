#include<bits/stdc++.h>
using namespace std;



void StirngSubet(int *arr, vector<int> &temp, int i, int n){
    if(i == n){
        if(temp.size() <= 0) cout<<"The Input was empty"<<endl;

        else{
            vector<int>::iterator it;
            for(it == temp.begin(); it != temp.end(); it++){
                cout<<temp[*it]<<" ";
            }
        }

        
        /* Print the vector*/
        return;
    }
    else{
        temp.push_back(i);
        StirngSubet(arr, temp, i+1, n);
        temp.pop_back();
        StirngSubet(arr, temp, i+1, n);
        return;
    }
}


int main()
{
    int arr[] = { 10, 20, 30, 40 };
    vector<int> temp;
    StirngSubet(arr, temp, 0, 4);
    return 0;
}