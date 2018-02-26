//CF41A Translation
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    while(cin>>s){
        cin>>t;
        int i=0,c=1;
        for (std::string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit,++i){
            if(*rit==t[i])
                continue;
            else{
                c=0;
                break;
            }
        }
        if(c)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';

    }
    return 0;
}
