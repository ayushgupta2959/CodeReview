/* Input
9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
0
Expected output :- 
*/
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int find_min(vector<int> &dist,vector<bool> &done){
	int min = INT_MAX;
	int min_node;
	int v = dist.size();
	for(int i=0;i<v;++i){
		if(!done[i] && dist[i]<min){
			min = dist[v];
			min_node = v;
		}
	}
	return min_node;
}
vector<int> singleSourceAllNodesShortestPath(vector<vector<pi>> &graph,int v,int e,int s){
	vector<int> dist(v,INT_MAX);
	dist[s] = 0;
	vector<bool> done(v,false);
	int x,w;
	while(v--){
		int min_node = find_min(dist,done);
		done[min_node] = true;
		for(auto node:graph[min_node]){
			x = node.first;
			w = node.second;
			dist[x] = min(dist[x],dist[min_node]+w);
		}
	}
	return dist;
}
int main() {
	int v,e,s;
	cin>>v>>e;
	vector<vector<pi>> graph(v,vector<pi>());
	int x,y,w;
	for(int i=0;i<e;++i){
	    cin>>x>>y>>w;
	    graph[x].emplace_back(make_pair(y,w));
	    graph[y].emplace_back(make_pair(x,w));
	}
	cin>>s; //source
    vector<int> shortest_distance = singleSourceAllNodesShortestPath(graph,v,e,s);
    for(int i=0;i<v;++i){
        cout<<i<<":"<<shortest_distance[i]<<"\n";
    }
	return 0;
}