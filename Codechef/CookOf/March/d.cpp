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

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin>>a[i];

	int max_val = *max_element(a.begin(), a.end());

	int lo = -1, hi = -1;
	int count = 0;
	int dist = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] ^ max_val) continue;
		if(lo == -1){
			lo = i;
			hi = i;
			count++;
			continue;
		}
		dist = max(dist, min(i-hi, n-i+hi));
		hi = i;
		count++;
	}
	if(count >= n/2){
		cout<<0;
		return;
	}
	if(count == 1){
	    cout<<n/2;
	    return;
	}
	
	dist = max(dist, min(hi-lo, n-hi+lo));
	cout<<n/2 - dist;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}