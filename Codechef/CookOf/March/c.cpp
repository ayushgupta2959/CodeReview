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
#define bc(x) __builtin_popcountll(x)

vector<long long> pow2(32);
int p = 1e9+7;

void solve(){
	int n;
	cin>>n;
	vector<long long> b(n);
	for(int i=0; i<n; ++i) cin>>b[i];

	long long result = 1;
	int xprev, xnow;

	for(int i=1; i < n; ++i){
		if((b[i] & b[i-1]) != b[i-1]){
			cout<<0;
			return;
		}
		xprev = bc(b[i-1]);
		result = (result*pow2[xprev])%p;
	}
	cout<<result;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////
	pow2[0] = 1;
	for(int i = 1; i < 32; ++i) pow2[i] = (pow2[i-1]*2)%p;
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}