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



// 2
// 8 1 1
// 6
// 3
// 10 3 3
// 1 4 8
// 2 3 10
int handle(int n, vector<int>& pos, int k) {
	int size = pos.size();
    if (k < pos[0]) {
    	return pos[0] - 1;
    }
    if (k > pos.back()) {
    	return n - pos.back();
    }
    auto upper = lower_bound(pos.begin(), pos.end(), k);
    auto lower = upper;
    lower--;
    int s = *lower;
    int e = *upper;
    int mid = s + (e - s)/2;
    int t1 = mid - s;
    int t2 = e - mid;
    return min(t1, t2);
}


int main(){
    fast_io;
    int t ;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;

    
    while(t--){
        int n, m, q;
        cin >> n;
        cin >> m;
        cin >> q;
        vector<int> pos;
        for (int i = 0; i < m; i++) {
        	int k;
        	cin >> k;
        	pos.push_back(k);
        }
        sort(pos.begin(), pos.end());
        for (int i = 0; i < q; i++) {
        	int k;
        	cin >> k;
        	cout << handle(n, pos, k) << endl;
        }

    }
    
    return 0;
}