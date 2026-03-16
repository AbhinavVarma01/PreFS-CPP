/* 1. Question: Given a string of parentheses, find the minimum number of deletions required to make the 
parentheses balanced. 
(e.g., Input: "()((())" → Output: 1)
Company: DBS Round: Online Assessment (HackerEarth)
Topic: Stack / String Difficulty: Medium Source: GeeksforGeeks — DBS Hack2Hire Interview Experience 
(Tech Associate) 

int ans(string &s){
    stack<char> st;
    for(char c : s){
        if(c == '(') st.push(c);
        else{
            if(!st.empty() && st.top()=='(') st.pop();
            else st.push(c);
        }
    }
    return st.size();
}

int ans1(string &s){
    if(s.empty()) return 0;
    int open = 0;
    int close = 0;
    for(char c : s){
        if(c=='(') open++;
        else{
            if(open>0) open--;
            else close++;
        }
    }
    return open + close;
}

*/ 


/* 2. Question: Given an array of numbers, arrange them to form the largest possible number by concatenating
all elements. (e.g., [3, 30, 34, 5, 9] → "9534330") Company: DBS Round: Online Assessment (HackerEarth) 
Topic: Array / Sorting / Greedy Difficulty: Medium Source: GeeksforGeeks — DBS Hack2Hire Interview Experience 
(Tech Associate)

class Solution {
public:

    static bool cmp(string a, string b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int x : nums){
            arr.push_back(to_string(x));
        }

        sort(arr.begin(), arr.end(), cmp);

        if(arr[0]=="0") return "0";

        string res = "";
        for(string s : arr){
            res = res+s;
        }
        return res;
    }
};*/


/* 3. Question: Find the missing number in an array of size N containing numbers from 1 to N 
with one number missing. Company: DBS Round: Technical Round Topic: Array / Math Difficulty: 
Easy Source: GeeksforGeeks — DBS Recruitment Process, Questions Asked in DBS section

class Solution {
public:
    int missingNumber(vector<int>& nums){
        int n = nums.size();
        int sum = n * (n+1)/ 2;
        int exp = accumulate(nums.begin(), nums.end(), 0);
        return sum - exp;
    }
}; */


/* 4. Question: Sort an array containing only 0s and 1s in a single pass (Dutch National Flag variant). 
Company: DBS Round: Online Assessment / Written Test Topic: Array / Two Pointers Difficulty: 
Easy Source: Glassdoor — DBS Bank Java Developer Interview, candidate reported: "Sort an array of 0 and 1"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        for(int right=0; right<n; right++){
            if(nums[right]!=0){
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid]==1) mid++;

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
}; */


/*5: Two Sum: 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++){
            int num = nums[i];
            int needed = target - num;
            
            if(mpp.find(needed)!= mpp.end()){
                return {mpp[needed], i};
            }

            mpp[num] = i;
        }
        return {-1,-1};
    }
};

ALL PAIRS - 
vector<pair<int,int>> allPairs(vector<int>& arr, int target) {

    unordered_set<int> st;
    vector<pair<int,int>> ans;

    for(int x : arr) {
        int need = target - x;

        if(st.count(need)) {
            ans.push_back({need, x});
        }
        st.insert(x);
    }

    return ans;
}

*/

/* 6. Binary Search:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1 ;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(target>nums[mid]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
    }
}; */

/* 7. Question: Given a string, find the first repeated character. (e.g., "Hyderabad" → 'd') 
Company: DBS Round: Technical Round (F2F) Topic: String / Hashing Difficulty:
Easy Source: Glassdoor — DBS Bank Java Developer Interview, candidate reported this exact problem
 
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

char firstRepeated(string s) {

    unordered_set<char> st;

    for(char c : s) {
        if(st.find(c) != st.end()) {
            return c;
        }
        st.insert(c);
    }

    return '#';   // if no repeated character
}

int main() {
    string s;
    cin >> s;
    cout << firstRepeated(s);
}
*/

/* 8. Question: Check whether string B is a rotation of string A. (e.g., "abcde" and "cdeab" → true) 
Company: DBS Round: Technical Round Topic: String Difficulty: Easy
Source: Glassdoor — Deutsche Bank / DBS technical round, candidate reported: "Check string 2 is rotation of string 1 or not"

#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;
    string doubleStr = s + s;
    return doubleStr.find(goal) != string::npos; 
}

int main(){
    string s; cin>>s;
    string goal; cin>>goal;
    cout<<rotateString(s,goal);
}*/


/* 9. Question: Given a number, repeatedly add its digits until you get a single digit. 
(Digital root / repeated digit sum problem) Company: DBS
Round: Technical Round Topic: Math / Recursion Difficulty: Easy
Source: Glassdoor — DBS technical round, 
candidate reported: "Convert number in single digit by adding digits of number until get single digit"

class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int sum = 0;
            while(num>0){
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        }
        return num;
    }

    if(num==0) return 0;
    else return 1 + (num - 1) % 9;
}
};
*/

/* 10. Level Order
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};*/

/* 11. Rotate String:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        std::rotate(nums.begin(), nums.end()-k, nums.end());
    }
};
*/


/* 12. Second Largest 
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {

    int first = INT_MIN;
    int second = INT_MIN;

    for(int x : arr) {
        if(x > first) {
            second = first;
            first = x;
        }
        else if(x > second && x != first) {
            second = x;
        }
    }

    return second;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    cout << secondLargest(arr);
}*/

/*13. SubString Search
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i<=n-m; i++){
            string sub = haystack.substr(i, m);
            if(sub==needle) return i;
        }
        return -1;
    }
};*/

/*14: Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        string alnum = "";
        for(char c:s){
            if(isalnum(c)){
                alnum+= tolower(c);
            }
        }
        string rev = alnum;
        reverse(rev.begin(), rev.end());
        return rev==alnum;

    }
};*/


/* 15: Remove Duplicates from a sorted array:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
            }  
        }
        return i+1;
        
    }
};*/


/* 16: */