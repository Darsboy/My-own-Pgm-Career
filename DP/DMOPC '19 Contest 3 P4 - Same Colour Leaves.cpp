#include<bits/stdc++.h>
using namespace std;
// v(i)
typedef long long ll;
const int MM=3e5+5,mod=1e9+7;

int N,clr[MM];
string s;
vector<int> adj[MM];
ll ans,dp[MM];
// the x values are the child nodes.
// dp= 1+sumX+v
/*
int sumX(int i,int j)
{
    return psa[j]-psa[i];
}
int v(int i)
{
    return v(i-1)+(sumX(1,i-1)+v(i-1))*x[i];
}
*/

void dfs(int pre,int cur,int coulor)
{
    ll sum=0,comb=0;
    for(int i:adj[cur])
    {
        if(i==pre)
            continue;
        dfs(cur,i,coulor);
        comb+=(sum+comb)*dp[i];
        sum+=dp[i];
        comb%=mod;
        sum%=mod;
    }
    int u=cur;
    if(clr[u]==coulor)
    {
        dp[u]=(1+sum+comb)%mod;
        ans=(ans+dp[u])%mod;
    }
    else
    {
        dp[u]=(sum+comb)%mod;
        ans=(ans+comb)%mod;
    }
}

int main()
{
    cin>>N>>s;
    for(int i=1; i<=N; i++)
    {
        clr[i]=(s[i-1]=='R');
    }
    for(int i=1,v,u; i<N; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(-1,1,1);
    dfs(-1,1,0);
    cout<<ans<<endl;
}
