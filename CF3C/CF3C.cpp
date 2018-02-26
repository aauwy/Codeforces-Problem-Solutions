//CF3C Tic-tac-toe
#include "bits/stdc++.h"
using namespace std;

char ti[5][5];

int main()
{
    for(int i=1;i<=3;i++)
        scanf("%s",ti[i]+1);
    int nd=0,nx=0,no=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        {
            if(ti[i][j]=='.')
                nd++;
            else if(ti[i][j]=='X')
                nx++;
            else
                no++;
        }
    //cout<<nd<<" "<<nx<<" "<<no<<endl;
    if(!((no+1)==nx||no==nx)) 
    {
        printf("illegal\n");
        return 0;
    }
    int f=0;
    for(int i=1;i<=3;i++)  
    {
        if(ti[i][1]!='.'&&ti[i][1]==ti[i][2]&&ti[i][1]==ti[i][3])
        {
            if(!f)
                f=ti[i][1]=='X'?1:2;
            else if(f!=(ti[i][1]=='X'?1:2))
                f=3;
        }
        if(ti[1][i]!='.'&&ti[1][i]==ti[2][i]&&ti[1][i]==ti[3][i])
        {
            if(!f)
                f=ti[1][i]=='X'?1:2;
            else if(f!=(ti[1][i]=='X'?1:2))
                f=3;
        }
    }
    if((ti[1][1]!='.'&&ti[1][1]==ti[2][2]&&ti[1][1]==ti[3][3])||(ti[3][1]!='.'&&ti[3][1]==ti[2][2]&&ti[3][1]==ti[1][3])) //对角线
    {
        if(!f)
            f=ti[2][2]=='X'?1:2;
        else if(f!=(ti[2][2]=='X'?1:2))
            f=3;
    }
    if(f==1)
    {
        if(no+1==nx)
            printf("the first player won\n");
        else
            printf("illegal\n");
        return 0;
    }
    else if(f==2)
    {
        if(no==nx)
            printf("the second player won\n");
        else
            printf("illegal\n");
        return 0;
    }
    else if(f==3)
    {
        printf("illegal\n");
        return 0;
    }
    if(nd==0)
    {
        printf("draw\n");
        return 0;
    }
    if(nx==no)
        printf("first\n");
    else
        printf("second\n");
    return 0;
}
