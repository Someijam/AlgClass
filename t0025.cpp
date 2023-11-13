#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

class t0025
{
private:
    int n;
    int m;
    vector<pair<int,int> > route;
    
public:
    t0025();
    void process();
    ~t0025();
};

t0025::t0025()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int tx,ty;
        cin>>tx>>ty;
        if(tx==ty)continue;
        route.push_back({tx,ty});
    }
    
}

void t0025::process()
{
    sort(route.begin(),route.end());
    for(int i=0;i<route.size()-1;i++)
    {
        // assert((route[i].first==route[i+1].first)&&(route[i].second==route[i+1].second));
    }
}

t0025::~t0025()
{
}


int main(int argc, char const *argv[])
{
    t0025 demo;
    demo.process();
    return 0;
}
