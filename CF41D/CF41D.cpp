//简单dp
//http://www.bubuko.com/infodetail-261478.html
//CF41D Pawn
#include <cstdio>
#include <algorithm>
#include<iostream>
#include<string.h>
#include <math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;
#define N 105
#define inf 10000000
#define ll int
int n,m,k;
int dp[N][N][12];
int px[N][N][12], py[N][N][12], sum[N][N][12];
int mp[N][N];
vector<pair<int,int> >ans;
int main(){
    int i, j, z;
    while(~scanf("%d %d %d",&n,&m,&k)){
            k++;
        memset(sum, -1, sizeof sum);
        memset(px, -1, sizeof px);
        memset(py, -1, sizeof py);
        memset(dp, 0, sizeof dp);
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
            scanf("%1d",&mp[i][j]);
        for(i = 1; i <= m; i++)
        dp[n][i][mp[n][i] % k] = 1, sum[n][i][mp[n][i] % k] = mp[n][i];

        for(i = n-1; i ; i--){
            for(j = 1; j <= m; j++) {
                int x = i+1, y = j-1;
                if(y>=1)
                {
                    for(z = 0; z <= k; z++)
                    if(dp[x][y][z] && sum[i][j][(z+mp[i][j])%k] < sum[x][y][z]+mp[i][j])
                    {
                        dp[i][j][(z+mp[i][j])%k] = 1;
                        px[i][j][(z+mp[i][j])%k] = x;
                        py[i][j][(z+mp[i][j])%k] = y;
                        sum[i][j][(z+mp[i][j])%k] = sum[x][y][z]+mp[i][j];
                    }
                }
                y = j+1;
                if(y<=m)
                {
                    for(z = 0; z <= k; z++)
                    if(dp[x][y][z] && sum[i][j][(z+mp[i][j])%k] < sum[x][y][z]+mp[i][j])
                    {
                        dp[i][j][(z+mp[i][j])%k] = 1;
                        px[i][j][(z+mp[i][j])%k] = x;
                        py[i][j][(z+mp[i][j])%k] = y;
                        sum[i][j][(z+mp[i][j])%k] = sum[x][y][z]+mp[i][j];
                    }
                }
            }
        }
        int posx = 1, posy = -1, mod = 0, anssum = -1;
        for(i = 1; i <= m; i++)
            if(dp[1][i][0] && anssum<sum[1][i][0])
                posy = i, anssum = sum[1][i][0];
        if(posy==-1){puts("-1");continue;}
        ans.clear();
        while(posy!=-1) {
            ans.push_back(pair<int,int>(posx, posy));
            int tx = px[posx][posy][mod];
            int ty = py[posx][posy][mod];
            mod = ((mod-mp[posx][posy])%k+k)%k;
            posx = tx, posy = ty;
        }
        cout<<anssum<<endl;

        int x = ans[ans.size()-1].first, y = ans[ans.size()-1].second;
        cout<<y<<endl;
        for(i = ans.size()-2; i >= 0; i--){
            int nowx = ans[i].first, nowy = ans[i].second;
            if(nowy>y)
                printf("R");
            else printf("L");
            x = nowx, y = nowy;
        }
        puts("");
    }
    return 0;
}
