#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define INF 0x3f

vector <int> graph[MAXN];
int dist[MAXN], from[MAXN];
bool vis[MAXN];
int bfs(int u, int v)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    vis[u] = vis[v] = 1;
    dist[u] = dist[v] = 0;
    from[u] = u;
    from[v] = v;
    q.push(u);
    q.push(v);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i : graph[curr])
        {

            if (!vis[i])
            {
                vis[i] = 1;
                dist[i] = dist[curr] + 1;
                from[i] = from[curr];
                q.push(i);
            }

            else if (from[i] ^ from[curr])
                return dist[i] + dist[curr] + 1;
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
    for(int i=0; i<MAXN; i++)
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
    if(u^v)
    {
        p[u]=v;
        return 1;
    }
    return 0;
}
// driver function
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setUp();
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
        unionSet(a,b);
    }
    while(q--)
    {

        int a,b;
        cin>>a>>b;
        if(a==b)
            printf("0\n");
        else if(findSet(b)!=findSet(a))
            printf("-1\n");
        else
            printf("%d\n",bfs(a,b));
    }

    return 0;
}
