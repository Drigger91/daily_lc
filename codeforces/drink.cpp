#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define endl "\n"

// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;

// Debugging Macros (Disable when submitting)
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " : " << x << endl;
    #define debug2(x, y) cerr << #x << " : " << x << " | " << #y << " : " << y << endl;
    #define debug3(x, y, z) cerr << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;
#else
    #define debug(x)
    #define debug2(x, y)
    #define debug3(x, y, z)
#endif

// Utility Functions
ll power(ll a, ll b, ll mod = MOD){
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

int handle(vector<int>& nums, int k) {
	int s = 0;
	int e = nums.size();
	int ans = -1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (nums[mid] > k) {
			e = mid - 1;
		} else {
			ans = max(mid, ans);
			s = mid + 1;
		}
	}
	return ans == nums.size() ? ans : ans + 1;
}




int main(){
    fast_io;
    int t;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;
    vector<int> nums;
    while(t--){
        int k;
        cin >> k;
        nums.push_back(k);
    }
    sort(nums.begin(), nums.end());
    int q;
	cin >> q;
	while(q--) {
		int k;
		cin >> k;
		cout << handle(nums, k)<<endl;
	}

    
    return 0;
}