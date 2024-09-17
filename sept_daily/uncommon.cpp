#include<bits/stdc++.h>
using namespace std;
void helper(map<string, int> &map, string s, int inc) {
	string curr = "";
	for (int i = 0; i < s.length(); i++) {
    	if (s[i] == ' ') {
    		map[curr] += inc;
    		curr = "";
    	} else {
    		curr.push_back(s[i]);
    	}
    }
    map[curr] += inc;
}
vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> ans;
    map<string, int> map;
    helper(map, s1, 1);
    helper(map, s2, -1);
    for (auto it: map) {
    	if (it.second == 1 || it.second == -1) {
    		ans.push_back(it.first);
    	}
    }
    return ans;
}


int main(int argc, char const *argv[]) {
	string s1 = "apple apple";
	string s2 = "bananana";
	vector<string> ans = uncommonFromSentences(s1, s2);
	for (string s : ans) cout<<s<<endl;
	return 0;
}