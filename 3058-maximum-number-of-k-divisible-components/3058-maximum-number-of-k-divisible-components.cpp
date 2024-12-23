const int N = 3e4 + 10;
int e[N<<1],ne[N<<1],h[N];
int idx =0 ;
void add(int u,int v){
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}
typedef long long ll;
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        memset(h,-1,sizeof h);
        idx = 0;
        for(auto& e : edges){
            add(e[0], e[1]);
            add(e[1], e[0]);
        }
        int ans= 0;
        auto dfs = [&](auto && dfs,int u,int fa) -> ll{
            ll res = values[u];
            for(int i = h[u]; i != -1; i = ne[i]){
                int v = e[i];
                if(v != fa){
                    res += dfs(dfs,v,u);
                }
            }
            ans += res%k == 0;
            return res;
        };
        dfs(dfs,0,-1);
        return ans;
    }
};