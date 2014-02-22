#include <iostream>
using namespace std;
long long nCr(int n,int r)
{
long long ret=1;
for(int i=1;i<=r;i++)
{
ret=(ret*n/i);
n--;
}
return ret;
}
int main()
{
int N,i=0;
cin>>N;
for(i=0;i<N;i++)
{
int n,r;
cin>>n;
cin>>r;
cout<<nCr(n,r)<<endl;
}
return 0;
}
