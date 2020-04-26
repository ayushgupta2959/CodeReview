#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define vv(t) vector<vector<t>>
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))

int p = 998244353;
long long result = 0;

void solve(vector<int> &a, int sum, int i, int r){
	cout<<sum<<" "<<i<<" "<<r<<"\n";
	if(sum == 0){
		result += (i+2)*(a.size() - r);
		result %= p;
		return;
	}

	if(i < 0) return;

	if(a[i] <= sum){
		solve(a, sum - a[i], i-1, (r==-1)?i:r);
	}
	solve(a, sum, i-1, r);
}

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int n, s;
	cin>>n>>s;
	vector<int> a(n);
	for(int i = 0; i<n;++i) cin>>a[i];

	solve(a, s, n-1, -1);

	// vv(long long) dp = vvn(long long, n+1, w+1, 0);

	// for(int i = 1; i <= n; ++i){
	// 	for(int j = 0; j <= s; ++j){
	// 		dp[i][j] = dp[i-1][j];
	// 		if(a[i] <= j) dp[i][j] += dp[i-1][j-a[i]];
	// 	}
	// 	if(a[i] <= s) dp[]
	// }
	cout<<result;
  	return 0;
}
//https://www.youtube.com/watch?v=WPPPFqsECz0