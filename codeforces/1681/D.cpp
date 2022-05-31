#include <bits/stdc++.h>

using namespace std;
void solve()
{
     long long n, x;
    cin>>n>>x;
    queue<long long> q;
    map<long long ,int> m;
    q.push(x);
    m[x]=0;
    if(x==1&&n!=1)
    {
        cout<<-1<<"\n";
        return;
    }
    long long p=0;
    while(!q.empty())
    {
        string s=to_string(q.front());
        p=q.front();
        if(s.size()==n)
        {
            cout<<m[p]<<"\n";
            return;
        }
        q.pop();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0'>0)
            {
                if(!m.count(p*(s[i]-'0')))
                {
                    m[p*(s[i]-'0')]=m[p]+1;
                     q.push(p*(s[i]-'0'));

                }

            }
        }
    }
    cout<<-1<<"\n";
}
int main()
{
   solve();
}
