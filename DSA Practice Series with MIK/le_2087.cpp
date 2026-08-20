class Solution {
public:
    // This code is not submitted gives TLE bcz of tight constraints so always
    // look at the constraints during contest time and OA round as the m*n is
    // O(10^10) so we cannot traverse all the cells of the matrices by simply
    // applying DFS solution in all the four directions

    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int sr = startPos[0];
        int sc = startPos[1];
        int er = homePos[0];
        int ec = homePos[1];
        int minCost = 0;
        if (er >= sr) {
            for (int r = sr + 1; r <= er; r++) {
                minCost += rowCosts[r];
            }
        } else {
            for (int r = sr - 1; r >= er; r--) {
                minCost += rowCosts[r];
            }
        }
        if (ec >= sc) {
            for (int c = sc + 1; c <= ec; c++) {
                minCost += colCosts[c];
            }
        } else {
            for (int c = sc - 1; c >=ec ; c--) {
                minCost += colCosts[c];
            }
        }
        return minCost;
    }
};