#include<bits/stdc++.h>
using namespace std;

string getKey(int x, int y) {
    return to_string(x) + "->" + to_string(y);
}
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_map<string, bool> map;
    for (auto& obstacle : obstacles) {
        map[getKey(obstacle[0], obstacle[1])] = true;
    }
                                // up, right, down, left
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> curr_pos = {0, 0};
    int ans = 0;
    int curr_dir = 0;

    for (int cmd : commands) {
        if (cmd == -1) {
            curr_dir = (curr_dir + 1) % 4;
            continue;
        }
        if (cmd == -2) {
            curr_dir = (curr_dir + 3) % 4;
            continue;
        }
        vector<int> dir = dirs[curr_dir];
        for (int i = 0; i < cmd; i++) {
            int x = curr_pos[0] + dir[0];
            int y = curr_pos[1] + dir[1];
            if (map[getKey(x, y)]) {
                break;
            }
            curr_pos[0] = x;
            curr_pos[1] = y;
        }

        ans = max(ans, curr_pos[0] * curr_pos[0] + curr_pos[1] * curr_pos[1]);
    }
    return ans;
}
int main(int argc, char const *argv[]) {
	vector<int> nums = {4,-1,3};
	vector<vector<int>> nums2 = {};
	cout<<robotSim(nums, nums2)<<endl;
	return 0;
}