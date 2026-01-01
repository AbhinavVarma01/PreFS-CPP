#include <bits/stdc++.h>
using namespace std;

// =============================================================================
// PROBLEM 1: Best Time to Buy and Sell Stock
// =============================================================================

/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing 
a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve 
any profit, return 0.

TEST CASES:
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

CONSTRAINTS:
- 1 <= prices.length <= 10^5
- 0 <= prices[i] <= 10^4
*/

// SOLUTION:
int maxProfit(vector<int>& prices) 
{   
    int max_profit = 0;
    int n = prices.size();
    int min_price = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}


// =============================================================================
// PROBLEM 2: Strobogrammatic Number
// =============================================================================

/*
QUESTION:
A strobogrammatic number is a number that looks the same when rotated 180 degrees 
(looked at upside down). For example, 69, 88, and 818 are strobogrammatic numbers.
Given a string num which represents an integer, return true if num is strobogrammatic, 
or false otherwise.

TEST CASES:
Example 1:
Input: num = "69"
Output: true
Explanation: When rotated 180 degrees, 69 becomes 69.

Example 2:
Input: num = "88"
Output: true

Example 3:
Input: num = "962"
Output: false

CONSTRAINTS:
- 1 <= num.length <= 50
- num consists of only digits
- Valid strobogrammatic digits: 0, 1, 8, 6, 9
- Mappings: 0→0, 1→1, 8→8, 6→9, 9→6
*/

// SOLUTION:
bool isStrobogrammatic(string &num) 
{
    string rotated = "";
    for(int i = num.size() - 1; i >= 0; i--) 
    {
        char c = num[i];
        if(c == '0' || c == '1' || c == '8') 
            rotated += c;
        else if(c == '6') 
            rotated += '9';
        else if(c == '9') 
            rotated += '6';
        else 
            return false; // invalid digit
    }
    return rotated == num;
}


// =============================================================================
// PROBLEM 3: Minimum Product Subset of an Array
// =============================================================================

/*
QUESTION:
Given an array a, you have to find the minimum product possible with a non-empty 
subset of elements present in the array. The minimum product can be a single element also.

TEST CASES:
Example 1:
Input: a[] = {-1, -1, -2, 4, 3}
Output: -24
Explanation: The minimum product will be (-2 * -1 * -1 * 4 * 3) = -24.

Example 2:
Input: a[] = {-1, 0, 2, 3}
Output: -6
Explanation: The minimum product is (-1 * 2 * 3) = -6.

Example 3:
Input: a[] = {5}
Output: 5

CONSTRAINTS:
- 1 <= n <= 20 (array length)
- -100 <= a[i] <= 100
- Approach: Generate all subsets using bitmasking
*/

// SOLUTION:
long long minimumProductSubset(vector<long long>& arr) 
{
    long long n = arr.size();
    long long minProduct = arr[0];

    for(long long mask = 1; mask < (1LL << n); mask++)
    {
        long long product = 1;
        for(long long i = 0; i < n; i++)
        {
            if(mask & (1 << i))
            {
                product *= arr[i];
            }
        }
        minProduct = min(minProduct, product);
    }
    return minProduct;
}


// =============================================================================
// PROBLEM 4: Classroom Attendance Tracker
// =============================================================================

/*
QUESTION:
A teacher keeps track of student names for each day of class. Some students attend 
multiple days, so their names appear multiple times in the attendance list.
Your task is to count how many times each student attended class and display the 
results in alphabetical order of names.

TEST CASES:
Example 1:
Input:
6
Alice Bob Alice Charlie Bob Alice
Output:
Alice:3
Bob:2
Charlie:1

Example 2:
Input:
5
David Eve David Eve Frank
Output:
David:2
Eve:2
Frank:1

CONSTRAINTS:
- 1 <= n <= 1000 (number of attendance entries)
- Each name consists of alphabetic characters
- Names are case-sensitive
*/

