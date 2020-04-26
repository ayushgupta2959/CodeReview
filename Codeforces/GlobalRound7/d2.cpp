#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int get_lpp(string s){
	string t = s + '$';
	reverse(s.begin(), s.end());
	t += s;
	int n = t.length();

	vector<int> lps(n, 0);

	int i = 0, j = 1;
	while(j < n){
		if(t[i] == t[j]){
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
	return lps[n-1];
}

void solve(){
	string A;
	cin>>A;

	int n = A.length();
	int low = 0, high = n-1;
	while(A[low] == A[high]){
		low++;
		high--;
	}

	if(low >= high){
		cout<<A;
		return;
	}


	string t = A.substr(low, (high - low) + 1);
	int lpp = get_lpp(t); //longest palindromic prefix
	int lps = get_lpp({t.rbegin(), t.rend()});

	// cout<<lpp<<" "<<lps<<"\n";

	if(lpp >= lps){
		cout<<A.substr(0, low)<<t.substr(0, lpp)<<A.substr(n-low,low);
	}
	else{
		cout<<A.substr(0, low)<<t.substr(t.length() - lps, lps)<<A.substr(n-low, low);
	}
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	vector<vector<int>> v;
	while(t--){
		solve();
		cout<<"\n";
	}

  return 0;
}