#include <iostream>

using namespace std;
void solve()
{
    long long h,d,mh,md=0;
    cin>>h>>d;
    cin>>mh>>md;
    long long k,w=0;
    long long a=0;
    cin>>k>>w>>a;
    if(md==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    long long temp=0;
    long long temp2=0;
    long long test=0;
    long long amount=0;
    long long amount2=0;
    //i is amount of coints spent on weapons
    for(long long i=0;i<=k;i++)
    {
        temp=h;
        temp2=d;
        temp=h+a*(k-i);
        temp2=d+ w*(i);
        //cout<<"damahge" << temp2<<"\n";
        amount=temp/md;
        if(temp%md!=0)
        {
            amount++;
        }
        amount2=mh/temp2;
        if(mh%temp2!=0)
        {
            amount2++;
        }
        if(amount>=amount2)
        {
            cout<<"YES"<<"\n";
            return;
        }
        //cout<<" answer :"<<amount<<" "<<amount2<<"\n";






    }
    cout<<"NO"<<"\n";

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
