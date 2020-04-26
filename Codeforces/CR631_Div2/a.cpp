#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(auto& x: a) cin>>x;
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	int max_rank = 1;
	for(int i = 0; (i < n); ++i){
		if(a[i] != max_rank){
			if(x == 0) break;
			x--;i--;
		}
		max_rank++;
	}
	while(x){
		max_rank++;
		x--;
	}
	cout<<max_rank-1;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}