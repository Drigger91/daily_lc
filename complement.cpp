#include<bits/stdc++.h>
using namespace std;

int calculateBits(int n){
    int count = 0;
    while(n != 0){
        n = n >> 1;
        count++;
    }
    return pow(2,count) - 1;
}
int findComplement(int num) {
    int closestPower = calculateBits(num);
    return num ^ closestPower;
}
int main(int argc, char const *argv[]) {
	int ans = findComplement(5);
	cout<<"Ans is : "<<ans<<endl;
	return 0;
}