#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long

bool solve(){
	string k;
	vector<int> d(7);
	cin>>k;
	cin>>d[0]>>d[1];

	ll num = stoll(k);
	d[2] = (d[0]+d[1])%10;
	d[3] = (2*d[2])%10;
	d[4] = (4*d[2])%10;
	d[5] = (8*d[2])%10;
	d[6] = (6*d[2])%10;

	if(num <= 7){
		ll sum = 0;
		for(int i = 0; i < num; ++i){
			sum += d[i];
		}
		return sum%3==0;
	}

	ll sum_cycle = d[3]+d[4]+d[5]+d[6];
	ll sum = d[0]+d[1]+d[2];

	num -= 4;
	sum += sum_cycle*((num/4));

	num %= 4;
	for(int i = 0; i <= num; ++i){
		sum += d[3+i];
	}


	return sum%3 == 0;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		if(solve()) cout<<"YES";
		else cout<<"NO";
		cout<<"\n";
	}

  	return 0;
}