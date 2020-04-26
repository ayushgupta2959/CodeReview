#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////
	string s;
	cin>>s;
	int n = s.length();
	vector<int> lps(n, 0);
	int i = 0, j=1;

	while(j < n){
		if(s[i] == s[j]){
			lps[j] = i+1;
			i++;
			j++; 
		}
		else{
			if(i==0){
				j++;
				continue;
			}
			i = lps[i-1];
		}
	}

	if(lps[n-1] >= n/2) cout<<"Yes";
	else cout<<"No";

  return 0;
}