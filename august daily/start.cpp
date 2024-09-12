#include<bits/stdc++.h>
using namespace std;

bool checkStrings(string s1, string s2) {
	// one swap means two chars out of place

	if (s1.length() != s2.length()) return false;

	vector<int> index;

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) index.push_back(i);
	}

	if (index.size() != 2) return false;

	swap(s1[index[0]], s1[index[1]]);

	return s1 == s2;
}


int main(int argc, char const *argv[]) {
	bool check = checkStrings("bank", "canb");
	cout<<"Ans is : " << check;
	return 0;
}				