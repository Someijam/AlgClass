#include <cstdio>
#include <iostream>
using namespace std;
int a1, a2, a3, f[200001], n, m;
long long ans=0;
long long mod=998244353;
int getf(int o)
{ // 不停找爹，直到找到祖宗为止
    if (f[o] == o)
        return o;
    else
        return f[o] = getf(f[o]); // 这里是路径压缩，把递归过程中遇到的
                                  // 结点的祖宗结点也直接修改了。
}
void merge(int v, int u)
{                 // 合并子集
    int t1, t2;   // t1,t2分别为v和u的祖宗
    t1 = getf(v); // 获取祖宗结点值
    t2 = getf(u);
    if (t1 != t2)
        f[t2] = t1; // 靠左。即将右边的集合，作为左边的子集
    return;
}
void find(int v, int u)
{
    int t1, t2; // 同上
    t1 = getf(v);
    t2 = getf(u);
    if (t1 == t2)
    {
        ans<<=1;
        ans++;
        ans%=mod;
        // printf("Y ");
        // cout<<ans<<endl;
        
    }
    else
    {
        ans<<=1;
        ans%=mod;
        // printf("N ");
        // cout<<ans<<endl;
    }
        
}
int main()
{
    // freopen("t0002in","r",stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i; // 初始化集合
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &a1, &a2, &a3);
        if (a1 == 0)
            merge(a2, a3);
        else
            find(a2, a3);
    }
    cout<<ans<<endl;
}