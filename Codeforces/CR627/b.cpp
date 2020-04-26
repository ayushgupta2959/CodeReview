#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))
#define S second
#define F first
#define EB emplace_back

bool solve(){
	int n;
	cin>>n;
	int x;
	unordered_map<int, vector<int>> m; 
	for(int i = 0; i < n; ++i){
		cin>>x;
		m[x].emplace_back(i);
	}
	for(auto& e: m){
		if(e.S.back() - e.S.front() > 1) return true;
	}
	return false;
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
		if(solve()) cout<<"YES";
		else cout<<"NO";
		cout<<"\n";
	}

  	return 0;
}