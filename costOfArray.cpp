#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;


long long modularMultiply(long long a, long long b) {
    long long result = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return result;
}

long long modularPow(long long base, long long exp) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = modularMultiply(result, base);
        base = modularMultiply(base, base);
        exp >>= 1;
    }
    return result;
}

vector<int> getFinalState(vector<int>& nums, int k, int mul) {
    int n = nums.size();
    vector<pair<long long, int>> sortedNums(n);
    
    // Sort the array by value
    for (int i = 0; i < n; i++) {
        sortedNums[i] = {nums[i], i};
    }
    sort(sortedNums.begin(), sortedNums.end());
    
    vector<long long> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = sortedNums[i].first;
    }

    for (int i = 0; i < n && k > 0; i++) {
        auto [minVal, index] = sortedNums[i];
        long long maxFactor = LLONG_MAX / minVal;
        long long operationsOnMin = min((long long)k, (long long)(log((double)maxFactor) / log(mul)));
        if (operationsOnMin == 0) operationsOnMin = 1;

        long long powResult = modularPow(mul, operationsOnMin);
        long long newVal = modularMultiply(powResult, minVal) % mod;
        result[index] = newVal;
        k -= operationsOnMin;
    }
    
    return vector<int>(result.begin(), result.end());
}

int main(int argc, char const *argv[]) {
    vector<int> check = {100000,2000};
    vector<int> ans = getFinalState(check, 2, 1000000);
    for (int i : ans) cout<<i<<" ";
    return 0;
}
