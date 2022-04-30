//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int t[27]={0};
    for(int i=0;i<27;i++)
    {
        t[i]=false;
    }
    int already=1;
    bool poop=false;
    int p=0;
    for(int i=0;i<n;i++)
    {


        t[s[i]-'a']++;
        if(t[s[i]-'a']==2)
        {
            while( true)
            {
                for(int j=0;j<i;j++)
                {
                    if(i+j==n)
                    {
                        cout<<"YES\n";
                        return;
                    }
                    if(s[i+j]!=s[j])
                    {
                        cout<<"NO"<<"\n";
                        return;
                    }
                }
                i+=i;
            }

        }



    }

    cout<<"YES\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
