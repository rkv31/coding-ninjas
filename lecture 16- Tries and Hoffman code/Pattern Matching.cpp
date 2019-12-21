Pattern Matching
Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.
Return true or false.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Line 3 : Pattern p (a string)
Output Format :
true ot false
Sample Input 1 :
4
abc def ghi cba
de
Sample Output 2 :
true
Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true
Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false

// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    bool search(TrieNode *root, string pattern)
    {
        if (pattern.size() == 0)
        {
            return true;
        }
        int index = pattern[0] - 'a';
        TrieNode *child = root->children[index];
        if (child != NULL)
            return search(child, pattern.substr(1));
        else
            return false;
    }
	
    
    bool patternMatching(vector<string> vect, string pattern) {
		// Complete this function
		// Return true or false
        for (int i=0; i< vect.size(); i++)
        {
            string str = vect[i];
            while(str.size() != 0)
            {
                insertWord(str);
                str = str.substr(1);
            }
        }
        return search(root, pattern);
        
	}
};
