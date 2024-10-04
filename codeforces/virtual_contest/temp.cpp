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
    #define debug(x, y) cerr << #x << " : " << x << " | " << #y << " : " << y << endl;
    #define debug(x, y, z) cerr << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;
#else
    #define debug(x)
    #define debug(x, y)
    #define debug(x, y, z)
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

int handle(vector<int>& nums) {
	int ans = 0;
	vector<int> groups(5, 0);
	for (int i : nums) groups[i]++;
	for (int i = 3; i < 5; i++) {
		int curr = groups[i];
		int req = groups[4 - i];
		if (curr == 0) continue;

		int canRideTogether = req == 0 ? curr : min(curr, req);

		ans += canRideTogether;

		groups[4 - i] -= canRideTogether;
		groups[i] -= canRideTogether;
		ans += max(groups[i], 0);
	}
	//cout<<"Ans "<<ans<<endl;
	int carry = 0;
	for (int i = 1; i <= 2; i++) {
		if (groups[i] <= 0) continue;
		int total = (groups[i] * i) + carry;
		ans += (total) / 4;
		carry = (total % 4);
		//cout<<ans<<" "<<carry<<" "<<total<<endl;
	}
	carry = (carry / 4) + (carry % 4 != 0);
	//cout<<"Carry : "<<carry<<endl;
	return ans + carry;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	while (n--) {
		int k;
		cin >> k;
		nums.push_back(k);
	}
	cout << handle(nums)<<endl;
	return 0;
}