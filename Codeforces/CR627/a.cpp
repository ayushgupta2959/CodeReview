#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))
bool solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto& x: a) cin>>x;

	int mn = *min_element(a.begin(), a.end());
	for(auto& x: a){
		if((x-mn)&1) return false;
	}
	return true;
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