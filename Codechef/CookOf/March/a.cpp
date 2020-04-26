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
	string s;
	cin>>s;
	pair<int,int> p, t;
	unordered_map<char, pair<int,int>> m;
	m['L'] = {-1,0};
	m['R'] = {1,0};
	m['U'] = {0,1};
	m['D'] = {0,-1};
	p = m[s[0]];

	for(int i = 1; i < n; ++i){
		if((s[i] == 'L' || s[i] == 'R') && (s[i-1] == 'L' || s[i-1] == 'R')) continue;
		if((s[i] == 'U' || s[i] == 'D') && (s[i-1] == 'U' || s[i-1] == 'D')) continue;

		t = m[s[i]];
		p.first += t.first;
		p.second += t.second;
	}
	cout<<p.first<<" "<<p.second;
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