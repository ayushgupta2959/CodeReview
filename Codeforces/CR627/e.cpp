#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

int main() {
	// sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n,h,l,r;
	cin>>n>>h>>l>>r;
	vector<int> a(n);
	for(auto&x: a){
		cin>>x;
	}
	int t1, t2;
	vector<vector<int>> dp(n, vector<int> (h, -1));
	t1 = a[0];
	t2 = a[0]-1;
	dp[0][t1] = (t1>=l && t1<=r);
	dp[0][t2] = (t2>=l && t2<=r);
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < h; ++j){
			if(dp[i-1][j] != -1){
				t1 = (j + a[i])%h;
				t2 = (j + a[i]-1)%h;
				dp[i][t1] = max(dp[i][t1], dp[i-1][j] + (t1>=l && t1<=r));
				dp[i][t2] = max(dp[i][t2], dp[i-1][j] + (t2>=l && t2<=r));
			}
		}
	}
	// for(int i = 0; i < h; ++i) printf("%3d ", i);
	// 	cout<<"\n";
	// for(auto& row: dp){
	// 	for(auto x: row) printf("%3d ", x);
	// 	cout<<"\n";
	// }


	cout<<*max_element(dp[n-1].begin(), dp[n-1].end());

  	return 0;
}