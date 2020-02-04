#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
private:

    struct node
    {
        int l,r,val;
    };
    node *tree,*lazy;
    int N,*arr;
    // one Indexed
    void printNode(node a)
    {
        printf("Node [%d %d] val=%d\n",a.l,a.r,a.val);
    }
    int QQ(int l,int r,int nds)
    {
printf("node %d [%d %d]\n",nds,l,r);
        printNode(tree[nds]);
        if(l<=tree[nds].l&&tree[nds].r<=r)
        {
            printf("Tanken\n");
            return tree[nds].val;
        }
        if(r<tree[nds].l||tree[nds].r<l){
            printf("Rejected\n");
            return 0;
            }
        int mid=(l+r)/2,val=op(QQ(l,r,nds<<1),QQ(l,r,1|(nds<<1)));
        return val;
    }
    int op(int a,int b)
    {
        return (a+b);
    }
public:
    SegmentTree(int *arr,int n)
    {
        N=n;
        this->arr=arr;
        tree=new node[4*N];
        lazy=new node[4*N];
        for(int i=0; i<4*N; i++)tree[i]={-1,-1,0};
        build(0,N-1,1);
    }

    int build(int l,int r,int segNode)
    {
        int val;
        if(l==r)
        {
            tree[segNode]= {l,r,arr[l]};
            val= arr[l];
        }
        else
        {
            int mid=(l+r)/2;
            val=op(build(l,mid,segNode<<1),build(1+mid,r,1|(segNode<<1)));
            tree[segNode]= {l,r,val};

        }
        printf("node %d [%d %d] val=%d\n",segNode,l,r,val);
        return val;
    }
    int quarry(int l,int r)
    {
       return QQ(l,r,1);
    }

};


int main()
{
    int *tree;
    tree=new int[10];
    for(int i=0; i<10; i++)
    {
        tree[i]=i*i;
        cout<<tree[i]<<endl;
    }
    SegmentTree st(tree,10);
    cout<<st.quarry(0,5);

}
