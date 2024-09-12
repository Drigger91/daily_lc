#include<bits/stdc++.h>
using namespace std;


int countConsistentStrings(string allowed, vector<string>& words) {
    vector<int> freq_map(26, 0);
    for (char c : allowed) freq_map[c - 'a']++;
    int ans = 0;
    for (string s: words) {
    	bool temp = true;
    	for (char c : s) {
    		if (freq_map[c - 'a'] == 0) temp = false;
    	}
    	//if (temp) cout<<s<<endl;
    	ans += temp;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	string allowed = "abc";
	vector<string> check = {"a","b","c","ab","ac","bc","abc"};
	cout<<countConsistentStrings(allowed, check);
	return 0;
}