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
	int n, x, y;
	cin>>n>>x>>y;

	vector<int> dist(n,0);
	int d;


	for(int i = 1; i <= n; ++i){
		for(int j = i+1; j <= n; ++j){
			d = min({abs(i-j), abs(i-x) + 1 + abs(y-j), abs(i-y) + 1 + abs(x-j)});
			dist[d]++;
		}
	}

	for(int i = 1; i < n; ++i){
		cout<<dist[i]<<"\n";
	}

}
int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	// int t;
	// cin>>t;
	// while(t--){
	// 	solve();
	// 	cout<<"/n";
	// }

	solve();

  	return 0;
}