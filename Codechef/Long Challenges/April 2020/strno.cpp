#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int mxn = 1e5+7;
vector<bool> is_prime(mxn+1, true);

void pre(){
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i = 4; i <= mxn; i+=2) is_prime[i] = false;

	for(int i = 3; i*i <= mxn; i+=2){
		if(is_prime[i]){
			for(int j = i*i; j <= mxn; j += 2*i){
				is_prime[j] = false;
			}
		}
	}
}

void solve(){
	int x, k;
	cin>>x>>k;
	int count = 0;
	for(int i = 2; i*i <= x; ++i){
		if(is_prime[i]){
			while( x % i == 0){
				count++;
				x /= i;
				// cout<<i<<" "<<count<<" "<<x<<"\n";
			}

		}
	}

	if( x != 1 ) count++;
	if(count >= k) cout<<1;
	else cout<<0;

}
int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	pre();

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}