#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int dp[511][21];   // memo cache
string lineR;      // used to keep track of the line we are given
string textR = "welcome to code jam";   // the phrase we are looking for

int calc(int lineIdx, int textIdx)
{
	// base cases
	if (textIdx >= textR.size()) return 1;
	if (lineIdx >= lineR.size()) return 0;
	// seen it before - return the previously computed value
	if (dp[lineIdx][textIdx] != -1) return dp[lineIdx][textIdx];
	dp[lineIdx][textIdx] = 0;
	for (int i = lineIdx; i < lineR.size(); i++)
	{
		// valid transition - add all the combinations
		if (lineR[i] == textR[textIdx])
		{
			dp[lineIdx][textIdx] = (dp[lineIdx][textIdx] + calc(i+1, textIdx+1)) % 10000;
		}
	}
	return dp[lineIdx][textIdx] % 10000;
}

int main()
{
	int N;
	cin >> N;
	// get rid of the trailing newline character
	string dump; getline(cin,dump);
	for (int i = 0; i < N; i++)
	{
		// reset the memo cache
		memset(dp,-1,sizeof(dp));
		string line; getline(cin,line);
		lineR = line;
		int v = calc(0,0);
		// correct the output into the required 4 digits
		ostringstream oss; oss << v;
		string output = oss.str();
		while (output.size() < 4) output = "0" + output;
		cout << "Case #" << (i+1) << ": " << output << "\n";
	}
	return 0;
}
