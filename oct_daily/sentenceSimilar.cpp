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
    #define debug2(x, y) cerr << #x << " : " << x << " | " << #y << " : " << y << endl;
    #define debug3(x, y, z) cerr << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;
#else
    #define debug(x)
    #define debug2(x, y)
    #define debug3(x, y, z)
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

bool handle(vector<string>& words1, vector<string>& words2) {
	int st = 0;
    int e1 = words1.size() - 1;
    int e2 = words2.size() - 1;
    while (st < words1.size() && words1[st] == words2[st])
        st++;
    while (e1 >= 0 && words1[e1] == words2[e2]) {
        e1--;
        e2--;
    }
    return e1 < st;
}

bool areSentencesSimilar(string s1, string s2) {
    vector<string> words1, words2;
    stringstream ss1(s1), ss2(s2);
    string s = "";
    while (ss1 >> s) words1.push_back(s);
    while (ss2 >> s) words2.push_back(s);

    if (words1.size() > words2.size()) return handle(words2, words1);
    return handle(words1, words2);
}


int main(){
    fast_io;
    string s1 = "My name is piyush";
    string s2 = "My piyush";
    cout << (areSentencesSimilar(s1, s2) ? "true" : "false") << endl;
    
    return 0;
}