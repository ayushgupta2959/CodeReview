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

	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;

	vector<int> red(a);
	vector<int> green(b);
	vector<int> colorless(c);

	for(auto& x: red) cin>>x;
	for(auto& x: green) cin>>x;
	for(auto& x: colorless) cin>>x;	

	sort(red.rbegin(), red.rend());
	sort(green.rbegin(), green.rend());
	// sort(colorless.rbegin(), colorless.rend());

	vector<long long> result_apples;
	for(int i = 0; i < min(x,a); ++i) result_apples.emplace_back(red[i]);
	for(int i = 0; i < min(y,b); ++i) result_apples.emplace_back(green[i]);
	for(int i = 0; i < c; ++i) result_apples.emplace_back(colorless[i]);

	sort(result_apples.rbegin(), result_apples.rend());
	cout<<accumulate(result_apples.begin(), result_apples.begin() + x + y, 0ll);

  	return 0;
}