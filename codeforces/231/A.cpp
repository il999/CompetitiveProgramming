#include <iostream>

using namespace std;

int main()
{
    int r;
    cin>>r;
    int n;
    int l;
    int q;
    int count1=0;

    for(int i=0;i<r;i++)
    {
        cin>>n;
        cin>>l;
        cin>>q;

        if(n==1)
        {
            if(q==1||l==1)
            {
                count1+=1;
            }
        }
        else if(q==1)
            {
                if(l==1)
                {
                    count1+=1;
                }
                }
            }


    cout<<count1;
}

