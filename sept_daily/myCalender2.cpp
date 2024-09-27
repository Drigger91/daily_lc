#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    map<int, int> freq_map;
    int limit = 2;

    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        freq_map[start]++;
        freq_map[end]--;

        int overlappedBooking = 0;
        for (pair<int, int> bookings : freq_map) {
            overlappedBooking += bookings.second;
            if (overlappedBooking > limit) {
                freq_map[start]--;
                freq_map[end]++;
                if (freq_map[start] == 0) {
                    freq_map.erase(start);
                }
                if (freq_map[end] == 0) {
                    freq_map.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};
int main(int argc, char const *argv[]) {
	MyCalendarTwo calender;
	vector<vector<int>> check = {{10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}};

	for (vector<int> v : check) {
		cout << v[0]<< " " <<v[1]<< " " << (calender.book(v[0], v[1]) ? "true" : "false" ) << endl;
	}
	return 0;
}