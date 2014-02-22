#include <iostream>
using namespace std;int main(){int N,i=0;long evenS=0,oddS=0;cin>>N;int a[N];for(i=0;i<N;i++){cin>>a[i];if(i%2==0){evenS+=a[i];}else if(i%2==1){oddS+=a[i];}}if(evenS>oddS){if((evenS-oddS)%11==0){cout<<"YES"<<endl;}else if((evenS-oddS)%11!=0){cout<<"NO"<<endl;}else if(oddS>evenS){if((oddS-evenS)%11==0){cout<<"YES"<<endl;}else if((oddS-evenS)%11!=0){cout<<"NO"<<endl;}}return 0;}
