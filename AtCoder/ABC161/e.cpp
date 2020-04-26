#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

bool solve(int i, string& s, int c int k, map<pair<int,int>, bool>& m, vector<int> & result){
	if(k == 0) return true;
	if(i >= s.size()) return false;

	if(m.find({i, k}) != m.end()) return m[{i,k}];

	bool r1 = true, r2 = true;
	if(s[i] != 'x') r1 = solve(i+c,s, c, k-1,m);
	r2 = solve(i+1, s,c, k,m);

	if(s[i] != 'x' && r1 && !r2){
		result.emplace_back()
	}
}

int main() {
	sp;

	////////////////To Remove//////////////
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n,k,c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	map<pair<int,int>, bool> m;
	vector<int> result;

	solve(0, s, c, k, m);

	for(auto& x: result) cout<<x<<"\n";

  	return 0;
}