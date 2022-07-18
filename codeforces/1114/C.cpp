//coding template
/*
⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉
*/
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
ll orign=0;
vector<ll> factors;
long long prime_factors(ll n)
{
    long long maxprimefactor=0;
    ll original=n;
    bool done=0;
    map<ll,ll> m;
    ll ans1=LLONG_MAX;
    while(n>1)
    {
        //cout<<"D";
        done=0;
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                n/=i;
                done=1;
                if(m.find(i)==m.end())
                {
                    m[i]=1;
                    factors.push_back(i);
                }else
                {
                    m[i]++;
                }

                maxprimefactor=max(maxprimefactor,i);
               // cout<<"DFS";
                break;
            }
        }
        if(!done)
        {
             if(m.find(n)==m.end())
                {
                    m[n]=1;
                     factors.push_back(n);
                }else
                {
                    m[n]++;
                }
                 maxprimefactor=max(maxprimefactor,n);
            //cout<<"DGS";
            for(ll p=0;p<factors.size();p++ )
            {
               // cout<<"FDS";
                ll i=factors[p];

                    //cout<<"DFS";
                    ll finder=i;
                    ll original=finder;
                    ll amount=0;
                    ll cost=1;

                    while((orign/finder)>=original&&finder*original<=orign)
                    {
                        finder*=original;
                        cost++;

                    }
                    //cout<<finder<<"\n";
                    //cout<<"GDS";
                    ll ans=0;
                    //cout<<finder<<"\n";
                    while(finder>=original)
                    {
                        //cout<<"FSD";
                        ans+=((orign/finder)-amount)*cost;

                        amount+=(orign/finder)-amount;
                        cost--;
                        finder/=original;


                    }
                  //  cout<<original<<"\n";
                  //  cout<<"FDS";
                    ans1=min(ans1,ans/m[i]);

            }
            n=0;
        }
    }
   // cout<<"GFDS";
    //cout<<ans;
    return ans1;
}
void solve()
{
    long long n , b;
    cin>>n>>b;
    orign=n;



    cout<<prime_factors(b)<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
