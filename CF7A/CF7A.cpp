//CF7A Kalevitch and Chess
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	char s[10];
	int a=0,b=10;
    for(int i=0;i<8;++i)
    {
        scanf("%s",s);
        int cnt=0;
        for(int j=0;j<8;++j)
        {
        	if(s[j]=='B')
        	{
        		++cnt;
			}
		}
		if(cnt==8)
		{
			++a;
		}
		b=min(b,cnt);
    }
    int ans=a+b;
    if(a==8)
    {
    	ans=8;
	}
	printf("%d\n",ans);
    return 0;
}
