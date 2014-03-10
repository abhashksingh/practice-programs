#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long minP(vector<long long> lis);


int main() {
    long long N,K,t,i,t1,min=999999999999,tmin,tstart=0;
    vector<long long> lis;
    cin>>N>>K;
    for(i=0;i<N;i++)
    {
     cin>>t;
     lis.push_back(t);
    }
    sort(lis.begin(), lis.end());
    for(i=0;i+K-1<N;i++)
    {
        t=lis[i];
        t1=lis[i+K-1];
        tmin=t1-t;
        if(tmin<min)
        {
            min=tmin;
            tstart=i;
        }
    }
    //cout<<"before segfault"<<endl;
    vector <long long> lis2;
    for(i=tstart;i<tstart+K;i++)
    {
lis2.push_back(lis[i]);
}
//cout<<"before segfault"<<endl;
    //minP(lis2);
    cout<<minP(lis2)<<endl;
    return 0;
}


long long minP(vector<long long> lis)
{
long long ret=0,size=lis.size(),i=0,j;
for(i=size-1;i>=0;i--)
{
//cout<<lis[i]<<endl;
for(j=i-1;j>=0;j--)
{
ret+=(lis[i]-lis[j]);
}
}
return ret;
}
