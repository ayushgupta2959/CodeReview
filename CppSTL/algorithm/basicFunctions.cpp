#include<bits/stdc++.h>
using namespace std;
bool comp1(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
bool comp2(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //functions to check for usage
    /*
    remove_if()
    revere_copy()
    lower_bound()
    merge()
    sort()
    */
    //next_permutation(range.begin(),range.end())
    int arr[4] = {1,2,3,4};
    int n = 4;
    do{
        for(int i=0;i<n;++i) cout<<arr[i]<<" ";
        cout<<"\n";
    }while(next_permutation(arr,arr+n));

    //accumulate(range.begin(),range.end(),initial_value_of_sum)
    int sum = accumulate(arr,arr+n,0);
    cout<<sum<<"\n";

    //min_element()
    auto x = min_element(arr,arr+n);
    cout<<*x<<"\n";

    vector<pair<int,int>> vp;
    vp.emplace_back(make_pair(1,2));
    vp.emplace_back(make_pair(0,9));
    vp.emplace_back(make_pair(2,0));
    vp.emplace_back(make_pair(5,1));

    auto y = min_element(vp.begin(),vp.end());
    cout<<(*y).first<<" "<<(*y).second<<"\n";

    y = min_element(vp.begin(),vp.end(),comp1);
    cout<<(*y).first<<" "<<(*y).second<<"\n";

    y = min_element(vp.begin(),vp.end(),comp2);
    cout<<(*y).first<<" "<<(*y).second<<"\n";

    return 0;
}
