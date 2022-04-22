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
    int p=0;
    bool three=false;
    int two=0;

    bool great=false;
    for(int i=1;i<n;i++)
    {
        if(l[i]-l[i-1]>1)
        {
           // cout<<"DTGSG";
            if(l[i]-l[i-1]>3)
            {
                cout<<"NO"<<"\n";
                return;
            }
            if(great)
            {
                cout<<"NO"<<"\n";
                return;
            }
            if(l[i]-l[i-1]!=2)
            {
                great=true;
            }else
            {
                two++;

            }
            if(two>0&&great)
            {
                cout<<"NO \n";
                return;
            }
            if(two>2)
            {
                cout<<"NO \n";
                return;
            }




        }

    }
    cout<<"YES"<<"\n";

}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
