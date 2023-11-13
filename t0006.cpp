#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    queue<pair<int,int> > robotRoute;// pos,depth
    vector<bool> visited(n+1);
    robotRoute.push({1,0});
    visited[1]=true;
    while (!robotRoute.empty())
    {
        int headOut=robotRoute.front().first;
        if(headOut-1<=n&&headOut-1>=1&&visited[headOut-1]==false)
        {
            if(headOut-1==n)
            {
                cout<<robotRoute.front().second+1<<endl;
                return 0;
            }
            robotRoute.push({headOut-1,robotRoute.front().second+1});
            visited[headOut-1]=true;
        }
        if(headOut+1<=n&&headOut+1>=1&&visited[headOut+1]==false)
        {
            if(headOut+1==n)
            {
                cout<<robotRoute.front().second+1<<endl;
                return 0;
            }
            robotRoute.push({headOut+1,robotRoute.front().second+1});
            visited[headOut+1]=true;
        }
        if(headOut*2<=n&&headOut*2>=1&&visited[headOut*2]==false)
        {
            if(headOut*2==n)
            {
                cout<<robotRoute.front().second+1<<endl;
                return 0;
            }
            robotRoute.push({headOut*2,robotRoute.front().second+1});
            visited[headOut*2]=true;
        }
        // cout<<"Tail="<<robotRoute.front().first<<", "<<robotRoute.front().second<<endl;
        robotRoute.pop();
    }
    
    return 0;
}
