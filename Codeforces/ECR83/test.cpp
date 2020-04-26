#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the chessboardGame function below.
vector<int> dx = {-2, -2, 1, -1};
vector<int> dy = {1, -1, -2, -2};
vector<vector<int>> sp(15, vector<int>(15));    

int mex(vector<int> &a){
    sort(a.begin(), a.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    int j = -1;
    for(int i = 0; i < a.size(); ++i){
        if(a[i]^j) return i;
    }
    return a.size();
}

int game_helper(int x, int y){
    if(x < 0 || y < 0 || x >= 15 || y >= 15) return -1;
    if(sp[x][y] == -1){
        vector<int> a;
        for(int i = 0; i < 4; ++i){
            if()
            a.emplace_back(game_helper(x+dx[i], y+dy[i]));
        }
        sp[x][y] = mex(a);
    }
    return sp[x][y];
}

string chessboardGame(int x, int y) {
    for(auto& row: sp){
        for(auto& val: row) val = -1;
    }
    game_helper(x-1, y-1);
    return (sp[x-1][y-1])? "First" : "Second";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    int x, y;
    while(t--){
        cin>>x>>y;
        cout<<chessboardGame(x,y);
        cout<<"\n";
    }
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
