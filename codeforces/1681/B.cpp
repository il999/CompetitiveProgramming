#include <iostream>

using namespace std;
void solve()
{
   int n;
   cin>>n;
   int a[n];
   int m;
   long long tot=0;
   for(int i=0;i<n;i++)
        cin>>a[i];
   cin>>m;
   long long thing=0;
   for(int i=0;i<m;i++)
   {
       cin>>thing;
       tot+=thing;
   }
   tot=tot%n;
   cout<<a[tot]<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
