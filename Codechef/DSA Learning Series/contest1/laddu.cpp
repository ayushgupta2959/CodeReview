#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
	int n, rank, severity;
	string origin, activity;
	cin>>n;
	cin>>origin;
	int score = 0;
	while(n--){
		cin>>activity;
		if(activity == "CONTEST_WON"){
			cin>>rank;
			score += 300 + max(0, 20-rank);
		}
		else if(activity == "TOP_CONTRIBUTOR"){
			score += 300;
		}
		else if(activity == "BUG_FOUND"){
			cin>>severity;
			score += severity;
		}
		else{
			score += 50;
		}
	}
	if(origin == "INDIAN"){
		cout<<score/200;
	}
	else{
		cout<<score/400;
	}
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
		solve();
		cout<<"\n";
	}
  	return 0;
}