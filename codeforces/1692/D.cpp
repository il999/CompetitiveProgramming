//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    string s;
    int x;
    cin>>s>>x;
    int n=5;
    int time=0;
    time=(s[0]-'0')*60*10+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
   // cout<<time<<"\n";
    int seen[1440];
    for(int i=0;i<1440;i++)
        seen[i]=false;
    int ans=0;
    while(!seen[time])
    {
        //cout<<time<<"\n";
        seen[time]=true;
        time+=x;
        time=time%1440;
        int f=time/60;
        int s=time%60;
        if(f/10==s%10&&s/10==f%10)
        {
            ans++;
        }
       // cout<<"VS";
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
