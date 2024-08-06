#include <bits/stdc++.h>
using namespace std;

int minimumPushes(string word) {
	vector<vector<int>> map;
	vector<int> freq(26, 0);
	for (char c: word){
		freq[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (freq[i] > 0) {
			map.push_back({freq[i], i});
		}
	}
	sort(map.rbegin(), map.rend());
	int ans = 0;
	for (int i = 0; i < map.size(); i++) {
		vector<int> v = map[i];
		char c = 'a' + v[1];
		int frequency = v[0];
		int elemCount = ((i + 1 )/ 8) + ((i + 1 ) % 8 != 0);
		int cost = (frequency * elemCount);
		cout<<"char : "<<c <<" "<<frequency<<" "<<cost<<endl;
		ans += cost;
	}
	return ans;
}
int main() {
	string word = "aabbccddeeffgghhiiiiii";
	int ans = minimumPushes(word);
	cout << "Ans is "<<ans <<endl;
	return 1;
}