#include <iostream>

using namespace std;
#include <bits/stdc++.h>
int main()
{

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> pos;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a'&&i<n-2)
        {

            if(s[i+1]=='b'&&s[i+2]=='c')
            {
               pos.push_back(i);
            }
        }
    }

    int current=pos.size();
    int a;
    char b;
    string s1=s;
    int r=0;
    int prev=0;
    int cur=0;
    while(q--)
    {
        cin>>a>>b;
        a--;
        s1[a]=b;

        prev=0;
        cur=0;
       for(int i=a-2;i<=a;i++)
       {
           if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
           {
               prev++;
           }
           if(s1[i]=='a'&&s1[i+1]=='b'&&s1[i+2]=='c')
           {
               cur++;
           }
       }
       s[a]=b;
       current+=(cur-prev);
       cout<<current<<endl;
    }
}
