//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    long long total=0;
    for(int i=0;i<n;i++)
    {
        total+=(s[i]-'a'+1);
    }
    if(n%2==0)
    {
        cout<<"Alice "<<total<<"\n";
    }else if(n==1)
    {
        cout<<"Bob "<<total<<"\n";
    }else
    {

        int m=s[0]-'a'+1;
        m=min(m,s[n-1]-'a'+1);
        //cout<<total<<"\n";
        cout<<"Alice "<<(total-2*m)<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
