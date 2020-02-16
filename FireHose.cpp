#include <bits/stdc++.h>
using namespace std;
int H,K,ans,LENIN=1000000;
vector<int>houses;
int mk(int gap)
{
    //printf("gap=%d\n",gap);
    int ret=LENIN,siz=houses.size(),searchLength=gap*2;
    for(int x=0; x<siz&&houses[x]<=houses[0]+searchLength; x++)
    {
    int cur=1,fin=houses[x];
    // house x is the end of the first hydrent's coverage
    for(int y=x+1; y<siz&&(houses[y]+searchLength)<houses[x]+LENIN; y++)
    {
        //houses[y]+searchLength-LENIN is always a behind houses[x]
        //printf("%d ? %d\n",houses[y],fin);
        if(houses[y]>fin)
        {

            fin=houses[y]+searchLength;
            cur++;

        }

    }
    //printf("cur=%d\n",cur);
    ret=min(ret,cur);


    return ret;
}
int main()
{
    scanf("%d",&H);
    for(int i=0,tmp; i<H; i++)
    {
        scanf("%d",&tmp);
        houses.push_back(tmp);
    }
    //sort from smallest to largest
    sort(houses.begin(),houses.end());
    scanf("%d",&K);
    int l=0,h=LENIN,mid;
    while(l<h)
    {
        mid=(l+h)/2;
        if(mk(mid)<=K)
        {
            ans=mid;
            h=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%d",ans);
}
