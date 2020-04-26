#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

bool solve(){
	string s;
	cin>>s;
	vector<int> fl(26, 0), fr(26, 0);
	int l = s.size();
	int i = 0;
	while(i < l/2){
		fl[s[i]-'a']++;
		i++;
	}
	if(l&1) i++;
	while(i < l){
		fr[s[i]-'a']++;
		i++;
	}

	for(i = 0; i < 26; ++i){
		// cout<<fl[i]<<" "<<fr[i]<<"\n";
		if(fl[i]^fr[i]) return false;
	}
	return true;

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