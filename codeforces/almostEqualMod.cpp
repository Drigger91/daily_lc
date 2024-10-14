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






int main(){
    fast_io;
    int t ;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;
     
    while(t--){ 
    	int ans = 0;
       int n; cin >> n;
       vector<int> a(n);
       bool isEven = false;
       bool isOdd = false;
       for (int i = 0; i < n; i++) {
       		int k; cin >> k;
       		if (k & 1) {
       			isOdd = true;
       		} else {
       			isEven = true;
       		}
       		a[i] = k;
       }
       if (isEven && isOdd ) cout << 2 << endl;
       else {
	       sort(a.begin(), a.end());
	       vector<int> diff;
	       for (int i = 1; i < n; i++) {
	       	diff.push_back(abs(a[i] - a[i - 1]));
	       }
	       int ans = diff[0];

	       for (int i = 1; i < diff.size(); i++) {
	       	ans = gcd(ans, diff[i]);
	       }
	       cout << ans << "\n";
       }
       

    }
    
    return 0;
}