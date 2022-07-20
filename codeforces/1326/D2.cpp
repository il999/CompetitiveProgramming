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
const int MOD=1e9+7;
const int MOD2=1e9+3;
int string_hashing(string s)
{

    int n=s.size();
    //hash
    ll h[n+1];
    //hash backwards;
    ll h2[n+1];
    ll hmod2[n+1];
    ll h2mod2[n+1];
    h2[n]=0;
    h[0]=0;
    h2mod2[n]=0;
    hmod2[0]=0;
    ll p=31;
    ll p2mod2=37;
    ll temp=1;
    ll p1[n];
    ll p1mod2[n];
    ll tempmod2=1;
    for(int i=0;i<n;i++)
    {
        p1[i]=temp%MOD;
        p1mod2[i]=tempmod2%MOD2;
        h[i+1]=(h[i]+temp*(s[i]-'a'+1)) %MOD;
        hmod2[i+1]=(hmod2[i]+tempmod2*(s[i]-'a'+1)) %MOD2;
        temp=(temp*p)%MOD;
        tempmod2=(tempmod2*p2mod2)%MOD2;


    }
    temp=1;
    tempmod2=1;
    for(int i=n-1;i>=0;i--)
    {

        h2mod2[i]=(h2mod2[i+1]+tempmod2*(s[i]-'a'+1))%MOD2;
        h2[i]=(h2[i+1]+temp*(s[i]-'a'+1))%MOD;
        temp=(temp*p)%MOD;
        tempmod2=(tempmod2*p2mod2)%MOD2;
    }
    ll hashval1=0;
    ll hashval2=0;
    ll temphash;
    ll temphash2;
    ll ans=0;
    for(int i=0;i<n/2;i++)
    {
       // cout<<h[i+2]<<"\n";
        //cout<<p1[10]<<"\n";
        hashval1=h[i+1];
        temphash=hmod2[i+1];
        if((i+1)*2<n)
        {
            hashval2=(h2[(i+2)]-h2[(i+1)*2+1])%MOD;
            temphash2=(h2mod2[(i+2)]-h2mod2[(i+1)*2+1])%MOD2;
            if(hashval2<0)
            {
                hashval2=MOD+hashval2;
            }
             if(temphash2<0)
            {
                temphash2=MOD2+temphash2;
            }
            if((n-(i+2)<i+1))
            {
                hashval2=(hashval2*(p1[i+1-(n-(i+2))]))%MOD;
            }else
            {
                hashval1=(hashval1*(p1[n-(i+2)-(i+1)]))%MOD;
            }

             if((n-(i+2)<i+1))
            {
                temphash2=(temphash2*(p1mod2[i+1-(n-(i+2))]))%MOD2;
            }else
            {
                temphash=(temphash*(p1mod2[n-(i+2)-(i+1)]))%MOD2;
            }
           // cout<<hashval1<<" "<<hashval2<<"\n";

            if(hashval1==hashval2&&temphash2==temphash)
            {
                ans=(i+1)*2;
             //  cout<<"DFS";
            }

        }
        hashval1=h[i+1];
        temphash=hmod2[i+1];
        if((i+1)*2<=n)
        {
             temphash2=(h2mod2[(i+1)]-h2mod2[(i+1)*2])%MOD2;
            hashval2=(h2[(i+1)]-h2[(i+1)*2])%MOD;
            if(hashval2<0)
            {
                hashval2=MOD+hashval2;
            }
            if(temphash2<0)
            {
                temphash2=MOD2+temphash2;
            }
            if((n-(i+1))<i+1)
            {
                hashval2=(hashval2*(p1[(i+1)-(n-(i+1))]))%MOD;
            }else
            {
                hashval1=(hashval1*(p1[(n-(i+1))-(i+1)]))%MOD;
            }
             if((n-(i+1)<i+1))
            {
                temphash2=(temphash2*(p1mod2[i+1-(n-(i+1))]))%MOD2;
            }else
            {
                temphash=(temphash*(p1mod2[n-(i+1)-(i+1)]))%MOD2;
            }
           // cout<<(hashval1*p1[10])%MOD<<" "<<hashval2<<"\n";
            if(hashval1==hashval2)
            {
                //cout<<"DS";
               // cout<<temphash<<" "<<temphash2<<"\n";
            }
            if(hashval1==hashval2&&temphash2==temphash)
            {
                ans=max(1ll*(i+1)*2-1,ans);
              //  cout<<"DS";
            }

        }

    }
    return ans;


}
void solve()
{
    int n;
    string s;
    cin>>s;
    n=s.size();

    string temp="";


    string pre_backwards[n];
    int in=0;

    while(s[in]==s[n-in-1]&&in<n-in-1)
    {
        in++;
    }
    string s2="";

    for(int i=in;i<n-in;i++)
    {
        s2+=s[i];
    }
     string middle="";
    if(s2.size()!=0)
    {
        int  prefix= string_hashing(s2);
        string backwardss2="";
        for(int i=s2.size()-1;i>=0;i--)
        {
            backwardss2+=s2[i];
        }
        int  suffix= string_hashing(backwardss2);
         if(prefix>suffix)
            {
                for(int i=0;i<=prefix;i++)
                {
                    middle+=s2[i];
                }
        }else
            {
                for(int i=0;i<=suffix;i++)
                {
                    middle+=backwardss2[i];
                }
            }
    }
   // cout<<s2<<"\n";



    for(int i=0;i<in;i++)
    {
        cout<<s[i];
    }
    cout<<middle;
    for(int i=in-1;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<"\n";




}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
