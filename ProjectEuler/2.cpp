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

	unsigned long long sum = 0;
	unsigned long long f1 = 1, f2 = 2, t;
	while(f2 <= 4000000){
		if(!(f2&1)) sum += f2;
		t = f1+f2;
		f1 = f2;
		f2 = t;
	}

	cout<<sum;
  	return 0;
}