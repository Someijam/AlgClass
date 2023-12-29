#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include <algorithm>
#include<string.h>
#include<stack>
#include<queue> 
#include<math.h>
#include<set>

#define ll long long
using namespace std;

ll nextt[1000010];
char s1[1000010],s2[1000010];
void getnextt(char *s)
{
	ll k=-1,j=0;
	nextt[0]=-1;
	while(j<strlen(s))
	{
		if(k==-1||s[j]==s[k])
		{
			j++;
			k++;
			if(s[j]!=s[k])nextt[j]=k;
			else nextt[j]=nextt[k];
		}
		else k=nextt[k];
	}
}

int kmp(char *s1,char *s2)
{
	getnextt(s2);
	ll i=0,j=0;
	ll ans=0;
	ll len1=strlen(s1),len2=strlen(s2);
	while(i<len1)
	{
		if(j==-1||s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else j=nextt[j];
		
		if(j==len2)ans++;
	}
	return ans;
}

int main()
{
	cin >> s1 >> s2;
	//cout << s1 << " " << s2;
	ll ans=kmp(s1,s2);
	cout << ans << endl ;

	return 0;
}




