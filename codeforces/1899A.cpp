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
#define endl "\n"

const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define debug(x) cout << #x << " : " << x << endl;
#define debug1(x, y) cout << #x << " : " << x << " | " << #y << " : " << y << endl;
#define debug2(x, y, z) cout << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;

template<typename T> 
void print(vector<T> arr) {
	cout << endl;
	for (T i : arr) {
	 cout << i << endl;
	}
	cout << endl;
}

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
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	if ((n + 1) % 3 == 0 || (n - 1) % 3 == 0) {
    		cout << "First" << endl;
    	} else {
    		cout << "Second" << endl;
    	}
    }
    
    return 0;
}