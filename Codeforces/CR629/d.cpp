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
	v(int) a(n);
	v(int) color(n, 1);
	for(auto& x: a) cin>>x;

	int last_dup = -1;

	for(int i = 1; i < n; ++i){
		if(a[i-1]^a[i]){
			color[i] = 3-color[i-1];
		}
		else{
			last_dup = i;
			color[i] = color[i-1];
		}
	}

	if(color[0] == color[n-1] && a[n-1] != a[0]){
		if(last_dup == -1){
			color[n-1] = 3;
		}
		else{
			for(int i = last_dup; i < n; ++i) color[i] = 3-color[i];
		}
	}

	cout<<*max_element(color.begin(), color.end())<<"\n";
	for(int i = 0; i < n; ++i) cout<<color[i]<<" \n"[i==n-1];
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
	}

  	return 0;
}
