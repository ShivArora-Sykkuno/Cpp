#include<bits/stdc++.h>
using namespace std ;

void generateStringsUtil(int K, char str[], int n){
	if (n == K)
	{
		str[n] = '\0' ;
		cout << str << endl;
		return ;
	}
	if (str[n-1] == '1')
	{
		str[n] = '0';
		generateStringsUtil (K , str , n+1);
	}
	if (str[n-1] == '0')
	{
		str[n] = '0';
		generateStringsUtil(K, str, n+1);
		str[n] = '1';
		generateStringsUtil(K, str, n+1) ;
	}
}

void generateStrings(int K )
{
	if (K <= 0)
		return ;

	char str[K];

	str[0] = '0' ;
	generateStringsUtil ( K , str , 1 ) ;
	str[0] = '1' ;
	generateStringsUtil ( K , str , 1 );
}

int main()
{
	int K = 4;
	generateStrings (K) ;
	return 0;
}
