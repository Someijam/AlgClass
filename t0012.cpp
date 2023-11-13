#include<iostream>

using namespace std;

int partNum(int n, int k)
{
    if(n<k)return 0;
    if(k==1)return 1;
    if(k==n)return 1;
    return partNum(n-1,k-1)+partNum(n-k,k);
}

int main(int argc, char const *argv[])
{
    int n;
    int k;
    cin>>n>>k;
    cout<<partNum(n, k)<<endl;
    return 0;
}
