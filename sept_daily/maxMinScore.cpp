#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<pair<int, int>>& intervals, int d, int minDiff) {
    int prev = intervals[0].first;
    for (int i = 1; i < intervals.size(); i++) {
       
        int start = max(prev + minDiff, intervals[i].first);
        if (start > intervals[i].second) {
            return false;
        }
        prev = start;
    }
    return true;
}

int maxMinDiff(vector<int>& start, int d) {
    int n = start.size();
    vector<pair<int, int>> intervals;
    
   
    for (int i = 0; i < n; i++) {
        intervals.push_back({start[i], start[i] + d});
    }
    
   
    sort(intervals.begin(), intervals.end());
    
    int s = 0;
    int e = intervals[n-1].second - intervals[0].first;
    int best = 0;
   
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(intervals, d, mid)) {
            best = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return best;
}

int main() {
    vector<int> start = {6, 0, 3};
    int d = 2;
    
    cout << "Maximum possible score: " << maxMinDiff(start, d) << endl;
    return 0;
}