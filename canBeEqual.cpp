#include<bits/stdc++.h>
using namespace std;
bool canBeEqual(vector<int>& target, vector<int>& arr) {
    vector<int> freq(1001, 0);
    for (int i : arr) freq[i]++;
    for (int i : target) freq[i]--;
    for (int i : freq) {
        if (i > 0) return false;
    }
    return true;
}
int main() {
	vector<int> nums = {2,4,1,3};
	vector<int> target = {1,2,3,4};
	cout << "Ans is: " << canBeEqual(target, nums);
	return 1;

}