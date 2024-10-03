#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll handle(ll n, ll k) {
    if (k == 1) {
        return n;
    }

    ll count = 0;

    while (n > 0) {
        ll power = 1;
        while (power * k <= n) {
            power *= k;
            if (power > (1e18 / k)) break;
        }
        
        n -= power;
        count++;
    }

    return count;
}

int main(int argc, char const *argv[]) {
	int x;
	cin >> x;
	while (x--) {
		ll n;
		ll k;
		cin>>n;
		cin>>k;
		cout<<handle(n, k)<<endl;
	}
	return 0;
}





















