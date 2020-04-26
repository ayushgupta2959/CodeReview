#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int h, c;
	cin>>h>>c;
	vector<string> a(h);
	int top, left;
	vector<vector<int>> dp(h, vector<int>(c, INT_MAX));
	for(int i = 0; i < h; ++i) cin>>a[i];
	dp[0][0] = a[0][0] == '.' ? 0:1;
	for(int i = 1; i < h; ++i) dp[i][0] = dp[i-1][0] + (a[i][0] == '.' ? 0 : a[i-1][0] == '.' ? 1 : 0);
	for(int i = 1; i < c; ++i) dp[0][i] = dp[0][i-1] + (a[0][i] == '.' ? 0: a[0][i-1] == '.' ? 1 : 0);
	
	for(int i = 1; i < h; ++i){
		for(int j = 1; j < c; ++j){
			
			if(a[i][j] == '.') dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
			else if(a[i-1][j-1] == a[i-1][j] && a[i-1][j] == a[i][j-1]){
				if(a[i][j] == a[i-1][j]) dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
				else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
			}
			else{
				top = dp[i-1][j] + (a[i-1][j] == '.' ? 1 : 0);
				left = dp[i][j-1] + (a[i][j-1] == '.' ? 1 : 0);
				dp[i][j] = min(top, left);
			}
		}
	}

	cout<<dp[h-1][c-1];
  return 0;
}