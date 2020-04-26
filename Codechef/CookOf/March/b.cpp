#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pair<int,int>>
#define vv(t,A,r,c,val) vector<vector<t>> A(r,vector<t>(c, val))
#define vvn(t,A) vector<vector<t>> A
#define vvv(t,A,l,b,h) vector<vector<vector<t>>> A(l,vector<vector<t>>(b,vector<t>(h)))
#define vvvn(t,A) vector<vector<vector<t>>> A

void solve(){
	int h;
	cin>>h;
	bool result = false;
	int q = 2*h+1;
	while(q--){

	}
	if(!result) exit(0);
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////

	int t;
	cin>>t;
	while(t--){
		int h;
		cin>>h;
		bool result = false;
		int q = 2*h+1;
		int node = 2;
		int dist;
		int verdict;
		while(q--){
			cout<<1<<" "<<node<<"\n"<<flush;
			cin>>dist;
			if(dist == 0){
				cout<<3<<" "<<node<<"\n"<<flush;
				cin>>node;
				if(node == 1){
					result = true;
					break;
				}
			}
			cout<<2<<" "<<node<<" "<<dist<<"\n"<<flush;
			cin>>node;
		}
		if(!result) return 0;
	}
  	return 0;
}