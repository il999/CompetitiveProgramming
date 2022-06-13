//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int m,k;
    cin>>m>>k;
    string a;
    string b;
    cin>>a;
    cin>>b;
    vector<char> ca;
    vector<char> cb;
    int ia=0;
    int ib=0;
    vector<int> tempa;
    vector<int> tempb;
    vector<char> ans;
    for(int i=0;i<n;i++)
    {
        ca.push_back(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        cb.push_back(b[i]);
    }
    sort(ca.begin(),ca.end());
    sort(cb.begin(),cb.end());

    bool anow=false;
    int count1=0;
    bool done=false;
    while(ia!=n&&ib!=m)
    {

        if(count1==k)
        {
           // cout<<count1<<"\n";
            if(anow)
            {
                ans.push_back(cb[ib]);
                ib++;
                anow=false;

            }else
            {
                ans.push_back(ca[ia]);
                ia++;
                anow=true;
            }
            count1=1;
        }
        else if(ca[ia]<cb[ib])
        {
            ans.push_back(ca[ia]);
            ia++;

            if(!anow||!done)
            {
                count1=1;
                anow=true;
            }else
            {
                count1++;
            }
        }else
        {

            ans.push_back(cb[ib]);
            ib++;
            if(anow||!done)
            {
                count1=1;
                anow=false;
            }else
            {
                count1++;
            }
        }
        done=true;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    cout<<"\n";
}
int main()
{
 //   ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
