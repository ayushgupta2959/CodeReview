#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define test cerr<<"abcd\n";

int main() {
  int t, s, w1, w2, w3, hits;
  cin>>t;

  while(t--){
    cin>>s>>w1>>w2>>w3;
    if(s == 1){
      hits = 3;
    }
    else{
      if(s >= w1+w2+w3){
        hits = 1;
      }
      else if(s >= w1+w2 || s>= w2+w3){
        hits = 2;
      }
      else hits = 3;
    }
    cout<<hits<<'\n';
  }
  return 0;
}


