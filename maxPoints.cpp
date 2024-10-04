#include<bits/stdc++.h>
using namespace std;

int getCol(int row, int col, int i) {
    return row == 0 ? i : col;
}
long long helper(vector<vector<int>>& mat, int row, long long curr_sum, int col) {
    if (row >= mat.size()) {
        return curr_sum;
    }
    
    long long row_ans = 0;
    for (int i = 0; i < mat[0].size(); i++) {
        long long value = curr_sum + mat[row][i] - (row == 0 ? 0 : abs(i - col));
        long long helperAns = helper(mat, row + 1, value, i);
        if (helperAns > row_ans) {
            row_ans = max(row_ans, helperAns);
        }
        
    }
    return row_ans;
}
long long maxPoints(vector<vector<int>>& points) {
    int rows = points.size(), cols = points[0].size();
    vector<long long> previousRow(cols);
    for (int col = 0; col < cols; col++) {
        previousRow[col] = points[0][col];
    }
    for (int row = 0; row < rows - 1; row++) {
        vector<long long> leftMax(cols);
        vector<long long> rightMax(cols);
        vector<long long> currentRow(cols);
        leftMax[0] = previousRow[0];
        for (int col = 1; col < cols; col++) {
            leftMax[col] = max(leftMax[col - 1] - 1, previousRow[col]);
        }
        rightMax[cols - 1] = previousRow[cols - 1];
        for (int col = cols - 2; col >= 0; --col) {
            rightMax[col] = max(rightMax[col + 1] - 1, previousRow[col]);
        }
        for (int col = 0; col < cols; col++) {
            currentRow[col] =
                points[row + 1][col] + max(leftMax[col], rightMax[col]);
        }
        previousRow = currentRow;
    }
    long long maxPoints = 0;
    for (int col = 0; col < cols; col++) {
        maxPoints = max(maxPoints, previousRow[col]);
    }
    return maxPoints;
}


int main(int argc, char const *argv[]) {
    /* 0*/
    vector<vector<int>> mat =  {{1,2,3},{1,5,1},{3,1,1}};

    long long ans = maxPoints(mat);
    cout << "Ans is : " <<ans<<endl;
    return 0;
}
