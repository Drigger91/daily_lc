#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

long long maximumValueSum(const vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<pair<long long, int>>> res(m, vector<pair<long long, int>>(3, make_pair(-1e18, -1)));

    for (int j = 0; j < m; j++) {
        long long max1 = -1e18;
        long long max2 = -1e18;
        long long max3 = -1e18;
        int idx1 = -1, idx2 = -1, idx3 = -1;

        for (int i = 0; i < n; i++) {
            if (board[i][j] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = board[i][j];
                idx3 = idx2;
                idx2 = idx1;
                idx1 = i;
            } else if (board[i][j] > max2) {
                max3 = max2;
                max2 = board[i][j];
                idx3 = idx2;
                idx2 = i;
            } else if (board[i][j] > max3) {
                max3 = board[i][j];
                idx3 = i;
            }
        }
        res[j][0] = {max1, idx1};
        res[j][1] = {max2, idx2};
        res[j][2] = {max3, idx3};
    }

    long long maxSum = -1e18;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        for (int z = 0; z < 3; ++z) {
                            pair<long long, int> p1 = res[i][x];
                            pair<long long, int> p2 = res[j][y];
                            pair<long long, int> p3 = res[k][z];
                            if (p1.second != p2.second && p2.second != p3.second && p1.second != p3.second) {
                                maxSum = max(maxSum, p1.first + p2.first + p3.first);
                            }
                        }
                    }
                }
            }
        }
    }

    return maxSum;
}

int main() {
    vector<vector<int>> board = {
        {-23, 12, -7},
        {12, 18, -52},
        {98, 16, 70}
    };
    long long result = maximumValueSum(board);
    cout << "Maximum sum: " << result << endl;
    return 0;
}
