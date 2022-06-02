//coding template
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void solve()
{
    long long n1,m1,q;
    cin>>n1>>m1>>q;
    long long n,m;
    n=n1;
    m=m1;


        long long gr=gcd(n,m);

        for(int i=0;i<q;i++)
        {
            long long a,b,c,d;
            cin>>a>>b>>c>>d;
            if(a==1)
            {
                if(c==1)
                {
                    if((b-1)/(n/gr)!=(d-1)/(n/gr))
                    {
                        cout<<"NO\n";
                    }else
                    {
                        cout<<"YES\n";
                    }
                }else
                {
                    if((b-1)/(n/gr)!=(d-1)/(m/gr))
                    {
                        cout<<"NO\n";
                    }else
                    {
                        cout<<"YES\n";
                    }
                }
            }else
            {
                if(c==1)
                {
                    if((b-1)/(m/gr)!=(d-1)/(n/gr))
                    {
                        cout<<"NO\n";
                    }else
                    {
                        cout<<"YES\n";
                    }
                }else
                {
                    if((b-1)/(m/gr)!=(d-1)/(m/gr))
                    {
                        cout<<"NO\n";
                    }else
                    {
                        cout<<"YES\n";
                    }
                }
            }

        }





}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
