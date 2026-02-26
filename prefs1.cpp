#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// 1. LARGEST NUMBER AT LEAST TWICE OF OTHERS
// ============================================================================
/*
QUESTION:
You are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much 
as every other number in the array. If it is, return the index of the largest 
element, or return -1 otherwise.

TEST CASES:
Example 1:
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer. For every other number in the array x, 
6 is at least twice as big as x. The index of value 6 is 1.

Example 2:
Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.

CONSTRAINTS:
- 2 <= nums.length <= 50
- 0 <= nums[i] <= 100
- The largest element in nums is unique
*/

// SOLUTION:
int dominantIndex(vector<int>& nums) {
    int n = nums.size();
    int maxVal = nums[0];
    int maxIndex = 0;
    
    // Find the largest element and its index
    for (int i = 0; i < n; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIndex = i;
        }
    }
    
    // Check if largest is at least twice all others
    for (int i = 0; i < n; i++) {
        if (i != maxIndex) {
            if (maxVal < 2 * nums[i]) {
                return -1;
            }
        }
    }
    
    return maxIndex;
}

// ============================================================================
// 2. BASEBALL GAME
// ============================================================================
/*
QUESTION:
You are keeping the scores for a baseball game with strange rules. 
At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith 
operation you must apply to the record and is one of the following:
- An integer x: Record a new score of x.
- '+': Record a new score that is the sum of the previous two scores.
- 'D': Record a new score that is the double of the previous score.
- 'C': Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.

TEST CASES:
Example 1:
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27

Example 3:
Input: ops = ["1","C"]
Output: 0
Explanation: After removing the score, the record is empty, so total sum is 0.

CONSTRAINTS:
- 1 <= operations.length <= 1000
- For operation "+", there will always be at least two previous scores.
- For operations "C" and "D", there will always be at least one previous score.
*/

// SOLUTION:
int calPoints(vector<string>& ops) {
    vector<int> record;
    
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == "C") {
            record.pop_back();
        }
        else if (ops[i] == "D") {
            int last = record[record.size() - 1];
            record.push_back(2 * last);
        }
        else if (ops[i] == "+") {
            int n = record.size();
            int sum = record[n - 1] + record[n - 2];
            record.push_back(sum);
        }
        else {
            record.push_back(stoi(ops[i]));
        }
    }
    
    return accumulate(record.begin(), record.end(), 0);
}

// ============================================================================
// 3. K-BEAUTY OF A NUMBER
// ============================================================================
/*
QUESTION:
The k-beauty of an integer num is defined as the number of substrings of num 
when it is read as a string that meet the following conditions:
- It has a length of k.
- It is a divisor of num.

Given integers num and k, return the k-beauty of num.

Note: Leading zeros are allowed. 0 is not a divisor of any value.

TEST CASES:
Example 1:
Input: num = 240, k = 2
Output: 2
Explanation: The substrings of 240 of length 2 are:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.

Example 2:
Input: num = 430043, k = 2
Output: 2
Explanation: The substrings with length 2 that are divisors: "43" and "43".

CONSTRAINTS:
- 1 <= num <= 10^9
- 1 <= k <= num.length
*/

// SOLUTION:
int divisorSubstrings(int num, int k) {
    string s = to_string(num);
    int n = s.size();
    int count = 0;
    
    for (int i = 0; i <= n - k; i++) {
        string substring = s.substr(i, k);
        int value = stoi(substring);
        
        if (value != 0 && num % value == 0) {
            count++;
        }
    }
    
    return count;
}

// ============================================================================
// 4. KOKO EATING BANANAS
// ============================================================================
/*
QUESTION:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has 
piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses 
some pile of bananas and eats k bananas from that pile. If the pile has less 
than k bananas, she eats all of them instead and will not eat any more bananas 
during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas 
before the guards return. Return the minimum integer k such that she can eat 
all the bananas within h hours.

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
long long calculateHours(vector<int>& piles, long long speed) {
    long long totalHours = 0;
    for (int i = 0; i < piles.size(); i++) {
        totalHours += (piles[i] + speed - 1) / speed; // Ceiling division
    }
    return totalHours;
}

long long minEatingSpeed(vector<int>& piles, long long h) {
    long long left = 1;
    long long right = *max_element(piles.begin(), piles.end());
    
    long long answer = right;
    
    // Binary search for minimum speed
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long hours = calculateHours(piles, mid);
        
        if (hours <= h) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}

// ============================================================================
// 5. REVERSE WORDS IN A STRING
// ============================================================================
/*
QUESTION:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

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
Explanation: Multiple spaces between words should be reduced to single space.

CONSTRAINTS:
- 1 <= s.length <= 10^4
- s contains English letters, digits, and spaces
*/

