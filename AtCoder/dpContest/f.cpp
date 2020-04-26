#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pair<int,int>>
#define vv(t,A,r,c,val) vector<vector<t>> A(r,vector<t>(c, val))
#define vvn(t,A) vector<vector<t>> A
#define vvv(t,A,l,b,h) vector<vector<vector<t>>> A(l,vector<vector<t>>(b,vector<t>(h)))
#define vvvn(t,A) vector<vector<vector<t>>> A

int main() {
	sp;
	////////////////To Remove//////////////
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	string s, t;
	cin>>s>>t;
	int sl = s.size(), tl = t.size();

	vv(int, dp, sl+1, tl+1, 0);

	for(int i = 1; i <= sl; ++i){
		for(int j = 1; j <= tl; ++j){
			if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	string result = "";
	int it = tl, is = sl;
	while(it > 0 && is > 0){
		if(t[it-1] == s[is-1]){
			result += t[it-1];
			it--;
			is--;
		}
		else if(dp[is-1][it] >= dp[is][it-1]){
			is--;
		}
		else it--;
	}


	reverse(result.begin(), result.end());

	cout<<result;

  	return 0;
}