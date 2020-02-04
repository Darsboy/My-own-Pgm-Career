#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define level 18
#define INF 0x3f
int n,m,q;
vector <int> graph[MAXN];
int arr[2][MAXN];
int bfs(int u, int v)
{

    memset(arr,-1,sizeof(arr));
    int nv=-1;
    deque<pair<int,bool>>q;
    arr[0][u]=arr[1][v]=0;
    q.emplace_back(u,0);
    q.emplace_back(v,1);
    while(!q.empty())
    {
        pair<int,bool> cur=q.front();
        q.pop_front();
        for(int fut:graph[cur.first])
        {
            if(arr[cur.second][fut]==-1)
            {
                arr[cur.second][fut]=arr[cur.second][cur.first]+1;
                if(arr[!cur.second][fut]!=nv)
                {
                    return (arr[!cur.second][fut]+arr[cur.second][fut]);
                }
                q.emplace_back(fut,cur.second);
            }
        }
    }
}


void addEdge(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int p[MAXN];
void setUp()
{
    for(int i=0; i<=n; i++)
    {
        p[i]=i;
    }
}
int findSet(int i)
{
    if(i==p[i])
        return i;
    return p[i]=findSet(p[i]);
}
bool unionSet(int u,int v)
{
    u=findSet(u);
    v=findSet(v);
    if(u!=v)
    {
        p[u]=v;
        return 1;
    }
    return 0;
}

// driver function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin>>n>>m>>q;
    setUp();
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
        unionSet(a,b);
    }
    for(int i=0; i<q; i++)
    {

        int a,b;
        cin>>a>>b;
        if(findSet(b)!=findSet(a))
            printf("-1\n");
        else if(a==b)
            printf("0\n");
        else
            printf("%d\n",bfs(a,b));
    }

    return 0;
}
