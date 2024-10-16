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


#define debug(x) cout << #x << " : " << x << endl;
#define debug1(x, y) cout << #x << " : " << x << " | " << #y << " : " << y << endl;
#define debug2(x, y, z) cout << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;

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
	cout << endl;
	for (int i : arr) cout << i << " ";
	cout << endl;
}

int main(){
    fast_io;
    int t; cin >> t;
    
    while(t--){
    	int n; cin >> n;
    	int r; cin >> r;
    	int ans = 0;
    	vector<int> arr;
    	for (int i = 0; i < n; i++) {
    		int x; cin >> x;
    		arr.push_back(x);
    	}
    	int sum = 0;

    	for (int i = 0; i < n; i++) {
    		int elem = arr[i];
    		int row = arr[i] / 2;
    		int rem = arr[i] % 2;
    		arr[i] = rem;
    		
    		ans += (row * 2);
    		r -= row;
    		//debug1(row, i);
    		sum += rem;
    	}
    	//print(arr);
    	//debug(r);

    	if (sum == 2*r) {

    	} else if (sum > r && sum < 2*r) {
    		while (sum > r) {
    			sum -= 2;
    			r--;
    		}
    		ans += sum;
    	} else {
    		ans += sum;
    	}



    	cout << ans << endl;

    }
    
    return 0;
}