// SOLUTION:
void attendanceCounts() 
{
    int n;
    cin >> n;
    map<string, int> attendance;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        attendance[name]++;
    }
    for(auto &it : attendance)
    {
        cout << it.first << ":" << it.second << endl;
    }
}


// =============================================================================
// PROBLEM 5: Encrypted Staircase Problem (Recursion)
// =============================================================================

/*
QUESTION:
You are at the bottom of a staircase with n steps. You can climb 1 to m steps at a time.
Count the number of different ways you can reach the top of the staircase.

TEST CASES:
Example 1:
Input: n = 4, m = 2
Output: 5
Explanation: Ways are: [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2]

Example 2:
Input: n = 3, m = 3
Output: 4
Explanation: Ways are: [1,1,1], [1,2], [2,1], [3]

CONSTRAINTS:
- 1 <= n <= 30 (number of steps)
- 1 <= m <= 5 (maximum steps at a time)
- Use recursion to count ways
*/

// SOLUTION:
int countWaysRecursive(int n, int m) 
{
    if(n == 0) return 1;
    if(n < 0) return 0;

    int ways = 0;
    for(int i = 1; i <= m; i++) 
        ways += countWaysRecursive(n - i, m);
    
    return ways;
}


// =============================================================================
// PROBLEM 6: Lemonade Change
// =============================================================================

/*
QUESTION:
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy 
from you and order one at a time (in the order specified by bills). Each customer will 
only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the 
correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Return true if you can provide every customer with the correct change, or false otherwise.

TEST CASES:
Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
- From first 3 customers: collect three $5 bills
- From 4th customer: collect $10, give back $5
- From 5th customer: give $10 and $5

Example 2:
Input: bills = [5,5,10,10,20]
Output: false
Explanation: Cannot give $15 change for the last customer.

CONSTRAINTS:
- 1 <= bills.length <= 10^5
- bills[i] is either 5, 10, or 20
*/

// SOLUTION:
bool lemonadeChange(vector<int>& bills)
{
    int fives = 0;
    int tens = 0;
    int n = bills.size();
    
    for(int i = 0; i < n; i++)
    {
        if(bills[i] == 5) 
            fives++;
        else if(bills[i] == 10)
        {
            if(fives)
            {
                fives--;
                tens++;
            }
            else return false;
        }
        else // bills[i] == 20
        {
            if(tens && fives)
            {
                tens--;
                fives--;
            }
            else if(fives >= 3) 
                fives -= 3;
            else 
                return false;
        }
    }
    return true;
}


// =============================================================================
// PROBLEM 7: Smallest Common Element in All Rows
// =============================================================================

/*
QUESTION:
You are given an n x m matrix mat where each row is sorted in non-decreasing order.
Your task is to find the smallest common element in all rows. If there is no common 
element, return -1.

TEST CASES:
Example 1:
Input:
3 4
2 3 4 5
1 2 3 4
3 5 6 7
Output: 3
Explanation: 3 is the smallest common element in all rows.

Example 2:
Input:
2 3
1 2 3
4 5 6
Output: -1
Explanation: No common element exists.

Example 3:
Input:
4 5
1 5 9 13 17
3 5 7 11 19
5 6 8 10 12
2 4 5 14 18
Output: 5

CONSTRAINTS:
- 1 <= n, m <= 500
- 1 <= mat[i][j] <= 10^4
- Each row is sorted in non-decreasing order
*/

// SOLUTION:
int smallestCommonElement() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    unordered_map<int, int> freqmap;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            freqmap[matrix[i][j]]++;
        }
    }

    int result = INT_MAX;
    for(auto it : freqmap) 
    {
        if(it.second == n) 
        {
            result = min(result, it.first);
        }
    }

    if(result == INT_MAX) 
        return -1;
    else 
        return result;
}


// =============================================================================
// PROBLEM 8: Roman to Integer
// =============================================================================

