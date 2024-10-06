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




void handle() {
	debug1("hi", "hello");
	debug("hi")
	debug2("1", "2", "3");
	vector<int> check;
	check.pb(1);
	cout<<check[0]<<endl;
}

int main(){
    fast_io;
    int t = 1;
    // Uncomment the next line if the problem has multiple test cases
    // cin >> t;
    
    while(t--){
        handle();

    }
    
    return 0;
}