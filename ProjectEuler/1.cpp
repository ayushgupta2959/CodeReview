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
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	///////////////////////////////////////

	// int result = 0;
	// for(int i = 1; i < 1000; ++i){
	// 	if(i%5 == 0 || i%3 == 0) result += i;
	// }
	// cout<<result;

	int nth3 = 999/3;
	int nth5 = 999/5;
	int nth15 = 999/15;
	int first3 = 3;
	int last3 = 3*nth3;
	int last5 = 5*nth5;
	int last15 = 15*nth15;

	int sum = (nth3*(3+last3))/2;
	sum += (nth5*(5+last5))/2;
	sum -= (nth15*(15+last15))/2;
	cout<<sum;

  	return 0;
}
//233168