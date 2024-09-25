#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	class TrieNode {
	public:
		unordered_map<char, TrieNode*> children;  // Changed to unordered_map to save memory
		int prefixCount;

		TrieNode() {
			this->prefixCount = 0;
		}
	};

	TrieNode* root;

	Solution() {
		this->root = new TrieNode();
	}

	void insert(const string &s) {
		TrieNode* node = root;
		for (char c : s) {
			if (node->children.find(c) == node->children.end()) {
				node->children[c] = new TrieNode();
			}
			node = node->children[c];
			node->prefixCount += 1;
			//cout<<index<<" "<<node->prefixCount<<endl;
		}
		//cout<<"-----"<<endl;
	}

	int getScore(const string &s) {
		TrieNode* node = root;
		int ans = 0;
		for (char c : s) {
			node = node->children[c];
			ans += node->prefixCount;
		}
		return ans;
	}

	vector<int> sumPrefixScores(vector<string>& words) {
		for (const string &s: words) {
			insert(s);
		}
		vector<int> ans;
		for (const string &s : words) {
			ans.push_back(getScore(s));
		}
		return ans;
	}
};

int main(int argc, char const *argv[]) {
	Solution solution;
	vector<string> words = {"abc", "ab", "bc", "b"};
	vector<int> ans = solution.sumPrefixScores(words);
	for (int i: ans) cout<<i<<" ";
	return 0;
}