/*
QUESTION:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol → Value: I=1, V=5, X=10, L=50, C=100, D=500, M=1000

Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. 
There are six instances where subtraction is used:
- I can be placed before V (5) and X (10) to make 4 and 9
- X can be placed before L (50) and C (100) to make 40 and 90
- C can be placed before D (500) and M (1000) to make 400 and 900

Given a roman numeral, convert it to an integer.

TEST CASES:
Example 1:
Input: s = "III"
Output: 3

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90, IV = 4

CONSTRAINTS:
- 1 <= s.length <= 15
- s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M')
- It is guaranteed that s is a valid roman numeral in the range [1, 3999]
*/

// SOLUTION:
int romanToInt(string s) 
{   
    map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int res = 0;
    for(int i = 0; i < s.size(); i++) 
    {
        if(i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]])
        {
            res -= roman[s[i]];
        }
        else 
            res += roman[s[i]];
    }
    return res;
}


// =============================================================================
// PROBLEM 9: Integer to Roman
// =============================================================================

/*
QUESTION:
Seven different symbols represent Roman numerals with the following values:
Symbol → Value: I=1, V=5, X=10, L=50, C=100, D=500, M=1000

Roman numerals are formed by appending conversions of decimal place values from 
highest to lowest. Subtractive forms used: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900.
Given an integer, convert it to a Roman numeral.

TEST CASES:
Example 1:
Input: num = 3749
Output: "MMMDCCXLIX"
Explanation: 3000=MMM, 700=DCC, 40=XL, 9=IX

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: 50=L, 8=VIII

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: 1000=M, 900=CM, 90=XC, 4=IV

CONSTRAINTS:
- 1 <= num <= 3999
*/

// SOLUTION:
string intToRoman(int num) 
{   
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string result = "";

    for(int i = 0; i < 13; i++) 
    {       
        while(num >= values[i]) 
        {        
            result += symbols[i];         
            num -= values[i];             
        }
    }
    return result;  
}


// =============================================================================
// PROBLEM 10: Reverse Words in a String
// =============================================================================

/*
QUESTION:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be 
separated by at least one space. Return a string of the words in reverse order 
concatenated by a single space.

TEST CASES:
Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: Multiple spaces between words should be reduced to a single space.

CONSTRAINTS:
- 1 <= s.length <= 10^4
- s contains English letters (upper-case and lower-case), digits, and spaces ' '
- There is at least one word in s
*/

// SOLUTION:
string reverseWords(string s) 
{
    stringstream ss(s);
    string word, result;
    while(ss >> word)
    {
        if(result.empty()) 
            result = word;
        else 
            result = word + " " + result;
    }
    return result;
}


// =============================================================================
// PROBLEM 11: Count Number of Homogenous Substrings
// =============================================================================

/*
QUESTION:
Given a string s, return the number of homogenous substrings of s. 
Since the answer may be too large, return it modulo 10^9 + 7.
A string is homogenous if all the characters of the string are the same.
A substring is a contiguous sequence of characters within a string.

TEST CASES:
Example 1:
Input: s = "abbcccaa"
Output: 13
Explanation: Homogenous substrings are:
"a" (3 times), "aa" (1 time), "b" (2 times), "bb" (1 time),
"c" (3 times), "cc" (2 times), "ccc" (1 time)
Total: 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13

Example 2:
Input: s = "xy"
Output: 2
Explanation: "x" and "y"

Example 3:
Input: s = "zzzzz"
Output: 15

CONSTRAINTS:
- 1 <= s.length <= 10^5
- s consists of lowercase letters
*/

// SOLUTION:
int countHomogenous(string s)
{
    long long ans = 0;
    long long count = 1;
    const int MOD = 1e9 + 7;

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i - 1]) 
            count++;
        else 
            count = 1;
        ans += count;
    }

    ans = ans % MOD;
    return ans + 1;
}


// =============================================================================
// PROBLEM 12: Minimum Cost to Connect Ropes
// =============================================================================