// SOLUTION:
string reverseWords(string s) {
    stringstream ss(s);
    string word;
    string result = "";
    
    while (ss >> word) {
        if (result == "") {
            result = word;
        } else {
            result = word + " " + result;
        }
    }
    
    return result;
}

// ============================================================================
// 6. COUNT NUMBER OF HOMOGENOUS SUBSTRINGS
// ============================================================================
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
Explanation: The homogenous substrings are:
"a" appears 3 times, "aa" appears 1 time
"b" appears 2 times, "bb" appears 1 time
"c" appears 3 times, "cc" appears 2 times, "ccc" appears 1 time
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13

Example 2:
Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".

Example 3:
Input: s = "zzzzz"
Output: 15

CONSTRAINTS:
- 1 <= s.length <= 10^5
- s consists of lowercase letters
*/

// SOLUTION:
long long countHomogenous(string s) {
    long long MOD = 1000000007;
    long long total = 0;
    long long count = 1;
    
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        total = (total + count) % MOD;
    }
    
    // Add 1 for the first character
    return (total + 1) % MOD;
}

// ============================================================================
// 7. MINIMUM COST TO CONNECT ROPES
// ============================================================================
/*
QUESTION:
You have some number of sticks with positive integer lengths. These lengths are 
given as an array sticks where sticks[i] is the length of the ith stick.

You can connect any two sticks of lengths x and y into one stick by paying a 
cost of x + y. You must connect all the sticks until there is only one stick 
remaining. Return the minimum cost of connecting all the given sticks into one 
stick in this way.

TEST CASES:
Example 1:
Input: sticks = [2,4,3]
Output: 14
Explanation: Connect 2 and 3 for cost 5. Connect 5 and 4 for cost 9. 
Total cost is 5 + 9 = 14.

Example 2:
Input: sticks = [1,8,3,5]
Output: 30
Explanation: Connect 1 and 3 (cost 4), then 4 and 5 (cost 9), 
then 8 and 9 (cost 17). Total cost = 4 + 9 + 17 = 30.

CONSTRAINTS:
- 1 <= sticks.length <= 10^4
- 1 <= sticks[i] <= 10^4
*/

// SOLUTION:
long long connectSticks(vector<int>& sticks) {
    // Use min heap to always get smallest two sticks
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    
    // Add all sticks to heap
    for (int i = 0; i < sticks.size(); i++) {
        minHeap.push(sticks[i]);
    }
    
    long long totalCost = 0;
    
    // Keep connecting until one stick remains
    while (minHeap.size() > 1) {
        long long first = minHeap.top();
        minHeap.pop();
        
        long long second = minHeap.top();
        minHeap.pop();
        
        long long cost = first + second;
        totalCost += cost;
        
        minHeap.push(cost);
    }
    
    return totalCost;
}

// ============================================================================
// 8. COIN CHANGE (GREEDY VARIANT)
// ============================================================================
/*
QUESTION:
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, 
return -1.

You may assume that you have an infinite number of each kind of coin.

NOTE: This greedy solution works for canonical coin systems (like US coins) 
but may not work for all coin combinations. For a general solution, use DP.

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
*/

// SOLUTION (Greedy - works for canonical coin systems):
long long coinChangeGreedy(vector<int>& coins, int amount) {
    // Sort coins in descending order (largest first)
    sort(coins.begin(), coins.end(), greater<int>());
    
    long long coinCount = 0;
    
    for (int i = 0; i < coins.size(); i++) {
        if (amount == 0) break;
        
        int numCoins = amount / coins[i];
        coinCount += numCoins;
        amount = amount % coins[i];
    }
    
    if (amount != 0) {
        return -1; // Cannot make exact change
    }
    
    return coinCount;
}

