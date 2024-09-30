#include <bits/stdc++.h>
using namespace std;

long long handle(int n, vector<int>& v) {
    if (n == 1) return -1;
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    int max_a = *max_element(v.begin(), v.end());
    int max_index = find(v.begin(), v.end(), max_a) - v.begin();
    double initial_threshold = (double) (sum) / (n * 2.0);
    long long initial_k = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] < initial_threshold){
            initial_k++;
        }
    }

  
    if (initial_k > n / 2) {
        return 0;
    }

  
    long long left = 0;
    long long right = 1e12;
    long long ans = -1;
    while(left <= right){
        long long mid = left + (right - left) / 2;
        double new_sum = sum + mid;
        double new_threshold = new_sum / (n * 2.0);
        long long k = 0;
        for(int i = 0; i < n; i++) {
            double current_w = v[i];
            if(i == max_index){
                current_w += mid;
            }
            if(current_w < new_threshold){
                k++;
            }
        }

      
        if(k > n / 2) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;  
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        cout << handle(n, v) << "\n";
    }
    return 0;
}


// 6
// 1
// 2
// 2
// 2 19
// 3
// 1 3 20
// 4
// 1 2 3 4
// 5
// 1 2 3 4 5
// 6
// 1 2 1 1 1 25
