#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
const int MAXN1=1000000;
struct Edge
{
    int v,w;
    // edge connects from u to v with weight w
};
ll parameters[3][MAXN],cherriesStart[MAXN];
vector<Edge> tree[MAXN];
void addEdge(int u,int v,int w)
{
    tree[u].push_back({v,w});
    tree[v].push_back({u,w});
}
/*
param[0] means parent edge weight
param[1] sum of all child node edges
param[2] sum of all cherries within the subtree
*/
void dfs(int cur,int prev)
{
    parameters[2][cur]=cherriesStart[cur];
    for(Edge e:tree[cur])
    {
        if(e.v==prev)
            continue;
        dfs(e.v,cur);
        parameters[0][e.v]=e.w;
        parameters[1][cur]+=(parameters[1][e.v]+e.w);
        parameters[2][cur]+=parameters[2][e.v];
    }
}

int main()
{
    int n, c, k;
    scan(n);
    scan(c);
    scan(k);
    for(int i=1; i<=n; i++)
    {
        int input;
        scan(input);
        cherriesStart[i] = input;
    }
    for(int i=1; i<=n-1; i++)
    {
        int a, b, c;
        scan(a); // node one
        scan(b); // node two
        scan(c); // weight
        addEdge(a, b, c);
    }
    dfs(1,0);
    long long ways=0;
    parameters[0][1]=MAXN;
    for(int i=1; i<=n; i++)
    {
        if((parameters[0][i]+parameters[1][i]<=k)&&parameters[2][i]>=c)
        {
            ways++;
        }
    }
    printf("%lld\n",ways);
    return 0;
}
