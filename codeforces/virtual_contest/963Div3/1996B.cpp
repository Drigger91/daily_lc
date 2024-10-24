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
	for (T i : arr) {
	 cout << i << " ";
	}
}
template<typename T> 
void print(vector<vector<T>> arr) {
	cout << endl;
	for (vector<T> v: arr) {
		print(v);
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

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> grid(n);       
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        int size = n / k;
        vector<vector<char>> ans(size, vector<char>(size));     
        for (int i = 0, row = 0; i < n; i += k, row++) {
            for (int j = 0, col = 0; j < n; j += k, col++) {
                ans[row][col] = grid[i][j];
            }
        }

       
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
