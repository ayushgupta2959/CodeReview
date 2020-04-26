#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(auto& x: a) cin>>x;
	for(auto& x: b) cin>>x;

	// vector<int> c(n);
	// for(int i = 0; i < n; ++i) c[i] = a[i] - b[i];
	// sort(c.begin(), c.end());

	// long long result = 0;
	// int term;
	// int prev = 0;
	
	// for(int i = 0; i < n; ++i){
 //        term = b[i] - a[i];
 //        result += c.end() - upper_bound(c.begin(), c.end(), term);
 //        if(term < 0 ){
 //        	result -= 1;
 //        }
	// }

	// cout<<result/2;

	oset<int> s;
	long long result = 0;
	for(int i = 0; i < n; ++i){
		result += s.order_of_key(b[i]-a[i]);
		s.insert(a[i]-b[i]);
	}

	cout<<result;

  	return 0;
}