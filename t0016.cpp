#include<stdio.h>
using namespace std;

int N,M;
int minS=0x7fffffff;

int thinnestV(int baseLayer)//不包含baseLayer层往上搭的所需最小体积
{
    int ans=0;
    for(int i=baseLayer+1;i<=M;i++)
    {
        //r_i=M-i+1
        //h_i=M-i+1
        ans+=(M-i+1)*(M-i+1)*(M-i+1);
    }
    return ans;
}
int fattestV(int baseLayer,int r0,int h0)//不包含baseLayer层往上搭能达到的最大体积,r0,h0是baseLayer层的参数
{
    int ans=0;
    for(int i=baseLayer+1;i<=M;i++)
    {
        ans+=(r0-(i-baseLayer))*(r0-(i-baseLayer))*(h0-(i-baseLayer));
    }
    return ans;
}

void search(int currentLayer,int r0,int h0,int expandedArea,int usedV)
{
    if(currentLayer==M)//到头了
    {
        // cout<<"Used V="<<usedV<<endl;
        if(usedV==N)
        {
            if(expandedArea<minS)
            {
                minS=expandedArea;
            }
        }
        return;
    }
    int availableV=N-usedV;
    int minV=thinnestV(currentLayer);
    int maxV=fattestV(currentLayer,r0,h0);
    if(availableV<minV)//剩下的体积不够用了
    {
        return;
    }
    if(availableV>maxV)//往上怎么搭都用不完
    {
        return;
    }
    //值得一试
    for(int ri=M-currentLayer;ri<=r0-1;ri++)
    {
        for(int hi=M-currentLayer;hi<=h0-1;hi++)
        {
            int tExpandedArea=expandedArea+2*ri*hi;
            if(tExpandedArea>=minS)
            {
                continue;//表面积已经超当前最优情况了
            }
            int tUsedV=usedV+ri*ri*hi;
            if(tUsedV>N)
            {
                break;//后面的情况不能再枚举了，体积不够用了
            }
            search(currentLayer+1,ri,hi,tExpandedArea,tUsedV);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    // cin>>N;
    // cin>>M;
    scanf("%d",&N);
    scanf("%d",&M);
    for(int r1=M;r1*r1<=N;r1++)
    {
        for(int h1=N/(r1*r1);h1>=M;h1--)
        {
            search(1,r1,h1,2*r1*h1+r1*r1,r1*r1*h1);
        }
    }
    if(minS==0x7fffffff)minS=0;
    // cout<<minS<<endl;
    printf("%d\n",minS);
    return 0;
}