// ============================================================================
// 9. PRINT MATRIX ROWS (ZIG-ZAG)
// ============================================================================
/*
QUESTION:
Given an N×N matrix, print its rows in a zig-zag pattern.
Even-indexed rows (0, 2, 4...) are printed right to left.
Odd-indexed rows (1, 3, 5...) are printed left to right.

TEST CASES:
Example 1:
Input: matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
Output: [3, 2, 1, 4, 5, 6, 9, 8, 7]
Explanation:
1<-2<-3
|
4->5->6
|
7<-8<-9

CONSTRAINTS:
- 1 <= N, M <= 1000
- -10^9 <= matrix[i][j] <= 10^9
*/

// SOLUTION:
vector<int> zigzagPrint(vector<vector<int>>& matrix) {
    vector<int> result;
    int n = matrix.size();
    if (n == 0) return result;
    
    int m = matrix[0].size();
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Even row: print right to left
            for (int j = m - 1; j >= 0; j--) {
                result.push_back(matrix[i][j]);
            }
        } else {
            // Odd row: print left to right
            for (int j = 0; j < m; j++) {
                result.push_back(matrix[i][j]);
            }
        }
    }
    
    return result;
}

// ============================================================================
// 10. FIND THE WINNER OF THE CIRCULAR GAME (JOSEPHUS PROBLEM)
// ============================================================================
/*
QUESTION:
There are n friends sitting in a circle numbered from 1 to n. 
The game rules:
1. Start at the 1st friend.
2. Count the next k friends clockwise (including the start friend).
3. The last friend counted leaves the circle.
4. Repeat from the next friend clockwise until one friend remains.

Return the winner of the game (1-indexed).

TEST CASES:
Example 1:
Input: n = 5, k = 2
Output: 3
Explanation: Friends leave in order: 2, 4, 1, 5. Winner is 3.

Example 2:
Input: n = 6, k = 5
Output: 1

CONSTRAINTS:
- 1 <= k <= n <= 500
*/

// SOLUTION (Josephus formula):
int findWinner(int n, int k) {
    int position = 0; // Start at position 0 (0-indexed)
    
    for (int i = 1; i <= n; i++) {
        position = (position + k) % i;
    }
    
    return position + 1; // Convert to 1-indexed
}

// ============================================================================
// 11. CLASSROOM ATTENDANCE TRACKER
// ============================================================================
/*
QUESTION:
A teacher keeps track of student names for each day of class. Some students 
attend multiple days, so their names appear multiple times in the attendance list.

Your task is to count how many times each student attended class and display 
the results in alphabetical order of names.

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
- 1 <= n <= 1000
- Names are strings of English letters
*/

// SOLUTION:
map<string, int> attendanceCounts(vector<string>& names) {
    map<string, int> attendance;
    
    for (int i = 0; i < names.size(); i++) {
        attendance[names[i]]++;
    }
    
    return attendance;
}

// ============================================================================
// 12. ENCRYPTED STAIRCASE PROBLEM
// ============================================================================
/*
QUESTION:
In an ancient temple, there's a mystical staircase with n steps. A codebreaker 
needs to reach the top of the staircase by making jumps of at most m steps at a time.

From any step, they can move to the next 1, 2, ..., up to m steps ahead.

Return the total number of distinct ways the codebreaker can climb from step 0 
to step n.

TEST CASES:
Example 1:
Input: n = 4, m = 2
Output: 5
Explanation: The codebreaker can jump in these 5 ways:
1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2

Example 2:
Input: n = 3, m = 3
Output: 4
Explanation:
1 + 1 + 1
1 + 2
2 + 1
3

CONSTRAINTS:
- 1 <= n <= 30
- 1 <= m <= n
*/

// SOLUTION (Recursive):
int countWaysRecursive(int n, int m) {
    // Base cases
    if (n == 0) return 1; // One way to stay at step 0
    if (n < 0) return 0;  // No way if we go below 0
    
    int totalWays = 0;
    
    // Try all possible jumps from 1 to m
    for (int jump = 1; jump <= m; jump++) {
        totalWays += countWaysRecursive(n - jump, m);
    }
    
    return totalWays;
}

