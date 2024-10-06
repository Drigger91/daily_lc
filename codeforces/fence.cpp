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
	int sum = 0;
	for (int i = 0; i < k; i++) sum += nums[i];
	int ans = 0;
	int e = k;
	int global_mini = sum;
	//cout<<"Sum "<<sum<<endl;
	//debug(nums.size() - k);
	int size = nums.size() - k;
	for (int i = 1; i <= size; i++) {
		int new_sum = sum - nums[i-1];
		new_sum += nums[e++];
		//debug3(new_sum, global_mini, i);
		if (global_mini >= new_sum) {
			ans = i;
			global_mini = new_sum;
		}
		sum = new_sum;
	}
	return ans + 1;
}



int main(){
    fast_io;
    int t = 1;
    // Uncomment the next line if the problem has multiple test cases
    // cin >> t;
    // 10 2
	// 3 1 4 1 4 6 2 1 4 6
    // 1 2 3 4 5 6 7 8 9 10
    while(t--){
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> nums;
        while (n--) {
        	int x;
        	cin >> x;
        	nums.push_back(x);	
        }
        cout << handle(nums, k) << endl;

    }
    
    return 0;
}