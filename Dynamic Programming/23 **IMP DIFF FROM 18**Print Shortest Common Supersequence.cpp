#include <bits/stdc++.h>
using namespace std;


//THE CODE IS VERY VERY SIMILAR TO PRINT LONGEST COMMON SUBSEQUENCE...TILL LINE 39


string SCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	//I GOT A DOUBT IN INITIALIZATION.....when n==0, then we should return m....ie when i==0, all j's should be m
	//similarly when m==0, then we should return n....ie when j==0, all i's should be n
	//and only when i==0 && j==0, dp[0][0] should be 0
	//The above 3 lines...this is what i thought about initialization....NOTHING WRONG!
	//but we did NOT do it. Why?
	//See while loop on line 35...we are using backtracking to make the string....so initializing with zeroes is a good idea
	//because the the base condition of while loop becomes simple...thats it!
	//otherwise there was no issue with my way of initialization, but then the base condition of while loop becomes ugly.
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string scs = "";
	
	//this is the backtracking loop
	while (i > 0 && j > 0) {  
		if (X[i - 1] == Y[j - 1]) { // when char are eqaul from table obs 
			scs += X[i - 1]; // take only once 
			i--, j--; // and decrement both
		}  //TILL THIS LINE, THE CODE WAS SAME AS PRINT THE LONGEST COMMON SUBSEQUENCE !!!!!!!!!!
		else if (dp[i][j - 1] > dp[i - 1][j]) {   
			scs += Y[j - 1]; // in this we will take the charecter to string 
			j--;
		}
		else {
			scs += X[i - 1]; // taking the charecter to string 
			i--;
		}
	}

	while (i > 0) {
		scs += X[i - 1]; // take left chareter from str1
		i--;
	}

	while (j > 0) {
		scs += Y[j - 1]; // take left chareter from str1
		j--;
	}

	reverse(scs.begin(), scs.end());

	return scs;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << SCS(X, Y, n, m) << endl;
	return 0;
}
