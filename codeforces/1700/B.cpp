//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;

void solve()
{
    int n1;
    string n;
    cin>>n1;
    cin>>n;
    string ans="";
    if(n[0]=='9')
    {
        int carry=0;
        int p=0;
        int deduct=11;
        for(int i=n1-1;i>=0;i--)
        {
            p=(deduct-(n[i]-'0'));
            p+=carry;
            carry=0;
            if(p>=10)
            {
                p-=10;
                carry++;
            }
            ans+=to_string(p);
            deduct=10;
        }
        if(carry)
        {
            ans+=to_string(carry);
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<ans[i];
        }
        cout<<"\n";
    }else
    {
        for(int i=0;i<n1;i++)
        {
            cout<<'9'-n[i];
        }
        cout<<"\n";
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
