//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int t;
    int a[n];
    int modu[k];

    for(int i=0;i<k;i++)
    {
        modu[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        modu[a[i]%k]++;
    }
    long long score=0;
    int temp=0;
    for(int i=1;i<k;i++)
    {
      //  cout<<i<<" "<<k-i<<"\n"
        if(modu[i]>0&&modu[k-i]>0&&k-i!=i)
        {
            //cout<<"GDS";
            //cout<<i<<" "<<k-i<<"\n";
            score+=min(modu[i],modu[k-i]);
            temp= min(modu[i],modu[k-i]);
            modu[i]-=temp;
            modu[k-i]-=temp;
        }else if(k-i==i)
        {
            score+=(modu[i])/2;
            if(modu[i]%2==0)
            {
                modu[i]=0;
            }else
            {
                modu[i]=1;
            }
        }
    }

    int amount=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        score+=a[i]/k;
        if(a[i]<k&&modu[a[i]]>0)
        {
            v.push_back(a[i]);
            //modu[a[i]]--;
        }
    }
    int last=0;
    for(int i=k-1;i>=1;i--)
    {
        for(int j=max(last,k-i);j<i;j++)
        {

            if(modu[i]<=0)
            {
                break;
            }
            //cout<<"DGS";
            temp=min(modu[i],modu[j]);

            score+=temp;
            last=j;
            modu[i]-=temp;
            modu[j]-=temp;
        }
        if(modu[i]>=2&&i*2>=k)
        {
            score+=modu[i]/2;

        }
    }

    cout<<score<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
