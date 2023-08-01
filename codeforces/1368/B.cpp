#include <iostream>
using namespace std;
using ll = long long;
int main()
{
ll k; cin>>k;
int low =0; int high=100; int mid=0; int works=1;
ll ans=0;
while (low<high){
mid=(low+high)/2;
ll tp=mid;
for (int i=0;i<9;i++){
tp=mid*1ll*tp;
}
if(tp<k){
low=mid+1;
}else{
high=mid; works=mid;
ans=tp;
}
}
int sto=-1; ll tp=ans;
for(int i =0;i<10;i++)
{
if((tp/(works))*(works-1)>=k){
tp/=works;
tp*=(works-1); sto=i;
}
}
string s="codeforces";
string ansr="";
for(int i=0;i<=sto;i++){
for (int j=0;j<works-1;j++) ansr+=s[i];
}
for(int i=sto+1;i<10;i++) {
for(int j=0;j<works;j++) ansr+=s[i];
}
cout<<ansr<<"\n";
}