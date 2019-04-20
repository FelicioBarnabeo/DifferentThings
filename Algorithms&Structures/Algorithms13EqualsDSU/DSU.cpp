#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;
public:
    DSU() = default;
    DSU(int size)
    {
        parent.resize(size);
        rank.resize(size);
    }
    void makeSet(int i)
    {
        parent[i] = i;
        rank[i]=0;
    }

    //find со сжатием путей , переподвешивает каждую вершину в ветке с искомым элементом к корню дерева
    int find(int i)
    {
        if(i!=parent[i])
            parent[i]=find(parent[i]);
        return parent[i];
    }

    void unite(int i,int j)
    {
        //cout<<"unite"<<endl;
        int iid = find(i);
        int jid = find(j);
        if(iid==jid) return;
        if(rank[iid] > rank[jid])
        {
            parent[jid]=iid;
        }
        else
        {
            parent[iid]=jid;
            if(rank[iid] == rank[jid])
                rank[jid]+=1;
        }
    }
};

int main()
{
    int n, e, d, k, j;
    cin >> n >> e >> d;
    DSU myset(n+1);
    for(int i=1; i<=n; i++)
    {
        myset.makeSet(i);
    }

    for(int i=0; i<e; i++)
    {
        cin >> k >> j;
        myset.unite(k,j);
    }
    for(int i=0; i<d; i++)
    {
        cin >> k >> j;
        int kid=myset.find(k);
        int jid=myset.find(j);
        if(kid==jid)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    return 0;
}