// ============================================================================
// 13. LEMONADE CHANGE
// ============================================================================
/*
QUESTION:
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue 
to buy from you and order one at a time. Each customer will only buy one lemonade 
and pay with either a $5, $10, or $20 bill. You must provide the correct change 
to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, 
return true if you can provide every customer with the correct change, or false 
otherwise.

TEST CASES:
Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills.
From the 4th customer, we collect a $10 bill and give back a $5.
From the 5th customer, we give a $10 bill and a $5 bill.

Example 2:
Input: bills = [5,5,10,10,20]
Output: false
Explanation: For the last customer, we cannot give the change of $15.

CONSTRAINTS:
- 1 <= bills.length <= 10^5
- bills[i] is either 5, 10, or 20
*/

// SOLUTION:
bool lemonadeChange(vector<int>& bills) {
    int fives = 0;
    int tens = 0;
    
    for (int i = 0; i < bills.size(); i++) {
        if (bills[i] == 5) {
            fives++;
        }
        else if (bills[i] == 10) {
            if (fives == 0) return false;
            fives--;
            tens++;
        }
        else { // bills[i] == 20
            // Try to give 1 ten and 1 five
            if (tens > 0 && fives > 0) {
                tens--;
                fives--;
            }
            // Otherwise give 3 fives
            else if (fives >= 3) {
                fives -= 3;
            }
            else {
                return false;
            }
        }
    }
    
    return true;
}

// ============================================================================
// 14. SMALLEST COMMON ELEMENT IN ALL ROWS
// ============================================================================
/*
QUESTION:
You are given an n x m matrix mat where each row is sorted in non-decreasing order.
Your task is to find the smallest common element in all rows. 
If there is no common element, return -1.

TEST CASES:
Example 1:
Input: mat = [
  [2,3,4],
  [1,2,3,4],
  [3,5,6,7]
]
Output: 3
Explanation: The number 3 is the smallest common element in all rows.

Example 2:
Input: mat = [
  [1,2,3],
  [4,5,6]
]
Output: -1
Explanation: There is no common element in all rows.

Example 3:
Input: mat = [
  [1,5,9,13,17],
  [3,5,7,11,19],
  [5,6,8,10,12],
  [2,4,5,14,18]
]
Output: 5
Explanation: The number 5 is the only element present in all four rows.

CONSTRAINTS:
- 1 <= n, m <= 500
- 1 <= mat[i][j] <= 10^4
- Each row is sorted in non-decreasing order
*/

// SOLUTION:
int smallestCommonElement(vector<vector<int>>& mat) {
    unordered_map<int, int> frequency;
    int n = mat.size();
    
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            frequency[mat[i][j]]++;
        }
    }
    
    int smallest = INT_MAX;
    
    // Find smallest element that appears in all rows
    for (auto it : frequency) {
        if (it.second == n) {
            smallest = min(smallest, it.first);
        }
    }
    
    if (smallest == INT_MAX) {
        return -1;
    }
    
    return smallest;
}

// ============================================================================
// 15. LONGEST MOUNTAIN IN ARRAY
// ============================================================================
/*
QUESTION:
You may recall that an array arr is a mountain array if and only if:
- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
  arr[0] < arr[1] < ... < arr[i-1] < arr[i]
  arr[i] > arr[i+1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray which is 
a mountain. Return 0 if there is no mountain subarray.

TEST CASES:
Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.

CONSTRAINTS:
- 1 <= arr.length <= 10^4
- 0 <= arr[i] <= 10^4
*/

// SOLUTION:
int longestMountain(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0;
    
    int maxLength = 0;
    
    // Check each position as potential peak
    for (int i = 1; i < n - 1; i++) {
        // Check if current position is a peak
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            int left = i;
            int right = i;
            
            // Expand left while increasing
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }
            
            // Expand right while decreasing
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }
            
            int length = right - left + 1;
            maxLength = max(maxLength, length);
        }
    }
    
    return maxLength;
}

// ============================================================================
// 16. ARRANGING COINS
// ============================================================================
/*
QUESTION:
You have n coins and you want to build a staircase with these coins. 
The staircase consists of k rows where the ith row has exactly i coins. 
The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

TEST CASES:
Example 1:
Input: n = 5
Output: 2
Explanation: 
Row 1: 1 coin
Row 2: 2 coins
Row 3 is incomplete (only 2 coins available), we return 2.

Example 2:
Input: n = 8
Output: 3
Explanation: 
Row 1: 1 coin
Row 2: 2 coins
Row 3: 3 coins
Row 4 is incomplete (only 2 coins available), we return 3.

CONSTRAINTS:
- 1 <= n <= 2^31 - 1
*/

