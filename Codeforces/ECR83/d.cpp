#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int p = 998244353;

long long mod_pow(long long x, long long y){
	long long result = 1;
	while(y){
		if(y&1) result = (result*x)%p;
		x = (x*x)%p;
		y >>= 1;
	}
	return result;
}

long long inverse_mod(long long x){
	return mod_pow(x, p-2);
}

long long nCr(long long n, long long r){
	long num = 1;
	long long denom = 1;
	r = min(n, n-r);
	for(long long i = 1; i <= r; ++i){
		num = (num*(n-i+1))%p;
		denom = (denom*i)%p;
	}
	return (num*inverse_mod(denom))%p;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////


	int n, m;
	cin>>n>>m;

	//((m)C(n-1)) * (n-2) * (2^(n-3)) <= since n-3 needs to be positive n >= 3

	long long result = 0;

	if(n >= 3){
		result = nCr(m, n-1);
		result = (result*(n-2))%p;
		result = (result*mod_pow(2, n-3))%p;
	}

	cout<<result;

  return 0;
}