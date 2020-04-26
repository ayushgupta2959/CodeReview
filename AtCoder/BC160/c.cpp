#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int k, n;
	cin>>k>>n;
	vector<int> a(n);
	for(auto& x: a) cin>>x;
	sort(a.begin(), a.end());

	int gap = 0;

	for(int i = 0; i < n-1; ++i){
		gap = max(gap, a[i+1]-a[i]);
	}

	gap = max(gap, k-a[n-1]+a[0]);
	// long long result = 0;
	// long long cr = 0;

	// for(int i = 0; i < n-1; ++i){
	// 	result += abs(a[i]-a[i+1]);
	// 	// cout<<abs(a[i]-a[i+1])<<" ";
	// }
	// // cout<<"\n";
	// cr = result;
	// // cout<<result<<"\n";

	// for(int i = 0; i < n-1; ++i){
	// 	result -= abs(a[i]-a[i+1]);
	// 	result += abs(a[n-1+i]-a[n + i]);
	// 	cr = min(result, cr);
	// }

	// cout<<cr;

	cout<<k-gap;

  	return 0;
}