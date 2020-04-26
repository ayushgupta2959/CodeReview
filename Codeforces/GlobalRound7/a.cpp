#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	///////////////////////////////////////


	int t, n, i;
  cin>>t;
  while(t--){
    cin>>n;
    if(n == 1) cout<<"-1\n";
    else{
      cout<<"2";
      for(i = 1; i < n; ++i) cout<<"3";
      cout<<"\n";
    }
  }

  return 0;
}