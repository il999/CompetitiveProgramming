#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    vector<int> digits;
    for(int i=s.size()-1;i>=0;i--)
    {
        digits.push_back(s[i]-'0');
    }
    int n=digits.size();
    //cout<<"DGAG"<<n<<endl;

    for(int i=1;i<n;i++)
    {
        if(digits[i]+digits[i-1]>=10)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(j==i)
                {
                    cout<<digits[i]+digits[i-1];
                    j--;
                }else
                {
                    cout<<digits[j];

                }
            }
            cout<<endl;
            return;
        }
    }
    cout<<digits[n-1]+digits[n-2];
    for(int i=n-3;i>=0;i--)
    {
        cout<<digits[i];
    }

    cout<<endl;

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
