//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> fir;
    vector<int> sec;
    int thing;
    long long totf=0;
    long long tots=0;
    for(int i=0;i<n;i++)
    {
        cin>>thing;
        if(thing>0)
        {
            fir.push_back(thing);
            totf+=thing;
        }else
        {
            sec.push_back(abs(thing));
            tots+=abs(thing);
        }
    }
    if(tots>totf)
    {
        cout<<"second\n";
    }else if(tots<totf)
    {
        cout<<"first\n";
    }else
    {
        int winner=0;
        for(int i=0;i<min(fir.size(),sec.size());i++)
        {
            if(fir[i]>sec[i])
            {
                cout<<"first\n";
                return;
            }else if(fir[i]<sec[i])
            {
                cout<<"second\n";
                return;
            }
        }
        if(fir.size()==sec.size())
        {
            if(thing<0)
            {
                cout<<"second\n";
                return;
            }else
            {
                cout<<"first\n";
                return;
            }
        }else
        {
            if(fir.size()<sec.size())
            {
                cout<<"first\n";
                return;
            }else
            {
                cout<<"second\n";
                return;
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
