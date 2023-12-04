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
class t0009
{
private:
    int n;
    int m;
    vector<int> v;
    vector<int> w;

public:
    t0009();
    void process();
    ~t0009();
};

t0009::t0009()
{
    cin>>n>>m;
    v.resize(m+1);
    w.resize(m+1);
    for(int i=1;i<=m;i++)cin>>v[i]>>w[i];
}

void t0009::process()
{
    vector<int> ans(n+1,0);
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j-v[i]>=0;j--)
        {
            ans[j]=max(ans[j],ans[j-v[i]]+v[i]*w[i]);
        }
    }
    cout<<ans[n]<<endl;
}

t0009::~t0009()
{
    
}

int main(int argc, char const *argv[])
{
    t0009 demo;
    demo.process();
    
    return 0;
}