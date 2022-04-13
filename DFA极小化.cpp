#include<iostream>
#include<vector>
#include<memory.h>
#include<cstring>
using namespace std;
#define Maxn 1000
#define Maxm 100
vector<pair<int,int>> list[Maxn][Maxn];//记录DFA 
int g[Maxn][Maxm];//记录DFA 
bool mark[Maxn][Maxn];//mark是可区分状态表 
bool end[Maxn];//end记录终止状态 
int n,m;
void del(int u,int v)
{
    int i,j,k;
    mark[u][v]=true;
    for(i=0;i<list[u][v].size();i++)
    {
        j=list[u][v][i].first;
        k=list[u][v][i].second;
        if(!mark[j][k])
            del(j,k);
    }
    list[u][v].clear();
}
int main()
{
    int i,j,k,u,v,w;
    bool flag;
    cout<<"请输入状态总数n"<<endl;
    cin>>n;
    cout<<"请输入输入字符集总数m"<<endl;
    cin>>m;
    memset(g,-1,sizeof(g));
    cout<<"请输入状态转换图（0<=状态<n,0<=输入字符<m）"<<endl;
    for(i=1;i<=m*n;i++)
    {
        cin>>u>>v>>w;
        g[u][w]=v;
    }//先输入起始状态，转移字符，在输入转移后的状态 
    cout<<"请输入接受状态个数（0<接受状态个数<=n）"<<endl;
    cin>>j;
    cout<<"请输入接受状态"<<endl;
    memset(end,false,sizeof(end));//将end内存块的值都设置为false 
    for(i=1;i<=j;i++)
    {
        cin>>k;
        end[k]=true;
    }//将终止状态对应的end位置都置为true 
    memset(mark,false,sizeof(mark));
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            list[i][j].clear();
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(end[i]!=end[j])
                mark[i][j]=true;
    for(j=0;j<n-1;j++)
        for(i=j+1;i<n;i++)
            if(end[i]==end[j])
            {
                flag=false;
                for(k=0;k<m;k++)
                {
                    if(g[i][k]!=-1 && g[j][k]!=-1)
                    {
                        u=g[i][k];
                        v=g[j][k];
                        if(mark[u][v] || mark[v][u])
                        {
                            flag=true;
                            if(!mark[i][j])
                                del(i,j);
                        }
                    }
                    if(flag)
                        break;
                }
                if(!flag)
                    for(k=0;k<m;k++)
                    {
                        if(g[i][k]!=-1 && g[j][k]!=-1)
                        {
                            u=g[i][k];
                            v=g[j][k];
                            if(u!=v && (min(u,v)!=j || max(u,v)!=i))
                                    list[max(u,v)][min(u,v)].push_back(make_pair(i,j));
                        }
                    }
            }
    for(i=1;i<n;i++)
    {
        cout<<i<<" ";
        for(j=0;j<i;j++)
            cout<<mark[i][j]<<' ';
        cout<<endl;
    }
    cout<<"  ";
    for(i=0;i<n-1;i++)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
