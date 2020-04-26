#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

string A, s;
int i, j, n, l;

void solve(){
  cin>>A;
  n = A.length();

  if(n == 1){
    cout<<A;
    return;
  }

  vector<vector<bool>> is_pd(n, vector<bool>(n, false));
  is_pd[0][0] = true;
  
  for(i = 1; i < n; ++i){
    is_pd[i][i] = true;
    is_pd[i][i-1] = true;
  }
  
  for(l = 2; l <= n; ++l){
    for(i = 0; i <= (n-l); ++i){
      j = i + l - 1;
      if(A[i] == A[j] && is_pd[i+1][j-1]) is_pd[i][j] = true;
    }
  }

  string prefix, suffix, rev_prefix, rev_suffix;
  vector<bool> iseq_prefix_and_rev_suffix(n+1), iseq_suffix_and_rev_prefix(n+1);
  iseq_prefix_and_rev_suffix[0] = true;
  iseq_suffix_and_rev_prefix[0] = true;
  for(i = 1; i <= n; ++i){
    prefix = A.substr(0, i);
    suffix = A.substr(n-i,i);
    rev_prefix.assign(prefix.rbegin(), prefix.rend());
    rev_suffix.assign(suffix.rbegin(), suffix.rend());

    if(prefix == rev_suffix)  iseq_prefix_and_rev_suffix[i] = true;
    if(suffix == rev_prefix)  iseq_suffix_and_rev_prefix[i] =  true;
  }

  int rlen = 0, ri, rj, is_prefix;
  string result;
  for(i = 1; i <=n; ++i){
    for(j = 0; j <= i; ++j){
      if(iseq_prefix_and_rev_suffix[j] && (j==i||is_pd[j][i-1]) && (j + i)<=n && (i + j) > rlen){
        rlen = i+j;
        is_prefix = 1;
        ri = i;
        rj = j;
      }

      else if(iseq_suffix_and_rev_prefix[j] && (j==i||is_pd[n-i][n-j-1]) && (j + i)<=n && (i + j) > rlen){
        rlen = i+j;
        is_prefix = 0;
        ri = i;
        rj = j;
      }
    }
  }

  // cout<<is_prefix<<" "<<ri<<" "<<rj<<"\n";

  if(is_prefix){
    result = A.substr(0, ri) + ((rj==0)?"":A.substr(n-rj, rj));
  }
  else{
    result = ((rj==0)?"":A.substr(0, rj)) + A.substr(n-ri, ri);
  }
  cout<<result;
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
    solve();
    cout<<"\n";
  }

  return 0;
}