#include<bits/stdc++.h>
using namespace std;

int TotalWays = 0;
void display(vector<vector<int>> &grid, int n){
     for(int i =0; i<n; i++){
           for(int j =0; j<n; j++){
               cout<<grid[i][j]<<" ";
           }
           cout<<endl;
       }
}
bool IsitSafe(vector<vector<bool>> &visited, int row, int column, int n){
    if(row >= 0 and column >= 0 and row < n and column< n and visited[row][column] == false) return true;
    return false;


}

void KnightTour(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int column, int KnightCount, int n){
    if(KnightCount == n*n){
        TotalWays++;
        grid[row][column] = KnightCount;
        display(grid, n);
        cout<<"\n\n";
        return;
    }
    if(KnightCount > n*n){
        return;
    }
    int xdir[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
    int ydir[8] = {1, -1, 2, -2, 1, -1, 2, -2};

    visited[row][column] = true;
    grid[row][column] = KnightCount;
    for (int i =0; i <8;i++){
        if(IsitSafe(visited, row+xdir[i], column+ydir[i], n)){

            KnightTour(grid, visited, row+xdir[i], column+ydir[i], KnightCount+1, n);
        }
    }
    grid[row][column] = 0;
    visited[row][column] = false;
}
int main(){
    int n;
    cout<<"Enter the Number of NxN You Want"<<endl;
    cin>> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    KnightTour(grid, visited, 0, 0, 1, n);
    cout<<TotalWays<<endl;
    return 0;
}
