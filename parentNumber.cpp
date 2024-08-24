#include<bits/stdc++.h>
using namespace std;

int findParent(int n) {
    if (n == 1) return -1;
    
    int parent = 1;
    int curr = 2;
    
    while (curr <= 1e9) {
    	int count = parent;
        int end = curr + (count - 1);
        if (n >= curr && n <= end) {
            return parent;
        }
        
        curr += count;
        parent++;
    }
    return -1;
}

int main() {
    int process;
    cout << "Enter process number: ";
    cin >> process;
    int parent = findParent(process);
    if (parent == -1) {
        cout << "Process " << process << " is equal to root" << endl;
    } else {
        cout << "The parent of " << process << " is " << parent << endl;
    }
    return 0;
}