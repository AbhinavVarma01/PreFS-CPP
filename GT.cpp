/*1. Climbing Stairs*/

/* class Solution {
public:
    int func(int n, vector<int> &dp) {
        if(n==0 || n==1) return 1;
        if(dp[n]!= -1) return dp[n];
        return dp[n] = func(n-1,dp) + func(n-2, dp);
    }

    int climbStairs(int n){
        vector<int> dp(n+1, -1);
        return func(n,dp);
    }

};*/

// ============================================================================

/* 2. House Robber - I */

/*class Solution {
public:

    int func(int index, vector<int> &nums, vector<int> &dp){
        if(index>nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index] + func(index-2, nums, dp);
        int notpick = 0 + func(index-1, nums, dp);
        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return func(n-1, nums, dp);
    }
};*/

// ============================================================================

/* 3. House Robber - II */

/*
class Solution {
public:
    int func(int index, vector<int>& nums, vector<int> &dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick = nums[index] + func(index-2, nums, dp);
        int notpick = 0 + func(index-1, nums, dp);
        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> vct1(nums.begin()+1, nums.end());
        vector<int> vct2(nums.begin(), nums.end()-1);
        vector<int> dp1(vct1.size(), -1);
        vector<int> dp2(vct2.size(), -1);
        return max(func(vct1.size()-1,vct1,dp1), func(vct2.size()-1,vct2,dp2));
    }
};*/

// ============================================================================

/* 4. Coin Change */

/* class Solution{
	public:

	int MinimumCoins(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, 1e9);
		dp[0] = 0;
		for(int i=1; i<=amount; i++){
			for(int j=0; j<coins.size(); j++){
				if(coins[j]<=i){
				dp[i] = min(dp[i], 1+dp[i-coins[j]]);
			}
		}
	}
		if(dp[amount]>=1e9) return -1;
		return dp[amount];
    }
}; */

// ============================================================================

/* 5. Tribonacci Number */

/*class Solution {
public:
    int func(int n, vector<int> &dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = func(n-1,dp) + func(n-2,dp) + func(n-3,dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return func(n,dp);
    }
};*/

// ============================================================================

/* 6.Total unique paths in a grid */

/*class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = func(i-1, j, dp);
        int left = func(i, j-1, dp);
        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
};*/

// ============================================================================

/* 7. Minimum Cost Climbing Stairs */

/* class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
}; */

// ============================================================================

/* 8. Word Search */   
/* class Solution {
public:

    bool func(vector<vector<char>> &board, int i, int j, string s, int k){
        if(k==s.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=s[k]) return false;
        bool ans = false;
        char x = board[i][j];
        board[i][j]=' ';
        ans|= func(board, i+1, j, s, k+1);
        ans|= func(board, i-1, j, s, k+1);
        ans|= func(board, i, j+1, s, k+1);
        ans|= func(board, i, j-1, s, k+1);
        board[i][j] = x;
        return ans;

    }

    bool exist(vector<vector<char> >& board, string word) {
        //your code goes here
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(func(board, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};*/

// ============================================================================

/* 9. Letter Combinations of a Phone Number */
/* class Solution {
public:

    void func(int index, string digits, string s, vector<string> &ans, string combos[]){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }

        int digit = digits[index] - '0';

        for(int i=0; i<combos[digit].size(); i++){
            func(index+1, digits, s+combos[digit][i], ans, combos);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        func(0,digits, s, ans, combos);
        return ans;
    }
};*/