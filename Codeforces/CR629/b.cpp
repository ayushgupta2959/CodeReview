#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

// vector<int> getFactoradic(int n, int k){
// 	vector<int> fact(n, 0);
// 	int i = 1;
// 	while(k){
// 		fact[n-i] = k%i;
// 		k/=i;
// 		i++;
// 	}
// 	return fact;
// }

// void solve(){
// 	int n, k;
// 	cin>>n>>k;
// 	int fa = n-2;
// 	int fb = 2;
// 	string result = "";
// 	vector<int> fact = getFactoradic(n, k-1);
// 	for(int i=0; i<n;++i){
// 		if(fact[i]<fa){
// 			result+='a';
// 			fa--;
// 		}
// 		else result +='b';
// 	}
// 	cout<<result;
// }
void solve(){
	long long n, k;
	cin>>n>>k;
	long long fa = n-2, fb = 2, sum;
	long long i = 1;
	while(fa && fb){
		if(fb == 2) sum = ((n-i)*(n-i-1))/2;
		else sum = (n-i);
		if(sum >= k){
			cout<<"a";
			fa--;
		}
		else{
			cout<<"b";
			fb--;
			k -= sum;
		}
		i++;
	}
	while(fa){
		cout<<"a";
		fa--;
	}
	while(fb){
		cout<<"b";
		fb--;
	}
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