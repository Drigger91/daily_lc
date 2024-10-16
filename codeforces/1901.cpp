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

const int MOD = 1e9 + 7;
const ll INF = 1e18;


#define debug(x) cerr << #x << " : " << x << endl;
#define debug1(x, y) cerr << #x << " : " << x << " | " << #y << " : " << y << endl;
#define debug2(x, y, z) cerr << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;

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

void print(vector<int>& arr) {
	cout<<endl;
	for (int i : arr) {
		cout << i << " ";
	}
	cout<<endl;
}
int handle(vector<int> arr, int n) {

 	sort(arr.begin(), arr.end());
	arr.push_back(n + abs(arr.back() - n));
	//print(arr);
	int ans = INT_MIN;

	for (int i = 1; i < arr.size(); i++) {
		ans = max(ans, arr[i] - arr[i - 1]);
	}
	return ans;
}
int main(){
    fast_io;
    int t = 1;
    // Uncomment the next line if the problem has multiple test cases
    cin >> t;
    
    while(t--){
        // Your code goes here
        int n; cin >> n;
        int k ; cin >> k;

        vector<int> arr;
        arr.push_back(0);
        for (int i = 0; i < n; i++) {
        	int x; cin >> x;
        	arr.push_back(x);
        }

        cout << handle(arr, k) << endl;

    }
    
    return 0;
}

