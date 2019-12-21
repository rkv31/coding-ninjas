Auto complete
Givan n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Line 3 : Word w
Output Format :
All possible words (in different lines)
Note : Order of words doesn't matter.
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"
	
	

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
    
    void find_and_print(TrieNode *root, string pattern, string ans)
    {
        if (pattern.size() == 0)
        {
            if (root->isTerminal == true)
            {
                cout<<ans<<endl;
            }
            for (int i=0; i< 26; i++)
            {
                TrieNode *child = root->children[i];
                if (child != NULL)
                {
                    string ans1 = ans;
                    ans1 += child->data;
                    find_and_print(child, pattern, ans1);
                }
            }
        }
        else
        {
            int index = pattern[0] - 'a';
            TrieNode *child = root->children[index];
            if (child != NULL)
            {
                ans += child->data;
                find_and_print(child, pattern.substr(1), ans);
            }
        }
        
            
    }
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for (int i=0; i< input.size(); i++)
        {
            insertWord(input[i]);
        }
        string ans;
        find_and_print(root, pattern, ans);
    }
    
    
    

};
