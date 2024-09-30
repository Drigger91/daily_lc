#include<bits/stdc++.h>
using namespace std;


vector<int> validSequence(string word1, string word2) {
    vector<int> result;
    int i = 0;
    int j = 0;
    int count = 0; 
    vector<int> update; 
    while (i < word1.size() && j < word2.size()) {
        if (word1[i] == word2[j]) {
            result.push_back(i);
            j++;  
        } else if (!count) {
            count++;  
            result.push_back(i);  
            j++;
        } else {
        	i++;
        }
        if (i == word1.size() && result.size() < word2.size()) {
            return {};
        }
        update = result;
    }    
    //return j == word2.size() ? result : vector<int>();
    return result;
}

int main(int argc, char const *argv[]) {
	string s1 = "aaaaaa";
	string s2 = "abc";
	vector<int> ans = validSequence1(s1, s2);
	for (int i : ans) cout << i << " ";
	return 0;
}