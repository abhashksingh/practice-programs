#include <regex>
#include <iostream>

using namespace std;

void process(string inp);

int main() {
    
    string inp;
    char c;
    int test;
    cin>>test;
    int s=scanf("%c",&c);
    while(test--)
    {
        getline(cin,inp);
        process(inp);
    }
    return 0;
}

void process(string inp)
{
    string panex= "[A-Z]{5}[0-9]{4}[A-Z]{1}";
    regex panreg(panex,regex_constants::basic);
    
    if(regex_match(inp,panreg))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}