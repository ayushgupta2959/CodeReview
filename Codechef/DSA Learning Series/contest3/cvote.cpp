#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define FF first
#define SS second

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n, m;
	cin>>n>>m;

	unordered_map<string, string> name_to_country;
	unordered_map<string, int> name_freq;
	unordered_map<string, int> country_freq;

	string name, country;
	for(int i = 0; i < n; ++i){
		cin>>name>>country;
		name_to_country[name] = country;
	}

	for(int i = 0; i < m; ++i){
		cin>>name;
		name_freq[name]++;
		country_freq[name_to_country[name]]++;
	}

	int f = 0;
	string res_country, res_name;

	for(auto& x: country_freq){
		// cout<<x.FF<<" "<<x.SS<<"\n";
		if(x.SS > f){
			res_country = x.FF;
			f = x.SS;
		}
		else if(x.SS == f && x.FF < res_country){
			res_country = x.FF;
		}
	}

	f = 0;

	for(auto& x: name_freq){
		// cout<<x.FF<<" "<<x.SS<<"\n";
		if(x.SS > f){
			res_name = x.FF;
			f = x.SS;
		}
		else if(x.SS == f && x.FF < res_name){
			res_name = x.FF;
		}
	}

	cout<<res_country<<"\n"<<res_name;

  	return 0;
}