#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll helper(string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l <= r) s[r--] = s[l++];
    return stoll(s);
}
ll findNext(ll num) {
    ll s = num;
    ll e = 1e18;
    ll ans = LONG_MIN;
    while (s <= e) {
        ll mid = s + (e - s) / 2;
        ll curr = helper(to_string(mid));
        if (curr > num) {
            ans = curr;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
ll findPrev(ll num) {
    ll s = 0;
    ll e = num;
    ll ans = LONG_MIN;
    while (s <= e) {
        ll mid = s + (e - s) / 2;
        ll curr = helper(to_string(mid));
        if (curr < num) {
            ans = curr;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}
string nearestPalindromic(string n) {
    if (n.length() == 1) {
        return to_string(stoll(n) - 1);
    }
    ll curr = stoll(n);
    ll next = findNext(curr);
    //cout<<" Next "<< next <<endl;
    ll prev = findPrev(curr);
    //cout<<"Prev : "<<prev<<endl;
    return abs(curr - next) < abs(curr - prev) ? to_string(next) : to_string(prev);
}
int main(int argc, char const *argv[]) {
	string ans = nearestPalindromic("121");
	cout<<"Ans is "<<ans<<endl;
	return 0;
}