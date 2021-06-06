/*
      Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
      Output: True
      There is a subset (4, 5) with sum 9.
*/

// Recursion
class SubsetSum
{
	public:
	bool isSubsetSum(int *set, int n, int sum) {
		if (sum == 0)
			return true;
		if (n == 0)
			return false;

		if (set[n-1] <= sum) {
			return isSubsetSum(set, n-1, sum - set[n-1]) ||
				   isSubsetSum(set, n-1, sum);
		}
		else {
			return isSubsetSum(set, n-1, sum);
		}
	}
};

// Recursion with memoization
class SubsetSum
{
	public:
	int isSubsetSumUtil(int *set, int n, int sum, int **dp) {
		if (sum == 0)
			return 1;
		if (n == 0)
			return 0;

		if (dp[n-1][sum] != -1)
			return dp[n-1][sum];

		if (set[n-1] <= sum) {
			return dp[n-1][sum] = isSubsetSumUtil(set, n-1, sum - set[n-1], dp) ||
								  isSubsetSumUtil(set, n-1, sum, dp);
		}
		else {
			return dp[n-1][sum] = isSubsetSumUtil(set, n-1, sum, dp);
		}
	}

	int isSubsetSum(int *set, int n, int sum) {
		int **dp;
		dp = new int*[n];
		for (int it = 0; it < n; it++) {
			dp[it] = new int[sum + 1];
		}

		for (int it = 0; it < n; it++) {
            for (int j = 0; j < sum + 1; j++) {
                dp[it][j] = -1;
            }
        }

        return isSubsetSumUtil(set, n, sum, dp);
	}
};

// With bottom up approach
