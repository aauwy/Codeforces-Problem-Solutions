//CF2A Winner
#include "bits/stdc++.h" 
using namespace std;  
const int maxn=1005;  
string x[maxn];  
int y[maxn];  
int main()  
{  
    int n;  
    //freopen("shuju.txt","r",stdin);  
    while(cin >> n)  
    {  
        map<string,int> map,cnt;  
        for(int i=0;i<n;++i)  
        {  
            cin >> x[i] >> y[i];  
            map[x[i]]+=y[i];  
        }  
        int kase=0;  
        for(int i=0;i<n;++i)  
        {  
            kase=max(kase,map[x[i]]);  
        }  
        for(int i=0;i<n;++i)  
        {  
            cnt[x[i]]+=y[i];  
            if(map[x[i]]==kase&&cnt[x[i]]>=kase)  
            {  
                cout <<x[i]<<endl;  
                break;  
            }  
        }  
    }  
    return 0;  
}  
