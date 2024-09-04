#include<bits/stdc++.h>
using namespace std;

int getLucky(string s, int k) {
    string number = "";
    for (int i = 0; i < s.length(); i++) {
       number += to_string((s[i] - 'a') + 1);
    }
    int ans = 0;
    while (k--) {
        string temp = "";
        int tempAns = 0;
        for (int i = 0; i < number.length(); i++) {
            tempAns += number[i] - '0';
        }
        temp = to_string(tempAns);
        ans = tempAns;
        number = temp;
        //cout<<number<<endl;
    }
    return ans;
}
int main(int argc, char const *argv[]) {
	string str = "iiii";
	cout<<getLucky(str, 2);
	return 0;
}