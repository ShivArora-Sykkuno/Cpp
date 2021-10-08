#include<bits/stdc++.h>
using namespace std;


void display(vector<vector<bool>> visited, int n){
     for(int i =0; i<n; i++){
           for(int j =0; j<n; j++){
               if(visited[i][j]== true) cout<<"Q ";
               else cout<<". ";
           }
           cout<<endl;
       }
}
bool Isitfree(vector<vector<bool>> &visited, int row, int column, int n){
    // Column Check
    for(int i = row-1; i>= 0; i--){
        if(visited[i][column]) return false;
    }
    // Left upeer Diagonal Check
    for(int i = row-1,j = column-1; i>=0 and j >= 0; i--, j--){
        if(visited[i][j]) return false;
    }
    // Right upeer Diagonal Check
    for(int i = row-1, j = column+1; i>=0 and j < n; i--, j++){
        if(visited[i][j]) return false;
    }
    return true;
}

int Queencount = 0;
void Queen(vector<vector<bool>> &visited, int row, int n){
    if(row == n){
        Queencount++;
        display(visited, n);
        cout<<("\n\n");
        return;
    }
    for(int i =0; i< n; i++){
        if(Isitfree(visited, row, i, n)){
            visited[row][i] = true;
            Queen(visited, row+1, n);
            visited[row][i] = false;
        }
    }

}
int main(){
    int n;
    cout<<"Enter"<<endl;
    cin>>n;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    Queen(vis, 0, n);
    cout<<Queencount<<endl;

    return 0;
}