#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
long long countOfSubstrings(string word, int k) {
    unordered_map<char, int> map;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int v = 0;
    int cnt = 0;
    int left = 0;
    long long ans = 0;
    int pos = -1;

    for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        if (vowels.count(c)) {
            if (map[c] == 0) {
                v++;
            }
            map[c]++;
        } else {
            cnt++;
        }

        while (cnt > k) {
            char left_char = word[left];
            if (vowels.count(left_char)) {
                map[left_char]--;
                if (map[left_char] == 0) {
                    v--;
                }
            } else {
                cnt--;
            }
            left++;
        }

        if (v == 5) {
            while (vowels.count(word[left]) && map[word[left]] > 1) {
                map[word[left]]--;
                left++;
            }
            pos = left;
        }

        if (v == 5 && cnt == k && pos != -1) {
            ans += left - pos + 1;
        }
    }
    return ans;
}

int main() {
    
    string word1 = "aeioqq";
    int k1 = 1;
    cout << "Example 1 Output: " << countOfSubstrings(word1, k1) << endl;

    string word2 = "aeiou";
    int k2 = 0;
    cout << "Example 2 Output: " << countOfSubstrings(word2, k2) << endl;

    string word3 = "ieaouqqieaouqq";
    int k3 = 1;
    cout << "Example 3 Output: " << countOfSubstrings(word3, k3) << endl;

    return 0;
}