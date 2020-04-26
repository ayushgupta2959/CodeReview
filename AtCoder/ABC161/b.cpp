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


	int n,m;
	cin>>n>>m;
	vector<long long> a(n);
	for(auto& x: a) cin>>x;
	nth_element(a.begin(), a.begin()+m-1, a.end(), greater<int>());

	// for(auto& x: a) cout<<x<<" ";

	// cout<<"\n";

	long long sum = accumulate(a.begin(), a.end(), 0ll);

	if(a[m-1]*4*m >= sum) cout<<"Yes";
	else cout<<"No";

	// int count = 0;
	// double limit = sum/(4.0*m);
	// for(auto& x: a){
	// 	if(x < limit) count++;
	// } 

	// if(n-count >= m) cout<<"Yes";
	// else cout<<"No"; 

  	return 0;
}