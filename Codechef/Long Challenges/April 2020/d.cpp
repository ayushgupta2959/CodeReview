#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))
#define EB emplace_back

void solve(){
	int n;
	cin>>n;
	if(n <= 3){
		cout<<1<<"\n";
		cout<<n<<" ";
		for(int i = 1; i <=n; ++i){
			cout<<i<<" ";
		}
		cout<<"\n";
		return;
	}
	int i = 1;
	cout<<n/2<<"\n";
	if(n&1){
		cout<<3<<" "<<1<<" "<<2<<" "<<3<<"\n";
		i = 4;
	}
	while(i <= n){
		cout<<2<<" "<<i<<" "<<i+1<<"\n";
		i+=2;
	}
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
	}

  	return 0;
}