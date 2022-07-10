//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int l2[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        l2[i]=l[i];
    }
    sort(l2,l2+n);
    bool reversed=0;
    bool thing=0;
    int st=-1;
    int fi=-1;;
    for(int i=0;i<n-1;i++)
    {

        if(l[i]>l[i+1])
        {
            if(thing)
            {
                cout<<"no\n";
                return;
            }
            if(!reversed)
                st=i;
            reversed=true;
        }else if(l[i]<l[i+1]&&reversed)
        {

            if(!thing)
            {
                fi=i;
            }
            if(!thing && l2[i]!=l[st])
            {
                cout<<"no\n";
                return;
            }
            thing=true;

        }
    }
    if(fi==-1)
    {

        if(st==-1)
        {
            fi=0;
            st=0;
        }else
        {
            fi=n-1;

        }
    }
    if(l2[st]!=l[fi])
    {
        cout<<"no\n";
        return;
    }
    cout<<"yes\n";
    cout<<st+1<<" "<<fi+1<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
