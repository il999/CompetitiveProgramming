#include <iostream>

using namespace std;

int main()
{
    int n=0;
    int t=0;
    cin>>n;
    cin>>t;
    string q;
    int pos[n];
    int boys=0;
    cin>>q;
    for(int i=0;i<n;i++)
    {

        if(q[i]=='B')
        {
            boys+=1;
            pos[boys-1]=i;
        }
    }

    for(int i=0;i<t;i++)
    {
        for(int j=0;j<boys;j++)
        {
            if(q[pos[j]+1]=='G')
            {
                //jhh

                q[pos[j]+1]='B';
                q[pos[j]]='G';
                pos[j]=pos[j]+1;


            }
        }
    }

    cout<<q<<endl;

}
