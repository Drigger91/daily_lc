#include<bits/stdc++.h>
using namespace std;
int chalkReplacer(vector<int>& chalk, int k) {
    int i = 0;
    int n = chalk.size();
    long long sum = 0;
    for (int i : chalk) {
        sum += i;
    }
    k = k % sum;
    while (chalk[i % n] <= k) {
        k -= chalk[i % n];
        i++;
    }
    return i % n;
}

int main(int argc, char const *argv[]) {
	vector<int> arr = {5,1,5};
	cout<<chalkReplacer(arr, 22)<<endl;
	return 0;
}