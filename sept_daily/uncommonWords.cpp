#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		class TrieNode {
		    public:
			    vector<TrieNode*> children;
			    bool isTerminal;
			    TrieNode() {
			        children = vector<TrieNode*>(26, nullptr);
			        isTerminal = false;
			    }
		};
		TrieNode* root;
		Solution() {
			this->root = new TrieNode;
		}
		void insert(string& s) {
			//if (root == nullptr) root = new TrieNode();
			TrieNode* node = root;
			for (char c : s) {
				if (node->children[c - 'a'] == nullptr) {
					node->children[c - 'a'] = new TrieNode();
				}
				node = node->children[c - 'a'];
			}
			node->isTerminal = true;
		}

		int minExtraChar(string s, vector<string>& dictionary) {
		    for (string str: dictionary) {
		    	insert(str);
		    }
		    int n = s.length();
		    vector<int> dp(n + 1);
		    dp[n] = 0;
		    for (int i = n - 1; i >= 0; i--) {
		   		dp[i] = dp[i + 1] + 1;
		   		TrieNode* node = root;
		   		for (int j = i; j < n; j++) {
		   			int c = s[j] - 'a';
		   			if (node->children[c] == nullptr) break;
		   			node = node->children[c];
		   			if (node->isTerminal) {
		   				dp[i] = min(dp[i], dp[j + 1]);
		   			}
		   		}
		   	}
		   return dp[0];
		}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> dictionary = {"leet", "code"};
	string s = "leetscode";
	int ans = solution.minExtraChar(s, dictionary);
	cout<<"Ans " << ans<<endl;
	return 0;
}