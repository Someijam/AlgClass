#include<cstring>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define rep(ii,aa,bb) for(re int ii=aa;ii<=bb;ii++)
#define Rep(ii,aa,bb) for(re int ii=aa;ii>=bb;ii--)
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e4+5;
const ll inf=1ll<<60;
namespace IO_ReadWrite{
	#define re register
	#define gg (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	char buf[1<<21],*p1=buf,*p2=buf;
	template <typename T>
	inline void read(T &x){
		x=0;re T f=1;re char c=gg;
		while(c>57||c<48){if(c=='-') f=-1;c=gg;}
		while(c>=48&&c<=57){x=(x<<1)+(x<<3)+(c^48);c=gg;}
		x*=f;return;
	}
	inline void ReadChar(char &c){
		c=gg;
		while(!isalpha(c)) c=gg;
	}
	template <typename T>
	inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
	template <typename T>
	inline void writeln(T x){write(x);putchar('\n');}
}
using namespace IO_ReadWrite;
int ver[maxn],head[maxn],nxt[maxn],c[maxn],tot=1;
inline void add(int u,int v,int w){
	ver[++tot]=v;c[tot]=w;nxt[tot]=head[u];head[u]=tot;
	ver[++tot]=u;c[tot]=0;nxt[tot]=head[v];head[v]=tot;
}
int d[maxn],cur[maxn],n,m,s,t;
inline bool bfs(){// BFS 进行分层 
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s);d[s]=1;cur[s]=head[s];
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i];
			if(c[i]&&d[v]==-1){
				d[v]=d[u]+1;q.push(v);
				cur[v]=head[v];
				if(v==t) return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int u,int limit){// DFS 进行增广
	if(u==t||limit==0) return limit;
	int flow=0; // 多路增广
	for(int i=cur[u];i&&flow<limit;i=nxt[i]){
		cur[u]=i;// 当前弧优化
		int v=ver[i];
		if(d[v]==d[u]+1&&c[i]){
			int f=dfs(v,min(c[i],limit-flow));
			if(!f) d[v]=-1;// 满流剪枝
			flow+=f;c[i]-=f;c[i^1]+=f;
		}
	}
	return flow;
}
inline ll dinic(){ // 求最大流
	ll maxflow=0,flow=0;
	while(bfs()) while(flow=dfs(s,inf)) maxflow+=flow;
	return maxflow;
}
int main(){
    freopen("t0026in","r",stdin);
	read(n);read(m);read(s);read(t);
	for(int i=1,u,v,w;i<=m;i++){
		read(u);read(v);read(w);
		add(u,v,w);
	}
	writeln(dinic());
	return 0;
}