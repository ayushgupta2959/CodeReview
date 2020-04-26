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
	long long a,b,c,d,x,y,x1,x2,y1,y2;
	cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
	if((a >= 1 || b>=1) && (abs(x1-x2) == 0)) return false;
	if((c >= 1 || d>=1) && (abs(y1-y2) == 0)) return false;
	if(a-abs(x1-x) > b) return false;
	if(b-abs(x2-x) > a) return false;
	if(c-abs(y1-y) > d) return false;
	if(d-abs(y2-y) > c) return false;
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
		if(solve()) cout<<"Yes";
		else cout<<"No";
		cout<<"\n";
	}

  	return 0;
}