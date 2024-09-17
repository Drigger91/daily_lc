#include<bits/stdc++.h>
using namespace std;


int findTheLongestSubstring(string s) {
    int prefix = 0;
    int characterMap[26] = {0};
    characterMap['a' - 'a'] = 1;
    characterMap['e' - 'a'] = 2;
    characterMap['i' - 'a'] = 4;
    characterMap['o' - 'a'] = 8;
    characterMap['u' - 'a'] = 16;
    vector<int> freq_map(32, -1);
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        prefix ^= characterMap[s[i] - 'a'];
        if (freq_map[prefix] == -1 && prefix != 0) freq_map[prefix] = i;
        ans = max(ans, i - freq_map[prefix]);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	int ans = findTheLongestSubstring("lcpysh");
	cout<<ans<<endl;
	return 0;
}