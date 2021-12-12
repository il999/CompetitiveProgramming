#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        bool last=true;
        bool print=false;
        int c=1;
        int l=1;
        for(int i=0;i<n;i++)
        {
            cin>>l;
            if(l==0&&last==false&&!print)
            {
                cout<<-1<<endl;

                print=true;
            }else if(l==1)
            {

                if(last==true&&i!=0)
                {
                    c+=5;

                }else
                {
                    c++;
                }
                last=true;
            }else
            {
                last=false;
            }
        }

        if(!print)
        {
            cout<<c<<endl;
        }
    }
}
