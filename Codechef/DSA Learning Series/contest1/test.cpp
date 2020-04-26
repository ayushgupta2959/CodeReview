#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	int x;
	bool flag = true;
	while(cin>>x){
		if(flag){
			if(x == 42) flag = false;
			else cout<<x<<"\n";
		}
	}

  	return 0;
}