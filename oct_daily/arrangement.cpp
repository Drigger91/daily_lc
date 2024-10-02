#include<bits/stdc++.h>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    vector<int> freq(k, 0);  
    for (int num : arr) {
        int rem = ((num % k) + k) % k;
        freq[rem]++;
    }
    for (int rem = 0; rem < k; rem++) {
      
        if (rem == 0) {
            if (freq[rem] % 2 != 0)
                return false;
        }
        else if (k % 2 == 0 && rem == k / 2) {
            if (freq[rem] % 2 != 0)
                return false;
        }
        else {
            if (freq[rem] != freq[k - rem])
                return false;
        }
    }
    
    return true;
}

int main(int argc, char const *argv[]) {
	int n = 0;
	return 0;
}