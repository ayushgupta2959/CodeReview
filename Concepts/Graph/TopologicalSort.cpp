class Solution {
public:
    bool dfs(vector<vector<int>> &g,int node,vector<bool> &visited,vector<bool> &onStack){
        for(auto x:g[node]){
            if(onStack[x]) return true;
            else if(!visited[x]){
                visited[x]=true;
                onStack[x]=true;
                if(dfs(g,x,visited,onStack)) return true;
                onStack[x]=false;
            }
        }
        return false;
    }
    bool is_cyclic(vector<vector<int>> &g){
        int n = g.size();
        vector<bool> onStack(n,false);
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                visited[i]=true;
                onStack[i]=true;
                if(dfs(g,i,visited,onStack)) return true;
                onStack[i]=false;
            }
        }
        return false;
    }
    void dfs2(vector<vector<int>> &g,int node,vector<int> &indegree,vector<int> &result,vector<bool> &visited){
        for(auto x:g[node]){
            if(!visited[x] && indegree[x]==0){
                result.emplace_back(x);
                visited[x]=true;
                for(auto y:g[x]){
                    if(indegree[y]>0) indegree[y]--;
                }
                dfs2(g,x,indegree,result,visited);
            }
        }
    }
    vector<int> topologicalSort(vector<vector<int>> &g){
        vector<int> result;
        int n = g.size();
        vector<int> indegree(n,0);
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            for(auto x:g[i]) indegree[x]++;
        }
        for(int i=0;i<n;++i){
            if(indegree[i]==0 && !visited[i]){
                result.emplace_back(i);
                visited[i]=true;
                for(auto x:g[i]){
                    if(indegree[x]>0) indegree[x]--;
                }
                dfs2(g,i,indegree,result,visited);
            }
        }
        return result;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(auto x:prerequisites){
            g[x[1]].emplace_back(x[0]);
        }
        if(is_cyclic(g)) return {};
        else{
            return topologicalSort(g);
        }
    }
};