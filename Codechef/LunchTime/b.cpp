//Chef Swaps Digits
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
	int A, B;
	cin>>A>>B;
	int a1 = A/10, a0 = A%10;
	int b1 = B/10, b0 = B%10;

	int one = A+B;
	int two = b1*10+a0+a1*10+b0;
	int three = a1*10+b1+a0*10+b0;
	int four = b0*10+a0+b1*10+a1;

	cout<<max({one, two, three, four});
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
		solve();
		cout<<"\n";
	} 

  	return 0;
}