/*
 * You are given weights and values of N items, put these items in a knapsack of capacity W
 * to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
 * You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
 Input:
      N = 3
      W = 4
      values[] = {1,2,3}
      weight[] = {4,5,1}
Output: 3
 */

// Recursion with memoization
class Solution{
    public:

    int knapSackUtil(int W, int wt[], int val[], int n, int **dp)
    {
         if (W == 0 || n == 0) {
             return 0;
         }

         if (dp[n-1][W] != -1) {
             return dp[n-1][W];
         }

         if (wt[n-1] <= W) {
             return dp[n-1][W] = max(val[n-1] + knapSackUtil(W-wt[n-1], wt, val, n - 1, dp),
                                     knapSackUtil(W, wt, val, n - 1, dp));
         }
         else {
             return dp[n-1][W] = knapSackRec(W, wt, val, n - 1, dp);
         }
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        int **dp;
        dp = new int*[n];
        for (int it = 0; it < n; it++) {
            dp[it] = new int[W+1];
        }

        for (int it = 0; it < n; it++) {
            for (int j = 0; j < W+1; j++) {
                dp[it][j] = -1;
            }
        }

        return knapSackUtil(W, wt, val, n, dp);
    }
};

// With bottom up approach
class Solution{
    public:

    int knapSack(int W, int wt[], int val[], int n)
    {
        int dp[n+1][W+1];

        for (int c = 0; c < W+1; c++) {
            dp[0][c] = 0;
        }
        for (int r = 0; r < n+1; r++) {
            dp[r][0] = 0;
        }

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < W+1; j++) {
                if (wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][W];
    }
};
