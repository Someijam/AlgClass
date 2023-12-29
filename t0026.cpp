#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class t0026
{
private:
    vector<vector<int> > graph;
    int n,m,s,t;
public:
    t0026();
    bool routeExist(vector<vector<int> >&g,int i,int j);//g中，存在i->j路径
    void process();
    ~t0026();
};

t0026::t0026()
{
    cin>>n>>m>>s>>t;
    graph.resize(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        graph[u][v]=c;
    }
}

bool t0026::routeExist(vector<vector<int>> &g, int i, int j)
{

    return false;
}

void t0026::process()
{
    vector<vector<int> > Gf(this->graph);
    vector<vector<int> > f(n+1,vector<int>(n+1,0));
    vector<vector<int> > Gl(n+1,vector<int>(n+1,0));

    while (true)
    {
        //由Gf初始化Gl:(V=所有顶点,E=(u,v),l(u)+1=l(v)),BFS:Gf ?
        bool tInGL=false;
        queue<pair<int,int> > Gf_trav; // <point,layer>
        vector<int> visitedGf(n+1,0);//visited[p]=l(p)
        Gf_trav.push({s,1});
        visitedGf[s]=1;
        while (Gf_trav.empty()==false)
        {
            auto p=Gf_trav.front();
            Gf_trav.pop();
            //遍历到p
            // visitedGf[p.first]=p.second;
            for(int i=1;i<=n;i++)
            {
                if(Gf[p.first][i]>0&&(visitedGf[i]==0||visitedGf[i]-p.second==1))//p->i有路径 && (i没有被访问过 || l(i)-l(p)==1)
                {
                    if(i==t)tInGL=true;
                    Gl[p.first][i]=Gf[p.first][i];
                    Gf_trav.push({i,p.second+1});
                    visitedGf[i]=p.second+1;
                }
            }
        }
        if(tInGL==false)break;
        //Gl中找阻塞流,DFS:Gl,加入到f中
        stack<pair<int,int> > Gl_route;
        stack<pair<int,int> > Gl_trav;
        vector<int> visitedGl(n+1,0);
        Gl_trav.push({-1,s});
        while (Gl_trav.empty()==false)
        {
            auto p=Gl_trav.top();
            Gl_route.push(p);
            Gl_trav.pop();
            //遍历到p
            if(p.second==t)break;
            visitedGl[p.second]=1;
            for(int i=1;i<=n;i++)
            {
                if(Gl[p.second][i]>0&&visitedGl[i]!=1)
                {
                    Gl_trav.push({p.second,i});
                }
            }
        }
        vector<int> validPath;//{t,...,s}
        validPath.push_back(t);
        while (Gl_route.empty()==false)
        {
            auto p=Gl_route.top();
            if(p.first==-1)break;
            Gl_route.pop();
            if(p.second==*validPath.rbegin())validPath.push_back(p.first);
        }
        vector<pair<int,int> > jamEdge;
        int minContain=INT_MAX;
        for(int i=0;i+1<validPath.size();i++)
        {
            jamEdge.push_back({validPath[i+1],validPath[i]});
            minContain=min(minContain,Gl[validPath[i+1]][validPath[i]]);
        }
        //更新f
        for(auto it:jamEdge)
        {
            f[it.first][it.second]+=minContain;
        }
        //由f更新Gf,BFS:Gf  ?
        Gf=this->graph;
        queue<int> Gf_trav2;
        vector<int> visitedGf2(n+1,0);
        Gf_trav2.push(s);
        while (Gf_trav2.empty()==false)
        {
            int p=Gf_trav2.front();
            Gf_trav2.pop();
            //遍历到p
            visitedGf2[p]=1;
            for(int i=1;i<=n;i++)
            {
                if(Gf[p][i]>0&&f[p][i]>0&&visitedGf2[i]!=1)
                {
                    //(p->i)
                    Gf[p][i]-=f[p][i];
                    Gf[i][p]+=f[p][i];
                    Gf_trav2.push(i);
                }
            }
        }
        cout<<"Gl:"<<endl;
        for(auto it:Gl)
        {
            for(auto iit:it)cout<<iit<<", ";
            cout<<endl;
        }
        cout<<"f:"<<endl;
        for(auto it:f)
        {
            for(auto iit:it)cout<<iit<<", ";
            cout<<endl;
        }
        cout<<"Gf:"<<endl;
        for(auto it:Gf)
        {
            for(auto iit:it)cout<<iit<<", ";
            cout<<endl;
        }
        cout<<endl;

    }
    int maxFlow=0;
    for(int i=1;i<=n;i++)
    {
        maxFlow+=f[i][t];
    }
    cout<<maxFlow<<endl;
}

t0026::~t0026()
{
    
}

int main(int argc, char const *argv[])
{
    freopen("t0026in","r",stdin);
    freopen("t0026out","w",stdout);
    t0026 demo;
    demo.process();
    
    return 0;
}