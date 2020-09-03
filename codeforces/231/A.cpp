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

        if(n&&q==1||n&&l==1||l&&q==1)
        {
            count1+=1;
        }
    }
    cout<<count1;
}
