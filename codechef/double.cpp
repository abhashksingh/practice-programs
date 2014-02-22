#include <iostream>
     
using namespace std;
     
int main()
{
	int t,num;
    cin>>t;
    while(t--)
    {
		cin>>num;
    	if(num%2==0)
	    {
    		cout<<num<<endl;
	    }	
    	else
	    {
    		cout<<num-1<<endl;
	    }
    }
} 
