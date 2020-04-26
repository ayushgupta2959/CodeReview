#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int t, n, s, p, v;
	int result;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s>>p>>v;
		result = (p/(s+1))*v;
		n--;
		while(n--){
			cin>>s>>p>>v;
			result = max(result, (p/(s+1))*v);
		}
		cout<<result<<"\n";
	}
  return 0;
}