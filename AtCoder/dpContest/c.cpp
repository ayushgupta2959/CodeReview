#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;

	vector<int> dp_prev(3), dp(3);
	cin>>dp_prev[0]>>dp_prev[1]>>dp_prev[2];
	
	for(int i = 1; i < n; ++i){
		cin>>dp[0]>>dp[1]>>dp[2];
		dp[0] += max(dp_prev[1], dp_prev[2]);
		dp[1] += max(dp_prev[0], dp_prev[2]);
		dp[2] += max(dp_prev[0], dp_prev[1]);
		dp_prev = dp;
	}

	cout<<max(dp_prev[0], max(dp_prev[1], dp_prev[2]));

  return 0;
}