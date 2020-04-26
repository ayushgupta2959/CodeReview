#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string a = "",b = "";
	bool is_a_greater = false;
	for(int i = 0; i < n; ++i){
		if(!is_a_greater){
			if(s[i] == '0'){
				a+='0';
				b+='0';
			}
			else if(s[i]=='1'){
				a+='1';
				b+='0';
				is_a_greater = true;
			}
			else{
				a+='1';
				b+='1';
			}
		}
		else{
			if(s[i]=='0'){
				a+='0';
				b+='0';
			}
			else if(s[i]=='1'){
				a+='0';
				b+='1';
			}
			else{
				a+='0';
				b+='2';
			}
		}
	}
	cout<<a<<"\n"<<b;

}
int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}