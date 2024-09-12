#include<bits/stdc++.h>
using namespace std;

 bool isValid(vector<vector<int>>& grid, int row, int col) {
    vector<bool> vis(10, false);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = grid[row + i][col + j];
            if (num < 1 || num > 9) return false;
            if (vis[num]) return false;
            vis[num] = true;
        }
    }
    int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
    int diag2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
    if (diag1 != diag2) return false;
    int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
    int row2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
    int row3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];
    if (!(row1 == diag1 && row2 == diag1 && row3 == diag1)) {
        return false;
    }
    int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
    int col2 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
    int col3 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];
    if (!(col1 == diag1 && col2 == diag1 && col3 == diag1)) {
        return false;
    }
    return true;
}
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int row = 0; row < m - 2; row++) {
        for (int col = 0; col < n - 2; col++) {
            if (isValid(grid, row, col)) {
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	vector<vector<int>> check = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
	int ans = numMagicSquaresInside(check);
	cout<<"Ans is : " << ans << endl;
	return 0;
}