/*
QUESTION:
Given n ropes of different lengths, connect them into one rope. The cost to connect 
two ropes is equal to the sum of their lengths. Connect the ropes with minimum cost.

TEST CASES:
Example 1:
Input: sticks = [2, 4, 3]
Output: 14
Explanation: 
- Connect 2 and 3, cost = 5, remaining = [5, 4]
- Connect 5 and 4, cost = 9, remaining = [9]
- Total cost = 5 + 9 = 14

Example 2:
Input: sticks = [1, 8, 3, 5]
Output: 30
Explanation:
- Connect 1 and 3, cost = 4, remaining = [4, 8, 5]
- Connect 4 and 5, cost = 9, remaining = [9, 8]
- Connect 9 and 8, cost = 17, remaining = [17]
- Total cost = 4 + 9 + 17 = 30

CONSTRAINTS:
- 1 <= sticks.length <= 10^4
- 1 <= sticks[i] <= 10^4
*/

// SOLUTION:
int connectSticks(vector<int>& sticks) 
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(const int& stickLength : sticks) {
        minHeap.push(stickLength);
    }

    int totalCost = 0;

    while(minHeap.size() > 1) 
    {
        int firstSmallest = minHeap.top();
        minHeap.pop();

        int secondSmallest = minHeap.top();
        minHeap.pop();

        int combinedLength = firstSmallest + secondSmallest;
        totalCost += combinedLength;

        minHeap.push(combinedLength);
    }

    return totalCost;
}


// =============================================================================
// PROBLEM 13: Coin Change (Greedy)
// =============================================================================

/*
QUESTION:
You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

TEST CASES:
Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

CONSTRAINTS:
- 1 <= coins.length <= 12
- 1 <= coins[i] <= 2^31 - 1
- 0 <= amount <= 10^4
- Note: This is a greedy approach (may not always give optimal solution)
*/

// SOLUTION:
int coinChangeGreedy(vector<int>& coins, int amount) 
{
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    
    for(int coin : coins)
    {
        if(amount >= coin)
        {
            int use = amount / coin;
            count += use;
            amount = amount % coin;
        }
    }

    if(amount != 0) 
        return -1;
    else 
        return count;
}


// =============================================================================
// PROBLEM 14: Print Matrix Rows in Zig-Zag
// =============================================================================

/*
QUESTION:
Given an N×M matrix, print its rows in a zig-zag manner.
- Even indexed rows (0, 2, 4, ...) should be printed from right to left
- Odd indexed rows (1, 3, 5, ...) should be printed from left to right

TEST CASES:
Example 1:
Input:
3 3
1 2 3
4 5 6
7 8 9
Output: 3 2 1 4 5 6 9 8 7
Explanation:
1<-2<-3
|
4->5->6
|
7<-8<-9

Example 2:
Input:
2 4
1 2 3 4
5 6 7 8
Output: 4 3 2 1 5 6 7 8

CONSTRAINTS:
- 1 <= N, M <= 100
- 1 <= matrix[i][j] <= 1000
*/

// SOLUTION:
void zigzagPrint() 
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(i % 2 == 0) // even row - print right to left
        {
            for(int j = M - 1; j >= 0; j--) 
            {
                cout << matrix[i][j] << " ";
            }
        }
        else // odd row - print left to right
        {
            for(int j = 0; j < M; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }
}


// =============================================================================
// PROBLEM 15: Find the Winner of the Circular Game (Josephus Problem)
// =============================================================================

/*
QUESTION:
There are n friends playing a game. The friends are sitting in a circle and are 
numbered from 1 to n in clockwise order. The rules of the game are:
1. Start at the 1st friend
2. Count the next k friends in the clockwise direction including the friend you started at
3. The last friend you counted leaves the circle and loses the game
4. If there is still more than one friend, go back to step 2
5. The last friend in the circle wins the game

Given the number of friends n and an integer k, return the winner of the game.

TEST CASES:
Example 1:
Input: n = 5, k = 2
Output: 3
Explanation: Round 1: [1,2,3,4,5], 2 is out
Round 2: [1,3,4,5], 4 is out
Round 3: [1,3,5], 1 is out
Round 4: [3,5], 5 is out
Winner: 3

Example 2:
Input: n = 6, k = 5
Output: 1

CONSTRAINTS:
- 1 <= k <= n <= 500
*/

