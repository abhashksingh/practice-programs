// A recursive program to print all possible partitions of a given string
// into dictionary words
#include <iostream>
using namespace std;
 
/* A utility function to check whether a word is present in dictionary or not.
  An array of strings is used for dictionary. Using array of strings for
  dictionary is definitely not a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","love","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
		return false;
}
 
//prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);
 
void wordBreak(string str)
{
	//last argument is prefix
	wordBreakUtil(str, str.size(), "");
}
 
// result store the current prefix with spaces between words
void wordBreakUtil(string str, int size, string result)
{
	int size = str.size();
	if (size == 0) return,
	bool wb[size+1];
	memset(wb, 0, sizeof(wb)); // Initialize all values as false.
}

int main()
{
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");
	cout << "\n\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
return 0;
}
