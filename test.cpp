#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
#define pi pair<int,int>
#define FF first
#define SS second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using omap=tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void mod_pow(ll g, ll a, ll p){
	cout<<"powers\n";
	long long res = g;
	int pow = 1;
	cout<<pow<<" "<<g<<"\n";
	while(pow <= a){
		res = (res*res)%p;
		pow = pow*2;
		cout<<pow<<" "<<res<<"\n";
	}
	cout<<"g to the power a mod p\n";
	res = 1;
	while(a){
		if(a&1){
			res = (res*g)%p;
		}
		cout<<(a&1)<<" "<<res<<"\n";
		g = (g*g)%p;
		a>>=1;
	}
}


int main() {
	sp;

	////////////////To Remove//////////////
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	// oset<int> s;
	// s.insert(1);
	// s.insert(1);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(2);
	// s.insert(3);
	// s.insert(3);
	// s.erase(s.upper_bound(2));
	// for(auto& x: s) cout<<x<<" ";
	// cout<<"\n";
	// omap<int, string> m;
	// m[1] = "ayush";
	// m[2] = "rma";

	// for(auto& x: m) cout<<x.first<<" "<<x.second<<"\n";

	// cout<<s.order_of_key(1);

	

	// vector<int> a = {1,1,2,3,3,4,4,5,5,6,8,8};
	// sort(a.rbegin(), a.rend());
	// for(auto& x: a) cout<<x<<" ";
	// 	cout<<"\n";
	// auto x = equal_range(a.begin(), a.end(), 3, greater<int>());
	// cout<<*lower_bound(a.begin(), a.end(), 7, greater<int>());

	// int begin_index = x.first - a.begin();
	// int end_index = x.second - a.begin();

	// cout<<begin_index<<" "<<end_index;

	//---------cryptography-----------
	// long long g = 3;
	// long long a = 115;
	// long long p = 55; 

	// mod_pow(g, a, p);

	// vector<ll> t = {3,5,15,25,54,110,225};
	// ll b = 10;
	// ll p = 439;
	// vector<ll> s;
	// for(auto& x: t){
	// 	auto y = (x*b)%p;
	// 	s.emplace_back(y);
	// }
	// for(auto& x: s) cout<<x<<" ";
	/////////////////////////////////////

	// vector<pi> a = {{0, 1},
	// 				{2, 5},
	// 				{6, 9},
	// 				{10, 15}	
	// };

	// set<pi> s(a.begin(), a.end());

	// for(auto& x: s)cout<<x.FF<<" "<<x.SS<<"\n";

	// auto x = *s.lower_bound({0, INT_MAX});
	// cout<<x.FF<<" "<<x.SS<<"\n";

	vector<vector<int>> g = {
		{1, 2},
		{2, 3, 4},
		{1, 2, 3},
		{0, 1},
		{0, 1, 2, 3, 4, 5}
	};

	sort(g.begin(), g.end());
	vector<int> haha = {1};
	auto t = *lower_bound(g.begin(), g.end(), haha);
	for(auto& x: t) cout<<x<<" ";

	cout<<"\n";
	for(auto& x: g){
		for(auto& y: x) cout<<y<<" ";
		cout<<"\n";
	}

  	return 0;
}