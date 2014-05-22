#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int areBracketsMatched(string s) 
{
    long long len = s.length(),i=0; 
    stack<char> st;
    bool val = true;
    for(i=0;i<len;i++)
    {
        if(s[i]=='['||s[i]=='{'||s[i]=='(')
        {
             st.push(s[i]);
        }
        else if(s[i]==']')
        {
            if(st.empty()||st.top()!='[')
            {
                val=false;
                break;
            }
            else
            {
                st.pop();
            }
        }
        else if(s[i]=='}')
        {
            if(st.empty()||st.top()!='{')
            {
                val=false;
                break;
            }
            else
            {
                st.pop();
            }
        }
        else if(s[i]==')')
        {
            if(st.empty()||st.top()!='(')
            {
                val=false;
                break;
            }
            else
            {
                st.pop();
            }
        }
    }
    if(val){cout<<1<<endl;}
    else{cout<<0<<endl;}
 
}

int main()
{
	string str = "(2))";
	/*cout <<*/
	areBracketsMatched(str);
}
 
