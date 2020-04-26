//Maximize LCM
#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

int maxN = 1e4+5;
vector<bool> is_prime(maxN, true);
set<int> primes;

void pre(){
	is_prime[1] = false;
	is_prime[0] = false;
	is_prime[2] = true;
	for(int i = 4; i <= maxN; i+=2) is_prime[i] = false;

	for(int i = 3; i*i <= maxN; i+=2){
		if(is_prime[i]){
			for(int j = i*i; j <= maxN; j+=2*i){
				is_prime[j] = false;
			}
		}
	}

	for(int i = 1; i <= maxN; ++i){
		if(is_prime[i]){
			primes.insert(i);
		}
	}
}

void solve(){
	int n, m;
	cin>>n>>m;
	set<int> t_primes = primes;
	int x;
	for(int i = 0; i < n; ++i){
		cin>>x;
		auto it = primes.begin();
		while(x!=1 && !is_prime[x]){
			if((x % (*it))==0){
				if(t_primes.count(*it)) t_primes.erase(t_primes.lower_bound(*it));
				x/=(*it);
			}
			else{
				it = next(it);
			}
		}
		if(is_prime[x] && t_primes.count(x)){
			t_primes.erase(t_primes.lower_bound(*it));
		}
	}
	auto it = t_primes.upper_bound(m);
	if(it != t_primes.begin()){
		cout<<*prev(it);
	}
	else cout<<1;
}
int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
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