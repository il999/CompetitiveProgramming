//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]&1)
        {
            odd++;
        }else
        {
            even++;
        }
    }
    cout<<min(odd,even)<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
