
#include<bits/stdc++.h>
using namespace std;
const int MM=1e5+1,mod=1e9+7;
int N,ways[MM],ans[MM],M,inDeg[MM],outDeg[MM];
vector<int>graph[MM];
int dp(int start)
{
    if(graph[start].empty())
    {
        ways[start]=1;
        return ans[start]=0;
    }
    if(ans[start]!=0)
        return ans[start];
    for(int fut:graph[start])
    {
        dp(fut);
        ways[start]=(ways[fut]%mod+ways[start]%mod)%mod;
        ans[start]=(ans[fut]%mod+ans[start]%mod)%mod;
    }
    ans[start]=(ans[start]+ways[start])%mod;
    return ans[start];
}


int main()
{
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        int a,b;
        cin>>a>>b;
        outDeg[a]++;
        inDeg[b]++;
        graph[b].push_back(a);
    }
    int ret=0;
    for(int i=1; i<=N; i++)
    {
        if(!outDeg[i])
        {
            ret=(ret%mod+dp(i)%mod)%mod;
        }
    }
    printf("%d\n",ret);
}
