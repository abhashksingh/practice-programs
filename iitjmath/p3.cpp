#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

bool test_input(int test_num);
bool checkinput(long,long,long,long,long,long);
long find_minimum(long* a,int end);
long* copy_array(long* t,int st,int end);

int main()
{
    int num_test;
    cin>>num_test;
    if(test_input(num_test))
    {
        for(int i=0;i<num_test;i++)
        {
            long n,k;
            long a,b,c,r,ret=0;
            cin>>n;
            cin>>k;
            cin>>a;
            cin>>b;
            cin>>c;
            cin>>r;
            if(checkinput(n,k,a,b,c,r))
            {
				int st=0;
                long *m,*tmp ;
                m = new long[n];
                tmp=new long[k];
                m[0]=a;
                //cout<<m[0]<<" ";
                for(int i=1;i<k;i++)
                {
                    m[i]=(b * m[i-1] + c) % r;
                    //cout<<m[i]<<" ";
                }
                //cout<<"berak ";
                for(int i=k;i<n;i++)
                {
					tmp=copy_array(m,st,k);
					m[i]=find_minimum(tmp,k);
					//cout<<m[i]<<" ";
					st++;
				}
				ret=m[n-1];
                delete[] m;
            }
            cout<<"Case #"<<i+1<<": "<<ret<<endl;
        }
        
    }
}        

bool checkinput(long n ,long k,long a,long b,long c,long r  )
{
    bool ret=false;
    if(k>=0 && k<100000 && n>k && k<1000000000 && a>=0 && b>0 && c>0 && c<1000000000 && k>1 && k<1000000000)
    {
        ret=true;
    }
    return ret;
}

long find_minimum(long* a,int end)
{
    long ret;
    sort(a,a+end);
    for(int i=0;i<end-1;i++)
    {
		if((a[i+1]>(a[i]+1)))
		{
			ret=a[i]+1;
			break;
		}
	}
    return ret;
}

long* copy_array(long* t,int st,int end)
{
	long *op;
	op = new long [end];
	for(int i=0;i<end;i++)
	{
		op[i]=t[i+st];
	}
	return op;
}

bool test_input(int test_num)
{
    if(test_num>=1 && test_num<=20)
    {
        return true;
    }
    return false;
}
