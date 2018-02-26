//CF88B Keyboard
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define del(a,b) memset(a,b,sizeof(a))
struct node
{
    int x,y;
}nn[900];
int aa[130];
bool flag;
int n,m,x,q,ans,snum;
char kb[33][33];
string s;
void init()
{
    del(aa,-1);
    x*=x;
    snum=0;
    ans=0;
    flag=true;
}
void fun()
{
    if(snum==0)
        return;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(kb[i][j]!='S')
            {
                int minn=10000,dd;
                for(int k=0;k<snum;k++)
                {
                    dd=(i-nn[k].x)*(i-nn[k].x)+(j-nn[k].y)*(j-nn[k].y);
                    if(dd<minn)
                        minn=dd;
                }
                if(minn<=x)
                    aa[kb[i][j]-32]=0;
                else if(aa[kb[i][j]-32]==-1)
                    aa[kb[i][j]-32]=1;
            }
        }
    }
}
void test()
{
    for(int i='a';i<='z';i++)
        printf("%c %d\n",i,aa[i]);
    printf("\n");
    for(int i='A';i<='Z';i++)
        printf("%c %d\n",i,aa[i]);
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&x))
    {
        init();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>kb[i][j];
                if(kb[i][j]!='S')
                    aa[kb[i][j]]=0;
                else
                {
                    nn[snum].x=i;
                    nn[snum].y=j;
                    snum++;
                }
            }
        }
        fun();
        //test();
        scanf("%d",&q);
        cin>>s;
        for(int i=0;i<q;i++)
        {
            if(aa[s[i]]==-1)
            {
                flag=false;
                break;
            }
            ans+=aa[s[i]];
        }
        if(!flag)
            printf("-1\n");
        else
            printf("%d\n",ans);

    }
}
