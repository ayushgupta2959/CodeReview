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
	int n;
	cin>>n;
	vector<long long> a(n);
	int p = 1e9+7;
	for(auto& x: a) cin>>x;

	sort(a.rbegin(), a.rend());

	long long d = 0;
	long long result = 0;

	for(auto& x: a){
		result = (result + max(0ll, x-d))%p;
		d++;
	}
	
	cout<<result;
}
int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}