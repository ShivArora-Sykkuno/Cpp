/*
    W9L1
    9.2.2
    Find Longest Common Subsequence


    Given two strings S1 & S2, find the Longest Common Subsequence present in both of them. 

    e.g. 
    LCS for input Sequences “Tuesday” and “Thursday” is “Tusday”. 
    LCS for input Sequences “requirement” and “recruitment” is “reuiment”. 

    Write a function: 
            int solution(String S1, String S2) 
    that accepts two strings S1 and S2. The function should return the length longest common subsequence in both the strings. If strings do not contain longest common subsequence then return 0.

*/

#include <bits/stdc++.h>
using namespace std;

int Subsequence(string str1, string str2){
    
  int l1 = str1.size();
  int l2 = str2.size();
    
  int dp[l1 + 1][l2 + 1];
  for (int i = 0; i <= l1; i++){
    for (int j = 0; j <= l2; j++){
	    if (i == 0 || j == 0){
	        dp[i][j] = 0;
		 }else if (str1[l1 - i] == str2[l2 - j]){
	        dp[i][j] = 1 + dp[i - 1][j - 1];
	     }else{
	          int n1 = dp[i - 1][j];	
              int n2 = dp[i][j - 1];	
              int n3 = dp[i - 1][j - 1];	
              dp[i][j] = max(n1, max(n2, n3));
		    }
	    }
    }
   return dp[l1][l2];
}

int main()    
{
	string str1, str2;
	cin>>str1>>str2;
	cout<<Subsequence(str1, str2) << endl;
	return 0;
}
