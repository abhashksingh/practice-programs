// Google Code Jam 2009 - Qualification Round (Alien Language)

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

vector<string> dict;

// determine the number of dictionary words that match the given pattern
int calculate(const vector<string>& tokens,const vector<string>& remain, int idx)
{
	if (idx >= tokens.size()) return remain.size();
	if (remain.size() == 0) return 0;
	string t = tokens[idx];
	vector<string> next;
	for (int i = 0; i < remain.size(); i++)
	{
		// a valid word given the current idx comparison - 
		// append it for the next iteration
		if (t.find(remain[i][idx]) != string::npos)
		{
			next.push_back(remain[i]);
		}
	}
	// run the next iteration
	return calculate(tokens, next, idx+1);
}

int main()
{
	int L, D, N;
	cin >> L >> D >> N;
	for (int i = 0; i < D; i++)
	{
		string word; cin >> word;
		dict.push_back(word);
	}
	sort(dict.begin(),dict.end());
	// get rid of the trailing newline from using cin
	string dump; getline(cin,dump);
	for (int i = 0; i < N; i++)
	{
		string line;
		getline(cin,line);
		vector<string> tokens;
		// parse the (xxx) patterns into separate strings
		for (int j = 0; j < line.size(); j++)
		{
			if (line[j] == '(')
			{
				string token;
				j++;
				while (line[j] != ')')
				{
					token += line[j];
					j++;
				}
				tokens.push_back(token);
			}
			else
			{
				string token = string(1,line[j]);
				tokens.push_back(token);
			}
		}
		cout << "Case #" << (i+1) << ": " << calculate(tokens, dict, 0) << "\n";
	}
	return 0;
}
