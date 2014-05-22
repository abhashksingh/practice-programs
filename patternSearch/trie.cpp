#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


using namespace std;

class trie_node
{
	public:
	int value;
	trie_node *children[ALPHABET_SIZE];
};

// trie ADT
class trie
{
	public:
	trie_node *root;
	int count;
};

// Returns new trie node (initialized to NULLs)
trie_node *getNode(void)
{
	trie_node *pNode = NULL;
	pNode = new trie_node;

	if( pNode )
	{
		int i;
		pNode->value = 0;

		for(i = 0; i < ALPHABET_SIZE; i++)
		{
			pNode->children[i] = NULL;
		}
	}
return pNode;
}

// Initializes trie (root is dummy node)
void initialize(trie *pTrie)
{
	pTrie->root = getNode();
	pTrie->count = 0;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(trie *pTrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	trie_node *pCrawl;

	pTrie->count++;
	pCrawl = pTrie->root;

	for( level = 0; level < length; level++ )
	{
		index = CHAR_TO_INDEX(key[level]);
		if( !pCrawl->children[index] )
		{
			pCrawl->children[index] = getNode();
		}

		pCrawl = pCrawl->children[index];
	}
	// mark last node as leaf
	pCrawl->value = pTrie->count;
}

// Returns non zero, if key presents in trie
int search(trie *pTrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	trie_node *pCrawl;

	pCrawl = pTrie->root;

	for( level = 0; level < length; level++ )
	{
		index = CHAR_TO_INDEX(key[level]);

		if( !pCrawl->children[index] )
		{
			return 0;
		}

		pCrawl = pCrawl->children[index];
	}

	return (0 != pCrawl && pCrawl->value);
}

// Driver
int main()
{
	// Input keys (use only 'a' through 'z' and lower case)
	char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	trie trie1;
	char output[2][32] = {"Not present in trie", "Present in trie"};

	initialize(&trie1);

	// Construct trie
	for(int i = 0; i < ARRAY_SIZE(keys); i++)
	{
		insert(&trie1, keys[i]);
	}

	// Search for different keys
	printf("%s --- %s\n", "the", output[search(&trie1, "the")] );
	printf("%s --- %s\n", "these", output[search(&trie1, "these")] );
	printf("%s --- %s\n", "their", output[search(&trie1, "their")] );
	printf("%s --- %s\n", "thaw", output[search(&trie1, "thaw")] );

return 0;
}
