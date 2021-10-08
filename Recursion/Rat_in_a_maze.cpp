#include<bits/stdc++.h>
using namespace std;

bool isfree(int** arr, int x, int y, int n){                    // To check that if the rat is going in the right direction 
    if(x<n && y<n && arr[x][y]== 1)
    return true;
    else return false;
}
bool ratmaze(int** arr, int x, int y, int n, int** solArr){
    if(x == n & y == n){                                       // When it reaches its destination
        solArr[x][y] = 1;
        return true;
    }
    if(isfree(arr,x,y,n) == true){
        solArr[x][y] = 1;                                    // To make the path
        if(ratmaze(arr, x+1, y, n, solArr)) return true;    // To move Right
        if((ratmaze(arr, x, y+1, n, solArr))) return true;  // To move Down
        solArr[x][y] = 0;       //BackTrack Line where to check if the rat can't go anywhere else it should come back to the previous point
        return false;
    }
}


int main(){

    int n;
    cout<<"Enter the size of the square array"<<endl;
    cin>>n;
    int ** arr = new int*[n];
    for(int i =0; i< n; i++){
        int* arr = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"Enter the ["<<i<<"]["<<j<<"] number"<<endl;
            cin>>arr[i][j];
        }
    }

    int ** solArr = new int*[n];
    for(int i =0; i< n; i++){
        int* solArr = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            solArr[i][j] = 0;
        }
    }
    return 0;
}