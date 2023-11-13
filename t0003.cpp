#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cstdio>
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
#include <cassert>
using namespace std;

class t0003
{
private:
    long long n;
    long long mergeTimes=0;
    long long sum=0;
    priority_queue<long long,vector<long long>,greater<long long> > a;
public:
    t0003();
    void process();
    ~t0003();
};

t0003::t0003()
{
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        long long ta;
        scanf("%lld",&ta);
        a.push(ta);
    }
    
}

void t0003::process()
{
    
    while(1)
    {
        //找最小的两个人
        long long minWt=a.top();
        a.pop();
        long long semiMinWt=a.top();
        a.pop();
        //加起来
        mergeTimes++;
        a.push(minWt+semiMinWt);
        sum+=minWt+semiMinWt;
        if(mergeTimes==n-1)
        {
            break;
        }
    }
    cout<<sum<<endl;
    return;
}

t0003::~t0003()
{

}

int main(int argc, char const *argv[])
{
    t0003 demo;
    demo.process();
    return 0;
}