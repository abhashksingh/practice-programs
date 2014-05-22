#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <map>

using namespace std;

void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = "/")
{
	// Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	string::size_type pos     = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}

class Node
{
	public:
	string key;
	map<string,Node* > directories;
	Node(string inp){key=inp;}
	Node()
	{Node("");};
};
long long ans=0;

void processRoot(vector<string>& directories,bool output);

Node* root; 

int main()
{
	long long T,i,j,N,M;
	cin>>T;
	for(i=1;i<=T;i++)
	{
		root = new Node("Root");
		cout<<"Case #"<<i<<": ";
		ans=0;
		cin>>N>>M;
		cin.ignore();
		for(j=0;j<N;j++)
		{
			string inp;
			getline(cin,inp);
			vector<string> tokens;
			Tokenize(inp,tokens,"/");
			processRoot(tokens,false);
		}
		for(j=0;j<M;j++)
		{
			string inp;
			getline(cin,inp);
			vector<string> tokens;
			Tokenize(inp,tokens,"/");
			processRoot(tokens,true);
		}
		
		cout<<ans<<endl;
		delete root;
	}
}

void processRoot(vector<string>& tokens,bool output)
{
	Node *temp=root;
	long long int j=0,lim=tokens.size();
	//map<string,Node*>::iterator it;
	for(j=0;j<lim;j++)
	{
		/*if(j>0 && tokens[j].compare(tokens[j-1])==0)
		{
			Node* t1 = new Node;
			t1->key = tokens[j];
			temp->directories[tokens[j]] = t1;
			if(output)
			{
				ans++;
			}
			temp = t1;
		}
		else if(temp->key.compare(tokens[j])==0)
		{
			//you are at right place
			continue;
		}
		else*/
		if(temp->directories.find(tokens[j])!=temp->directories.end())
		{
			//the key exists
			temp = temp->directories[tokens[j]];
		}
		else
		{
			Node* t1 = new Node;
			t1->key = tokens[j];
			temp->directories[tokens[j]] = t1;
			if(output)
			{
				ans++;
			}
			temp = t1;
		}
	}
}
