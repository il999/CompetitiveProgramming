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
void solve()
{
    ll l,r;
    cin>>l>>r;
    ll output=1;
    ll c=1;
    __int128 numbers[2];
    numbers[0]=0;
    numbers[1]=0;
    __int128 numberofnumbers=0;
    bool started=0;
    __int128 ans=0;
    __int128 bottomans=0;
    l--;
    __int128 takeaway=1;
    while(numberofnumbers<r)
    {
        numbers[c%2]+=output;
        numberofnumbers+=output;
        __int128 lowerbound;
        __int128 upperbound;
        ll difference=numberofnumbers-r;
        ll difference2=numberofnumbers-l;
        if(difference<0)
        {
            difference=0;
        }
         if(difference2<0)
        {
            difference2=0;
        }

            if(c%2)
            {
                lowerbound=1+2*(numbers[c%2]-output);
                upperbound=2*(numbers[c%2]-difference)-1;
            }else
            {
                lowerbound=2*(numbers[c%2]-output+1);
                upperbound=2*(numbers[c%2]-difference);
            }
          //  cout<<lowerbound<<" "<<upperbound<<"\n";

            __int128 temp;
            if(upperbound>=lowerbound)
            {
                temp=(((lowerbound+upperbound)/2)*((upperbound-lowerbound)/2+1));
                ans+=temp;
                ans%=MOD;
            }



            if(c%2)
            {
                lowerbound=1+2*(numbers[c%2]-output);
                upperbound=2*(numbers[c%2]-difference2)-1;
            }else
            {
                lowerbound=2*(numbers[c%2]-output+1);
                upperbound=2*(numbers[c%2]-difference2);
            }
            if(upperbound>=lowerbound)
            {

            temp=(((lowerbound+upperbound)/2)*((upperbound-lowerbound)/2+1));

             bottomans+=temp;
            }




            bottomans%=MOD;


        output*=2;

        c++;
        ll newans=ans%MOD;
        ll newbottomans=bottomans%MOD;
        //cout<<newans<<"\n";
        takeaway=0;

    }
    ll newans=ans;
    ll newbottomans=bottomans;

    ll tem=(newans-newbottomans);
    if(tem<0)
        cout<<MOD+tem<<"\n";
    else cout<<tem%MOD<<"\n";

}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
