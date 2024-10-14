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



vector<int> getBest(vector<int>& v) {
	int ans1 = -1, ans2 = -1, ans3 = -1;

	for (int i = 0; i < v.size(); i++) {
		if (ans1 == -1 || v[i] > v[ans1]) {
			ans3 = ans2;
			ans2 = ans1;
			ans1 = i;
		} else if (ans2 == -1 || v[i] > v[ans2]) {
			ans3 = ans2;
			ans2 = i;
		} else if (ans3 == -1 || v[i] > v[ans3]) {
			ans3 = i;
		}
	}
	return {ans1, ans2, ans3};
}


int main(){
    fast_io;
    int t;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;
    
    while(t--){
    	int n; cin >> n;
        vector<int> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) {
        	int k; cin >> k;
        	a[i] = k;
        }
        vector<int> a_best = getBest(a);


        for (int i = 0; i < n; i++) {
        	int k; cin >> k;
        	b[i] = k;
        }
        vector<int> b_best = getBest(b);

        for (int i = 0; i < n; i++) {
        	int k; cin >> k;
        	c[i] = k;
        }
        vector<int> c_best = getBest(c);
        int ans = 0;

        for (int i : a_best) {
        	for (int j : b_best) {
        		for (int k: c_best) {
        			if (i != j && j != k && k != i) {
        				ans = max(ans, a[i] + b[j] + c[k]);
        			}
        		}
        	}
        }
        
        cout << (ans) << "\n";
    }
    
    return 0;
}