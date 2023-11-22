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
class t0019
{
private:
    int n;
    vector<pair<long long,long long> > positions;
    int lb=-10000000;
    int rb=10000000;
public:
    t0019();
    void process();
    long long rangeFind(int indexl,int indexr);//拆分
    ~t0019();
};

t0019::t0019()
{
    cin>>n;
    positions.resize(n);
    for(int i=0;i<n;i++)cin>>positions[i].first>>positions[i].second;
}

void t0019::process()
{
    sort(positions.begin(),positions.end(),[](pair<long long,long long> a,pair<long long,long long> b)->bool
    {
        return a.first<b.first;
    });
    cout<<rangeFind(0,positions.size())<<endl;

}

long long t0019::rangeFind(int indexl, int indexr)
{
    long long leftPartMin=LLONG_MAX;
    long long rightPartMin=LLONG_MAX;
    long long boarderMin=LLONG_MAX;
    if(indexl==indexr)return LLONG_MAX;
    if(indexl+1==indexr)return (positions[indexl].first-positions[indexr].first)*(positions[indexl].first-positions[indexr].first)+(positions[indexl].second-positions[indexr].second)*(positions[indexl].second-positions[indexr].second);
    if(indexl<indexr)//正常情况
    {
        int mid=(indexl+indexr)/2;
        leftPartMin=rangeFind(indexl,mid);//左边最近的
        rightPartMin=rangeFind(mid+1,indexr);//右边最近的
        long long singlePartMin=min(leftPartMin,rightPartMin);
        //找到跨mid的最近两个点，定mid为参考点
        vector<int> nearMidPoints;
        for(int i=indexl;i<=indexr;i++)
        {
            if(abs(positions[mid].first-positions[i].first)<=singlePartMin)
            {
                nearMidPoints.push_back(i);
            }
        }
        sort(nearMidPoints.begin(),nearMidPoints.end(),[&](int a,int b)->bool{return positions[a].second<positions[b].second;});
        //计算刚刚收集好的点之间距离
        for(int i=0;i<nearMidPoints.size()-1;i++)
        {
            for(int j=i+1;j<nearMidPoints.size()&&abs(positions[nearMidPoints[i]].second-positions[nearMidPoints[j]].second)<singlePartMin;j++)
            {
                boarderMin=min(boarderMin,(positions[nearMidPoints[i]].first-positions[nearMidPoints[j]].first)*(positions[nearMidPoints[i]].first-positions[nearMidPoints[j]].first)+(positions[nearMidPoints[i]].second-positions[nearMidPoints[j]].second)*(positions[nearMidPoints[i]].second-positions[nearMidPoints[j]].second));
            }
        }
    }
    return min(boarderMin,min(leftPartMin,rightPartMin));
}

t0019::~t0019()
{
    
}

int main(int argc, char const *argv[])
{
    t0019 demo;
    demo.process();
    return 0;
}

