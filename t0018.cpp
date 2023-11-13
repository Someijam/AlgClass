#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class t0018
{
private:
    int m;
    int n;
    vector<pair<int,int> > timeTable; //<time,backMoney>
    int ans;
public:
    t0018();
    void process();
    ~t0018();
};

t0018::t0018()
{
    cin>>m;
    ans=m;
    cin>>n;
    vector<int> timeLine(n);
    vector<int> backMoney(n);
    for(int i=0;i<n;i++)
    {
        cin>>timeLine[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>backMoney[i];
    }
    // timeTable.push_back({0,0});
    for(int i=0;i<n;i++)
    {
        timeTable.push_back({timeLine[i],backMoney[i]});
    }
    sort(timeTable.begin(),timeTable.end(),[](pair<int,int> a,pair<int,int> b)->bool
    {
        if(a.first<b.first)return true;
        else if(a.first==b.first)return a.second>b.second;
        else return false;
    });
    
}

void t0018::process()
{
    vector<pair<int,int> > selected;
    for(auto it:timeTable)
    {
        if(selected.size()+1<=it.first)//可按时
        {
            selected.push_back(it);
        }
        else//这个人不能按时
        {
            auto minInAlreadySaved=min_element(selected.begin(),selected.end(),[](pair<int,int> a,pair<int,int> b)->bool
            {
                return a.second<b.second;
            });
            if((*minInAlreadySaved).second<it.second)
            {
                ans-=(*minInAlreadySaved).second;
                selected.erase(minInAlreadySaved);
                selected.push_back(it);
            }
            else
            {
                ans-=it.second;
                continue;
            }
        }
    }
    return;
}

t0018::~t0018()
{
    cout<<ans<<endl;
}

int main(int argc, char const *argv[])
{
    t0018 demo;
    demo.process();
    return 0;
}