// SOLUTION:
int findWinner(int n, int k) 
{
    int winner = 0; // 0-indexed base case
    for(int i = 1; i <= n; i++) 
    {
        winner = (winner + k) % i;
    }
    return winner + 1; // convert to 1-indexed
}


// =============================================================================
// PROBLEM 16: Arranging Coins
// =============================================================================

/*
QUESTION:
You have n coins and you want to build a staircase with these coins. The staircase 
consists of k rows where the ith row has exactly i coins. The last row of the 
staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.

TEST CASES:
Example 1:
Input: n = 5
Output: 2
Explanation: 
Row 1: 1 coin
Row 2: 2 coins
Row 3: 2 coins (incomplete)
Complete rows = 2

Example 2:
Input: n = 8
Output: 3
Explanation:
Row 1: 1 coin
Row 2: 2 coins
Row 3: 3 coins
Row 4: 2 coins (incomplete)
Complete rows = 3

CONSTRAINTS:
- 1 <= n <= 2^31 - 1
- Formula: Total coins for k rows = k * (k + 1) / 2
*/

// SOLUTION:
long long arrangeCoins(long long n)
{   
    long long low = 0; 
    long long high = n;
    long long ans = 0;

    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long total_coins = mid * (mid + 1) / 2;
        
        if(total_coins == n) 
            return mid;
        else if(total_coins < n) 
        {
            ans = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return ans;
}


// =============================================================================
// PROBLEM 17: Merge Strings Alternately
// =============================================================================

/*
QUESTION:
You are given two strings word1 and word2. Merge the strings by adding letters in 
alternating order, starting with word1. If a string is longer than the other, append 
the additional letters onto the end of the merged string.
Return the merged string.

TEST CASES:
Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: word1:  a   b   c
             word2:    p   q   r
             merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"

CONSTRAINTS:
- 1 <= word1.length, word2.length <= 100
- word1 and word2 consist of lowercase English letters
*/

// SOLUTION:
string mergeAlternately(string word1, string word2)
{
    string ans = "";
    int n = word1.size();
    int m = word2.size();
    int i = 0;
    int j = 0;

    while(i < n && j < m)
    {
        ans += word1[i++];
        ans += word2[j++];
    }

    while(i < n) ans += word1[i++];
    while(j < m) ans += word2[j++];
    
    return ans;
}


// =============================================================================
// PROBLEM 18: Last Stone Weight
// =============================================================================

/*
QUESTION:
You are given an array of integers stones where stones[i] is the weight of the ith stone.
We are playing a game with the stones. On each turn, we choose the heaviest two stones 
and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. 
The result of this smash is:
- If x == y, both stones are destroyed
- If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x

At the end of the game, there is at most one stone left.
Return the weight of the last remaining stone. If there are no stones left, return 0.

TEST CASES:
Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
- Combine 7 and 8 → 1, array = [2,4,1,1,1]
- Combine 2 and 4 → 2, array = [2,1,1,1]
- Combine 2 and 1 → 1, array = [1,1,1]
- Combine 1 and 1 → 0, array = [1]
Result: 1

Example 2:
Input: stones = [1]
Output: 1

CONSTRAINTS:
- 1 <= stones.length <= 30
- 1 <= stones[i] <= 1000
*/

// SOLUTION:
int lastStoneWeight(vector<int>& stones) 
{   
    priority_queue<int> pq;
    for(int stone : stones) 
        pq.push(stone);
    
    while(pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();

        if(x != y) 
            pq.push(y - x);
    }
    
    if(pq.empty()) 
        return 0;
    else 
        return pq.top();
}


// =============================================================================
// PROBLEM 19: Koko Eating Bananas
// =============================================================================

/*
QUESTION:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile 
of bananas and eats k bananas from that pile. If the pile has less than k bananas, she 
eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the 
guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

TEST CASES:
Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

CONSTRAINTS:
- 1 <= piles.length <= 10^4
- piles.length <= h <= 10^9
- 1 <= piles[i] <= 10^9
*/

// SOLUTION:
long long totalHours(vector<int>& piles, long long h)
{
    long long hours = 0;
    long long n = piles.size();
    for(long long i = 0; i < n; i++)
    {
        hours += ceil((double)(piles[i]) / (double)(h));
    }
    return hours;
}

long long minEatingSpeed(vector<int>& piles, long long h) 
{   
    sort(piles.begin(), piles.end());
    long long n = piles.size();
    long long max_element = piles[n - 1];
    long long low = 1;
    long long high = max_element;
    
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long res = totalHours(piles, mid);
        
        if(res <= h) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return low;
}


// =============================================================================
// PROBLEM 20: Maximum Candies Allocated to K Children
// =============================================================================

/*
QUESTION:
You are given a 0-indexed integer array candies. Each element in the array denotes a 
pile of candies of size candies[i]. You can divide each pile into any number of sub piles, 
but you cannot merge two piles together.
You are also given an integer k. You should allocate piles of candies to k children such 
that each child gets the same number of candies. Each child can be allocated candies from 
only one pile of candies and some piles of candies may go unused.
Return the maximum number of candies each child can get.

TEST CASES:
Example 1:
Input: candies = [5,8,6], k = 3
Output: 5
Explanation: Divide candies[1] into [5,3], candies[2] into [5,1]. 
We now have [5,5,3,5,1]. Allocate three piles of size 5 to 3 children.

Example 2:
Input: candies = [2,5], k = 11
Output: 0
Explanation: Only 7 candies total, cannot give each of 11 children at least 1 candy.

CONSTRAINTS:
- 1 <= candies.length <= 10^5
- 1 <= candies[i] <= 10^7
- 1 <= k <= 10^12
*/

// SOLUTION:
bool canDistribute(vector<int>& candies, long long k, long long mid)
{
    long long count = 0;
    for(int c : candies)
    {
        count += c / mid;
    }
    return count >= k;
}

int maximumCandies(vector<int>& candies, long long k) 
{   
    long long low = 1;
    long long high = *max_element(candies.begin(), candies.end());
    long long ans = 0;
    
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        if(canDistribute(candies, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return ans;        
}


// =============================================================================
// PROBLEM 21: Longest Mountain in Array
// =============================================================================

/*
QUESTION:
An array arr is a mountain array if and only if:
- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
  * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray which is a mountain. 
Return 0 if there is no mountain subarray.

TEST CASES:
Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.

Example 3:
Input: arr = [0,1,2,3,4,5,4,3,2,1,0]
Output: 11

CONSTRAINTS:
- 1 <= arr.length <= 10^4
- 0 <= arr[i] <= 10^4
*/

// SOLUTION:
int longestMountain(vector<int>& arr)
{
    int n = arr.size();
    int longest_mountain = 0;
    
    for(int i = 1; i < n - 1; i++)
    {
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            int left = i;
            int right = i;

            while(left > 0 && arr[left - 1] < arr[left]) 
                left--;
            while(right < n - 1 && arr[right] > arr[right + 1]) 
                right++;

            longest_mountain = max(longest_mountain, right - left + 1);
        }
    }
    return longest_mountain;
}


// =============================================================================
// PROBLEM 22: Find the K-Beauty of a Number
// =============================================================================

/*
QUESTION:
The k-beauty of an integer num is defined as the number of substrings of num when it 
is read as a string that meet the following conditions:
- It has a length of k
- It is a divisor of num

Given integers num and k, return the k-beauty of num.
Note: Leading zeros are allowed. 0 is not a divisor of any value.

TEST CASES:
Example 1:
Input: num = 240, k = 2
Output: 2
Explanation: Substrings of length k:
- "24" from "240": 24 is a divisor of 240 ✓
- "40" from "240": 40 is a divisor of 240 ✓
k-beauty = 2

Example 2:
Input: num = 430043, k = 2
Output: 2
Explanation: Substrings: "43" (divisor), "30" (not), "00" (not), "04" (not), "43" (divisor)
k-beauty = 2

CONSTRAINTS:
- 1 <= num <= 10^9
- 1 <= k <= num.length (as a string)
*/

// SOLUTION:
int divisorSubstrings(int num, int k) 
{   
    string numStr = to_string(num);
    int n = numStr.size();
    int count = 0;

    for(int i = 0; i <= n - k; i++) 
    {
        string subStr = numStr.substr(i, k);   
        int val = stoi(subStr);                   
        if(val != 0 && num % val == 0) 
            count++; 
    }
 
    return count;
}


// =============================================================================
// PROBLEM 23: Baseball Game
// =============================================================================

/*
QUESTION:
You are keeping the scores for a baseball game with strange rules. At the beginning 
of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the ith operation 
you must apply to the record and is one of the following:
- An integer x: Record a new score of x
- '+': Record a new score that is the sum of the previous two scores
- 'D': Record a new score that is the double of the previous score
- 'C': Invalidate the previous score, removing it from the record

Return the sum of all the scores on the record after applying all the operations.

TEST CASES:
Example 1:
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" → [5]
"2" → [5, 2]
"C" → [5]
"D" → [5, 10]
"+" → [5, 10, 15]
Sum = 5 + 10 + 15 = 30

Example 2:
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27

Example 3:
Input: ops = ["1","C"]
Output: 0

CONSTRAINTS:
- 1 <= operations.length <= 1000
- operations[i] is "C", "D", "+", or a string representing an integer in range [-3*10^4, 3*10^4]
- For operation "+", there will always be at least two previous scores
- For operations "C" and "D", there will always be at least one previous score
*/

// SOLUTION:
int calPoints(vector<string>& operations) 
{   
    vector<int> res;
    int x = operations.size();

    for(int i = 0; i < x; i++)
    {
        if(operations[i] != "C" && operations[i] != "D" && operations[i] != "+")
        {
            int temp = stoi(operations[i]);
            res.push_back(temp);
        }
        else if(operations[i] == "+")
        {   
            int n = res.size();
            int sum = res[n - 1] + res[n - 2];
            res.push_back(sum);
        }
        else if(operations[i] == "C")
        {
            res.pop_back();
        }
        else if(operations[i] == "D")
        {   
            int n = res.size();
            int d_operation = 2 * res[n - 1];
            res.push_back(d_operation);
        }
    }

    int total_sum = accumulate(res.begin(), res.end(), 0);
    return total_sum;
}


// =============================================================================
// PROBLEM 24: Largest Number At Least Twice of Others
// =============================================================================

/*
QUESTION:
You are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much as 
every other number in the array. If it is, return the index of the largest element, 
or return -1 otherwise.

TEST CASES:
Example 1:
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer. For every other number x, 6 is at least twice 
as big as x. The index of value 6 is 1.

Example 2:
Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3.

Example 3:
Input: nums = [1]
Output: 0

CONSTRAINTS:
- 2 <= nums.length <= 50
- 0 <= nums[i] <= 100
- The largest element in nums is unique
*/

// SOLUTION:
int dominantIndex(vector<int>& nums)
{
    int n = nums.size();
    int max_index = 0;
    int max_val = nums[0];
    
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > max_val)
        {
            max_val = nums[i];
            max_index = i;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {   
        if(max_val >= 2 * nums[i]) 
            count++;
    }

    if(count == n - 1) 
        return max_index;
    else 
        return -1;
}













