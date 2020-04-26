#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////


    int t, a, b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a%b) cout<<"NO\n" : cout<<"YES\n";
    }
  	return 0;
}