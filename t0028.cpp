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

struct node
{
    int start;
    int end;
    long long val;
    long long lazytag;
    node* parent;
    node* lch;
    node* rch;
    node(int s,int e,int v)
    {
        this->start=s;
        this->end=e;
        this->val=v;
        this->lazytag=0;
        this->parent=nullptr;
        this->lch=nullptr;
        this->rch=nullptr;
    }
};

class t0028
{
private:
    int n,m;
    vector<long long> arr;
    node* root;
public:
    t0028();
    void process();
    long long searchSum(node* p,int l,int r);
    void pushdown(node *p);
    void partialAdd(node* p,int l,int r,long long k);
    void buildTree(node* p);
    void deleteNode(node* p);
    ~t0028();
};

t0028::t0028()
{
    cin>>n>>m;
    arr.resize(n+1,0);
    for(int i=1;i<=n;i++)cin>>arr[i];
    root=new node(1,arr.size(),0);
    buildTree(root);    
}

void t0028::buildTree(node *p)//从已有节点p往下建树，返回start最终的val
{
    if(p->start==p->end)//p应为叶节点
    {
        p->val=arr[p->start];
        return;
    }
    int mid=(p->start+p->end)/2;
    p->lch=new node(p->start,mid,0);
    p->rch=new node(mid+1,p->end,0);
    buildTree(p->lch);
    buildTree(p->rch);
    p->val=p->lch->val+p->rch->val;
    return;
}

void t0028::deleteNode(node *p)
{
    if(p->lch==nullptr&&p->rch==nullptr)
    {
        delete p;
        p=nullptr;
        return;
    }
    deleteNode(p->lch);
    deleteNode(p->rch);
    delete p;
    p=nullptr;
    return;
}

void t0028::process()
{
    for(int i=0;i<m;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            long long k;
            cin>>x>>y>>k;
            partialAdd(root,x,y,k);
        }
        else if(op==2)
        {
            int x,y;
            cin>>x>>y;
            cout<<searchSum(root,x,y)<<endl;
        }
    }
}

long long t0028::searchSum(node *p, int l, int r)//区间查询：在p的区间内，搜索在[l,r]区间内所有人的和
{
    if(p->start>r||p->end<l)return 0;
    if(p->start>=l&&p->end<=r)return p->val;
    pushdown(p);
    return searchSum(p->lch,l,r)+searchSum(p->rch,l,r);
}

void t0028::pushdown(node *p)//要查到p下面了，赶紧把更改生效
{
    //p把懒标记发下去
    p->lch->lazytag+=p->lazytag;
    p->rch->lazytag+=p->lazytag;
    //子节点响应更新
    p->lch->val+=p->lazytag*(p->lch->end-p->lch->start+1);
    p->rch->val+=p->lazytag*(p->rch->end-p->rch->start+1);
    //p的标记发下去没有了
    p->lazytag=0;
}

void t0028::partialAdd(node *p, int l, int r, long long k)//区间修改：在p的区间内，更新在[l,r]中的人对应的值
{
    if(p->start>=l&&p->end<=r)//p被完全包含，p下面全都得改
    {
        p->lazytag+=k;
        p->val+=(p->end-p->start+1)*k;
        return;
    }
    if(p->start>r||p->end<l)return;
    //只要改p的一部分人
    int mid=(p->start+p->end)/2;
    pushdown(p);
    if(l<=mid)partialAdd(p->lch,l,r,k);
    if(mid<r)partialAdd(p->rch,l,r,k);
    p->val=p->lch->val+p->rch->val;
}

t0028::~t0028()
{
    deleteNode(root);

}

int main(int argc, char const *argv[])
{
    // freopen("t0028in","r",stdin);
    t0028 demo;
    demo.process();
    
    return 0;
}