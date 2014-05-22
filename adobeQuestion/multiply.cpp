#include <iostream>

using namespace std;

int sum(int a,int b)
{return a+b;}

int multiplyNumbers(int M,int N){
/*
 For your reference, a function of the prototype int sum(int,int); has already been defined.
When you're going to sum 2 numbers, use the above function.

For instance to sum up M & N, you can call the function sum(M,N) and it would return M+N. 

Please avoid the usage of '+' operator and use the function instead
*/
    //assuming I can use divide operator
    if(N==1)
    {
        return M;
    }
    else if(N%2==0)
    {
        return multiplyNumbers(sum(M,M),N/2);    
    }
    else
    {
        return multiplyNumbers(sum(M,sum(M,M)),(N-3)/2);
    }
}
int main()
{
	 int a =5,b=6;
	 cout << multiplyNumbers(5,7)<<endl;
}
