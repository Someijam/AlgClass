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
int n;
vector<int> arr;
long long extra_info=0;

void m_merge(vector<int> &a,int l,int mid,int r)
{
    // [l,...,mid],[mid+1,...,r]
    // newArr[l,...,...,r]
    vector<int> temp;
    int p1=l;
    int p2=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(p1>mid)
        {
            temp.push_back(a[p2]);
            p2++;
        }
        else if(p2>r)
        {
            temp.push_back(a[p1]);
            p1++;
        }
        else if(a[p1]<a[p2])
        {
            temp.push_back(a[p1]);
            p1++;
        }
        else 
        {
            temp.push_back(a[p2]);
            p2++;
        }
    }
    for(int i=l;i<=r;i++)
    {
        a[i]=temp[i-l];
    }
    return;
}

void m_sort(vector<int> &a,int l,int r)
{
    int mid=(l+r)/2;
    // if(l!=r)extra_info+=mid;
    if(l>=r)return;
    m_sort(a,l,mid);
    m_sort(a,mid+1,r);
    m_merge(a,l,mid,r);
    return;
}

int main(int argc, char const *argv[])
{
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    m_sort(arr,0,arr.size()-1);
    for(auto it:arr)cout<<it<<" ";
    cout<<extra_info<<endl;
    return 0;
}