// SOLUTION (Binary Search):
long long arrangeCoins(long long n) {
    long long left = 0;
    long long right = n;
    long long result = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long coinsNeeded = mid * (mid + 1) / 2;
        
        if (coinsNeeded <= n) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

// ============================================================================
// 17. MERGE STRINGS ALTERNATELY
// ============================================================================
/*
QUESTION:
You are given two strings word1 and word2. Merge the strings by adding letters 
in alternating order, starting with word1. If a string is longer than the other, 
append the additional letters onto the end of the merged string.

Return the merged string.

TEST CASES:
Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: 
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.

CONSTRAINTS:
- 1 <= word1.length, word2.length <= 100
- word1 and word2 consist of lowercase English letters
*/

// SOLUTION:
string mergeAlternately(string word1, string word2) {
    string result = "";
    int i = 0;
    int j = 0;
    
    // Add characters alternately while both strings have characters
    while (i < word1.size() && j < word2.size()) {
        result += word1[i];
        result += word2[j];
        i++;
        j++;
    }
    
    // Add remaining characters from word1
    while (i < word1.size()) {
        result += word1[i];
        i++;
    }
    
    // Add remaining characters from word2
    while (j < word2.size()) {
        result += word2[j];
        j++;
    }
    
    return result;
}

// ============================================================================
// 18. LAST STONE WEIGHT
// ============================================================================
/*
QUESTION:
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two 
stones and smash them together. Suppose the heaviest two stones have weights x 
and y with x <= y. The result of this smash is:
- If x == y, both stones are destroyed.
- If x != y, the stone of weight x is destroyed, and the stone of weight y has 
  new weight y - x.

At the end of the game, there is at most one stone left.
Return the weight of the last remaining stone. If there are no stones left, return 0.

TEST CASES:
Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1, array converts to [2,4,1,1,1]
We combine 2 and 4 to get 2, array converts to [2,1,1,1]
We combine 2 and 1 to get 1, array converts to [1,1,1]
We combine 1 and 1 to get 0, array converts to [1]
Final stone weight is 1.

Example 2:
Input: stones = [1]
Output: 1

CONSTRAINTS:
- 1 <= stones.length <= 30
- 1 <= stones[i] <= 1000
*/

// SOLUTION:
int lastStoneWeight(vector<int>& stones) {
    // Use max heap to get heaviest stones
    priority_queue<int> maxHeap;
    
    // Add all stones to heap
    for (int i = 0; i < stones.size(); i++) {
        maxHeap.push(stones[i]);
    }
    
    // Keep smashing until one or zero stones remain
    while (maxHeap.size() > 1) {
        int first = maxHeap.top();
        maxHeap.pop();
        
        int second = maxHeap.top();
        maxHeap.pop();
        
        if (first != second) {
            maxHeap.push(first - second);
        }
    }
    
    if (maxHeap.empty()) {
        return 0;
    }
    
    return maxHeap.top();
}

// ============================================================================
// 19. MAXIMUM CANDIES ALLOCATED TO K CHILDREN
// ============================================================================
/*
QUESTION:
You are given a 0-indexed integer array candies. Each element in the array denotes 
a pile of candies of size candies[i]. You can divide each pile into any number of 
sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children 
such that each child gets the same number of candies. Each child can be allocated 
candies from only one pile.

Return the maximum number of candies each child can get.

TEST CASES:
Example 1:
Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] 
into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, 
and 1. We can allocate the 3 piles of size 5 to 3 children.

Example 2:
Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible 
to ensure each child receives at least one candy.

CONSTRAINTS:
- 1 <= candies.length <= 10^5
- 1 <= candies[i] <= 10^7
- 1 <= k <= 10^12
*/

// SOLUTION (Binary Search):
bool canGiveCandiesToAll(vector<int>& candies, long long k, long long candiesPerChild) {
    long long childCount = 0;
    
    for (int i = 0; i < candies.size(); i++) {
        childCount += candies[i] / candiesPerChild;
    }
    
    return childCount >= k;
}

long long maximumCandies(vector<int>& candies, long long k) {
    long long left = 1;
    long long right = *max_element(candies.begin(), candies.end());
    
    long long answer = 0;
    
    // Binary search for maximum candies per child
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canGiveCandiesToAll(candies, k, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}

// ============================================================================
// END OF FILE
// ============================================================================





