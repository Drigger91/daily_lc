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
    #define debug1(x, y) cerr << #x << " : " << x << " | " << #y << " : " << y << endl;
    #define debug2(x, y, z) cerr << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;
#else
    #define debug(x)
    #define debug1(x, y)
    #define debug2(x, y, z)
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


int handle(string& s) {

	vector<int> freq(2,0);

	for (char c : s) {
		freq[c - '0']++;
	}

	int n = s.length();

	for (int i = 0; i < n; i++) {
		int idx = (s[i] - '0' == 0 ? 1 : 0);

		if (freq[idx] == 0) return n - i;


		// swap
		freq[idx]--;
	}
	return 0;
}
int main(){
    fast_io;
    int t ;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;
    
    while(t--){
        // Your code goes here
        string s;
        cin >> s;
        cout << handle(s) << endl;

    }
    
    return 0;
}