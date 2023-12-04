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
class t0008
{
private:
    int r;
    vector<vector<int> > tower;
public:
    t0008();
    void process();
    ~t0008();
};

t0008::t0008()
{
    cin>>r;
    tower.resize(r);
    for(int i=1;i<=r;i++)tower[i-1].resize(i);
    for(int i=1;i<=r;i++)
    {
        for(int j=0;j<i;j++)
        {
            cin>>tower[i-1][j];
        }
    }
}

void t0008::process()
{
    vector<vector<int> > maxSumFrom(r);
    for(int i=0;i<maxSumFrom.size();i++)maxSumFrom[i].resize(i+1);
    maxSumFrom[r-1]=tower[r-1];
    for(int i=r-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)maxSumFrom[i][j]=max(tower[i][j]+maxSumFrom[i+1][j],tower[i][j]+maxSumFrom[i+1][j+1]);
    }
    cout<<maxSumFrom[0][0]<<endl;
}

t0008::~t0008()
{
    
}

int main(int argc, char const *argv[])
{
    t0008 demo;
    demo.process();
    
    return 0;
}