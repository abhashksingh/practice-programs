#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int Count( const std::string & str,  const std::string & obj ) {
    int n = 0;
    std::string ::size_type pos = 0;
    while( (pos = obj.find( str, pos )) != std::string::npos ) {
    	n++;
    	pos += str.size();
    }
    return n;
}
int main()
{
	int i=0;
	string S,T1,T2;
	while(getline(cin,S)&&getline(cin,T1)&&getline(cin,T2))
	{
		string res = T1+T2;
		cout<<Count(S,res)<<endl;
	}
}
