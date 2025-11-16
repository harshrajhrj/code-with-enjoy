### Longest Palindromic Substring (\#5)

**1. Question & Constraints**

  * **Question:** Given a string `s`, find the longest substring in `s` that is also a palindrome (reads the same forwards and backward).
  * **Constraints:**
      * `1 <= s.length <= 1000`
      * `s` consists of only digits and English letters.

**2. Intuition & Pattern**

  * **Intuition:** A palindrome is symmetrical around its center. This center can be a single character (like in `a*b*a`) or the space between two characters (like in `a*bb*a`). We can check every possible center and "expand" outwards as long as the characters match.
  * There are `2*n - 1` possible centers in a string of length `n`. We iterate through all of them, expand, and keep track of the longest palindrome found.
  * **Pattern:** **Expand Around Center**.

**3. Solution (C++)**

```cpp
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Helper function to expand from a center
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindrome (center is at i)
            int len1 = expandAroundCenter(s, i, i);
            
            // Even length palindrome (center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                // Calculate the start index of this new longest palindrome
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N^2)$. We iterate through `N` centers, and each expansion can take up to $O(N)$ time.
  * **Space:** $O(1)$. We only use a few pointer variables.

-----

### String to Integer (atoi) (\#8)

**1. Question & Constraints**

  * **Question:** Implement the `atoi` function, which converts a string to a 32-bit signed integer.
  * **Constraints:**
      * The function must first discard leading whitespace.
      * It then checks for an optional `+` or `-` sign.
      * It reads in digits until a non-digit character is found.
      * If no digits are read, the result is 0.
      * The number must be clamped to the 32-bit signed integer range `[-2^31, 2^31 - 1]`. If the number overflows, return `INT_MAX` or `INT_MIN`.

**2. Intuition & Pattern**

  * **Intuition:** This is a **Simulation** problem. We must carefully follow the rules step-by-step. The most complex part is detecting overflow *before* it actually happens.
  * We can build the result as we go. Before adding the next digit, we check if `result > INT_MAX / 10`. If it is, we've already overflowed. If `result == INT_MAX / 10`, we must check if the new digit is greater than `7` (`INT_MAX` ends in 7).
  * **Pattern:** **String Simulation / State Machine**.

**3. Solution (C++)**

```cpp
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int result = 0;
        int n = s.length();

        // 1. Skip whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits and handle overflow
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow BEFORE it happens
            if (result > numeric_limits<int>::max() / 10 || 
                (result == numeric_limits<int>::max() / 10 && digit > 7)) {
                return (sign == 1) ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We do a single pass over the relevant parts of the string.
  * **Space:** $O(1)$.

-----

### Integer to Roman (\#12)

**1. Question & Constraints**

  * **Question:** Convert a given integer to its Roman numeral representation.
  * **Constraints:**
      * `1 <= num <= 3999`.

**2. Intuition & Pattern**

  * **Intuition:** Roman numerals are built by combining symbols. The key is that some combinations are subtractive (like `CM` for 900, `XL` for 40). The most straightforward way is to be greedy.
  * We can create a static mapping of values and their symbols, ordered from largest to smallest. Then, we greedily subtract the largest possible value from our number and append its symbol, repeating until the number is 0.
  * **Pattern:** **Greedy Algorithm**.

**3. Solution (C++)**

```cpp
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Store all possible values and their symbols, in descending order
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        
        // Greedily subtract the largest possible value
        for (int i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(1)$. The input is bounded (max 3999). The loop runs a constant number of times (13), and the inner `while` loop is also bounded (e.g., 'M' can repeat at most 3 times).
  * **Space:** $O(1)$. The output string length is also bounded.

-----

### Valid Sudoku (\#36)

**1. Question & Constraints**

  * **Question:** Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated; the board does not need to be solvable.
  * **Constraints:**
      * A board is valid if:
        1.  Each row contains the digits 1-9 without repetition.
        2.  Each column contains the digits 1-9 without repetition.
        3.  Each of the nine 3x3 sub-boxes contains the digits 1-9 without repetition.
      * The board is 9x9, with cells containing '.' or '1'-'9'.

**2. Intuition & Pattern**

  * **Intuition:** We need to check three conditions: rows, columns, and boxes. We can use **Hash Sets** (or boolean arrays) to keep track of the numbers we've seen in each row, column, and 3x3 box.
  * **Strategy:** We can iterate through the 9x9 board once. For each cell `(i, j)`, we find its box index (`box_idx = (i/3)*3 + (j/3)`). We then check if the current number is already in `rows[i]`, `cols[j]`, or `boxes[box_idx]`. If it is, the board is invalid. If not, we add it to all three sets.
  * **Pattern:** **Hash Set** / **Matrix Traversal**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                
                if (num == '.') continue;
                
                // 1. Check Row
                if (rows[i].count(num)) return false;
                rows[i].insert(num);

                // 2. Check Column
                if (cols[j].count(num)) return false;
                cols[j].insert(num);

                // 3. Check 3x3 Box
                int box_index = (i / 3) * 3 + (j / 3);
                if (boxes[box_index].count(num)) return false;
                boxes[box_index].insert(num);
            }
        }
        return true;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(1)$. The board size is fixed at 9x9. We iterate through 81 cells, and all set operations are $O(1)$.
  * **Space:** $O(1)$. We use a fixed amount of space (3 \* 9 sets), which will store at most 81 elements in total.

-----

### Combination Sum (\#39)

**1. Question & Constraints**

  * **Question:** Given an array of *distinct* integers `candidates` and a `target`, find all *unique combinations* from `candidates` that sum to `target`. The *same* number may be used an unlimited number of times.
  * **Constraints:**
      * `1 <= candidates.length <= 30`
      * `1 <= candidates[i] <= 200`
      * `1 <= target <= 500`

**2. Intuition & Pattern**

  * **Intuition:** "Find all combinations" is a strong signal for **Backtracking (DFS)**. We need to explore all possible paths of adding numbers.
  * **Strategy:** We define a recursive function. In this function, we iterate through the `candidates` starting from a given `index`. For each candidate, we "use" it (add it to our current path and subtract from the target) and recurse. Because we can reuse numbers, the recursive call *stays at the same index*. If the target becomes 0, we found a valid combination. If it goes below 0, we backtrack.
  * **Pattern:** **Backtracking (DFS)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> results;
    
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& currentPath) {
        // Base Case 1: Found a solution
        if (target == 0) {
            results.push_back(currentPath);
            return;
        }
        
        // Base Case 2: Pruning (went too far)
        if (target < 0) {
            return;
        }

        // Recursive step: Iterate from the current index
        for (int i = index; i < candidates.size(); ++i) {
            // "Use" the candidate
            currentPath.push_back(candidates[i]);
            
            // Recurse. Stay at 'i' to allow reuse of candidates[i].
            backtrack(candidates, target - candidates[i], i, currentPath);
            
            // Backtrack
            currentPath.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentPath;
        backtrack(candidates, target, 0, currentPath);
        return results;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N^{T/M + 1})$, where $N$ is `candidates.length`, $T$ is `target`, and $M$ is the smallest candidate. This is a loose upper bound. The time complexity is exponential.
  * **Space:** $O(T/M)$ for the recursion stack depth.

-----

### Permutations (\#46)

**1. Question & Constraints**

  * **Question:** Given an array `nums` of *distinct* integers, return all possible permutations.
  * **Constraints:**
      * `1 <= nums.length <= 6`
      * `-10 <= nums[i] <= 10`

**2. Intuition & Pattern**

  * **Intuition:** "All possible permutations" is another classic **Backtracking (DFS)** problem.
  * **Strategy:** We can think of building the permutation one element at a time. A common and efficient in-place method is to use swaps.
  * We define a `backtrack(index)` function. This function is responsible for finding all permutations for the *rest* of the array starting at `index`. It iterates from `i = index` to the end. In each iteration, it **swaps** `nums[index]` with `nums[i]`, "fixing" the `i`-th element in the `index` position. Then it recurses with `backtrack(index + 1)`. After the recursive call returns, it **swaps back** to restore the array (this is the "backtrack" step).
  * **Pattern:** **Backtracking (DFS)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> results;

    void backtrack(vector<int>& nums, int index) {
        // Base case: Reached the end, we have a full permutation
        if (index == nums.size()) {
            results.push_back(nums);
            return;
        }
        
        // Recursive step: Try placing each remaining element at 'index'
        for (int i = index; i < nums.size(); ++i) {
            // Place i-th element at current 'index'
            swap(nums[index], nums[i]);
            
            // Recurse for the next index
            backtrack(nums, index + 1);
            
            // Backtrack: swap back to restore original state
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return results;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N \cdot N!)$. There are $N!$ permutations. For each one, we do an $O(N)$ copy to add it to the `results` vector.
  * **Space:** $O(N)$. This is the space for the recursion stack.

-----

### Merge Intervals (\#56)

**1. Question & Constraints**

  * **Question:** Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals and return an array of the non-overlapping intervals.
  * **Constraints:**
      * `1 <= intervals.length <= 10^4`
      * `0 <= start_i <= end_i <= 10^4`

**2. Intuition & Pattern**

  * **Intuition:** If we have `[1, 3]` and `[2, 6]`, they overlap because `2 <= 3`. The merged interval is `[1, max(3, 6)] = [1, 6]`. This is much easier to check if the intervals are **sorted** by their start time.
  * **Strategy:**
    1.  **Sort** the `intervals` based on their `start` time.
    2.  Create a `merged` list and add the first interval.
    3.  Iterate through the rest of the intervals.
    4.  Compare the `current` interval's `start` with the `end` of the `last` interval in `merged`.
    5.  If `current.start <= last.end` (overlap), update `last.end = max(last.end, current.end)`.
    6.  If no overlap, just add `current` to `merged`.
  * **Pattern:** **Sorting** + **Greedy Merging**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // 1. Sort by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]); // Add the first interval

        // 2. Iterate and merge
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& lastInterval = merged.back();
            vector<int>& currentInterval = intervals[i];

            // Check for overlap
            if (currentInterval[0] <= lastInterval[1]) {
                // Merge: update the end of the last interval
                lastInterval[1] = max(lastInterval[1], currentInterval[1]);
            } else {
                // No overlap, add as a new interval
                merged.push_back(currentInterval);
            }
        }
        
        return merged;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N \log N)$. This is dominated by the initial sorting step. The merging pass is $O(N)$.
  * **Space:** $O(N)$ (or $O(\log N)$) depending on the sort implementation's space and the space required for the `merged` result array.

-----

### Rotate List (\#61)

**1. Question & Constraints**

  * **Question:** Given the `head` of a linked list, rotate the list to the right by `k` places.
  * **Constraints:**
      * The number of nodes in the list is in the range `[0, 500]`.
      * Node values are typically in the range `[-100, 100]`.
      * `0 <= k <= 2 * 10^9`. The key constraint is that `k` can be much larger than the list length, so we must use modulo.

**2. Intuition & Pattern**

  * **Intuition:** Rotating the list by `k` is equivalent to taking the last `k` nodes and moving them to the front. If `k` is larger than the list length `n`, we only care about the remainder, `k % n`.
  * **Strategy:**
    1.  Handle edge cases (empty list, one node, `k=0`).
    2.  Find the length `n` of the list.
    3.  Calculate the effective rotation: `k = k % n`. If `k == 0`, no rotation is needed.
    4.  Find the new tail: This is the node at position `n - k - 1` (the (n-k)-th node).
    5.  The node *after* this (`n - k`-th node) will be the new head.
    6.  To perform the rotation, make the list circular by connecting the old tail to the old head.
    7.  Break the circle at the new tail (set `newTail->next = nullptr`).
  * **Pattern:** **Linked List Manipulation** / **Two Pointers**.

**3. Solution (C++)**

```cpp
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Find length and make the list circular
        ListNode* oldTail = head;
        int n = 1;
        while (oldTail->next) {
            oldTail = oldTail->next;
            n++;
        }
        oldTail->next = head; // Connect tail to head

        // 2. Calculate effective k
        int effectiveK = k % n;
        int stepsToNewTail = n - effectiveK;

        // 3. Find new tail and new head
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail - 1; ++i) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        // 4. Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We traverse the list twice at most: once to find the length and once to find the new tail.
  * **Space:** $O(1)$. We only use a few pointers.

-----

### Minimum Path Sum (\#64)

**1. Question & Constraints**

  * **Question:** Given an `m x n` grid filled with non-negative numbers, find a path from the top-left cell to the bottom-right cell that minimizes the sum of all numbers along its path.
  * **Constraints:**
      * You can only move either **down** or **right** at any point.
      * `m == grid.length`, `n == grid[i].length`
      * `1 <= m, n <= 200`

**2. Intuition & Pattern**

  * **Intuition:** This is a classic **Dynamic Programming** problem. The minimum path sum to reach any cell `(i, j)` depends on the minimum sum to reach the cells from which it's reachable (i.e., `(i-1, j)` from above or `(i, j-1)` from the left).
  * **DP Relation:** `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`
  * **Strategy:** We can create a 2D `dp` array of the same size.
    1.  Initialize `dp[0][0] = grid[0][0]`.
    2.  Fill the first row: `dp[0][j] = grid[0][j] + dp[0][j-1]`.
    3.  Fill the first column: `dp[i][0] = grid[i][0] + dp[i-1][0]`.
    4.  Fill the rest of the `dp` table using the DP relation.
    5.  The answer is `dp[m-1][n-1]`.
  * **Optimization:** We can use the `grid` itself as the `dp` table to save space.
  * **Pattern:** **Dynamic Programming**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Fill first row
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // 2. Fill first column
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        // 3. Fill the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // 4. Result is in the bottom-right corner
        return grid[m - 1][n - 1];
    }
};
```

**4. Time Complexities**

  * **Time:** $O(M \cdot N)$. We visit each cell in the grid exactly once.
  * **Space:** $O(1)$ (if we modify the input grid), or $O(M \cdot N)$ if we use a separate `dp` table.

-----

### Word Search (\#79)

**1. Question & Constraints**

  * **Question:** Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.
  * **Constraints:**
      * The word can be constructed from letters of sequentially adjacent cells (horizontally or vertically).
      * The same letter cell may not be used more than once.
      * `1 <= m, n <= 6`
      * `1 <= word.length <= 15`

**2. Intuition & Pattern**

  * **Intuition:** We need to find *a* path. This is a classic **Backtracking (DFS)** problem.
  * **Strategy:**
    1.  Iterate through every cell `(i, j)` on the board. If `board[i][j]` matches `word[0]`, start a DFS from this cell.
    2.  The DFS function `(i, j, index)` will try to find `word[index...]` starting at `(i, j)`.
    3.  **Base Case 1:** If `index == word.length()`, we found the whole word, return `true`.
    4.  **Base Case 2 (Pruning):** If `(i, j)` is out of bounds or `board[i][j] != word[index]`, return `false`.
    5.  **Mark as visited:** To prevent reuse, temporarily change `board[i][j]` to a special character (e.g., '\#').
    6.  **Explore neighbors:** Recursively call DFS for all 4 adjacent cells `(i+1, j)`, `(i-1, j)`, `(i, j+1)`, `(i, j-1)` with `index + 1`.
    7.  If any neighbor returns `true`, we found a path, so return `true`.
    8.  **Backtrack:** After exploring neighbors, restore the cell: `board[i][j] = original_char`.
    9.  If all neighbors return `false`, return `false`.
  * **Pattern:** **Backtracking (DFS)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base Case 1: Word found
        if (index == word.length()) {
            return true;
        }
        
        // Base Case 2: Out of bounds or char mismatch
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore neighbors
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        // Backtrack
        board[i][j] = temp;
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N \cdot 3^L)$, where $N = M \cdot N$ is the number of cells and $L$ is `word.length`. We start a DFS from each of $N$ cells. The DFS can branch 3 ways (not 4, since we don't go back to the cell we came from) and has a depth of $L$.
  * **Space:** $O(L)$ for the recursion stack depth.

-----

### Validate Binary Search Tree (\#98)

**1. Question & Constraints**

  * **Question:** Given the `root` of a binary tree, determine if it is a valid Binary Search Tree (BST).
  * **Constraints:**
      * A valid BST has these properties:
          * The left subtree of a node contains only nodes with keys **less than** the node's key.
          * The right subtree of a node contains only nodes with keys **greater than** the node's key.
          * Both the left and right subtrees must also be valid BSTs.
      * The number of nodes is in `[1, 10^4]`.

**2. Intuition & Pattern**

  * **Intuition:** It's not enough to check `node->left->val < node->val`. The *entire* left subtree must be less. This means we need to pass down valid value ranges.
  * **Strategy (Recursive):**
    1.  Define a recursive helper `isValid(node, min_val, max_val)`.
    2.  The `root` must be between `(-inf, +inf)`.
    3.  When we go left, the new `max_val` becomes `node->val`. The `min_val` stays the same. `isValid(node->left, min_val, node->val)`.
    4.  When we go right, the new `min_val` becomes `node->val`. The `max_val` stays the same. `isValid(node->right, node->val, max_val)`.
    5.  **Base Case:** If `node` is `nullptr`, return `true`.
    6.  **Validation:** If `node->val <= min_val` or `node->val >= max_val`, return `false`.
  * **Pattern:** **Tree Traversal (DFS)** with **Range constraints**. (An alternative is In-order Traversal, which must produce a *strictly* increasing sequence).

**3. Solution (C++)**

```cpp
#include <limits>
#include <cstdint> // For INT64_MIN/MAX

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Use long long (int64_t) to handle edge cases where node->val == INT_MIN or INT_MAX
    bool isValid(TreeNode* node, long long min_val, long long max_val) {
        // Base case: Empty node is valid
        if (node == nullptr) {
            return true;
        }

        // Validation: Check if current node is within its valid range
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // Recursively check subtrees with updated ranges
        return isValid(node->left, min_val, node->val) && 
               isValid(node->right, node->val, max_val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We visit each node in the tree exactly once.
  * **Space:** $O(H)$, where $H$ is the height of the tree, for the recursion stack. $O(\log N)$ on average, $O(N)$ worst case (skewed tree).

-----

### Binary Tree Level Order Traversal (\#102)

**1. Question & Constraints**

  * **Question:** Given the `root` of a binary tree, return the *level order traversal* of its nodes' values. (i.e., from left to right, level by level).
  * **Constraints:**
      * The number of nodes is in `[0, 2000]`.

**2. Intuition & Pattern**

  * **Intuition:** "Level by level" is the definition of **Breadth-First Search (BFS)**.
  * **Strategy:**
    1.  Use a **Queue** (e.g., `std::queue<TreeNode*>`).
    2.  Push the `root` into the queue.
    3.  While the queue is not empty:
        a.  Get the current `level_size`. This is crucial.
        b.  Create a `current_level` vector to store values.
        c.  Loop `level_size` times:
        i.   Pop a `node` from the front of the queue.
        ii.  Add `node->val` to `current_level`.
        iii. If `node->left` exists, push it to the queue.
        iv.  If `node->right` exists, push it to the queue.
        d.  After the loop, add `current_level` to the main `result` vector.
  * **Pattern:** **Tree Traversal (BFS)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;

            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                current_level.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(current_level);
        }
        return result;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We visit each node exactly once.
  * **Space:** $O(W)$, where $W$ is the maximum width of the tree. This is the maximum size the queue will reach (in a perfect binary tree, $W \approx N/2$).

-----

### Convert Sorted List to Binary Search Tree (\#109)

**1. Question & Constraints**

  * **Question:** Given the `head` of a sorted singly linked list, convert it to a **height-balanced** Binary Search Tree (BST).
  * **Constraints:**
      * A height-balanced tree is one where the depth of the two subtrees of any node never differs by more than 1.
      * Number of nodes is in `[0, 2 * 10^4]`.

**2. Intuition & Pattern**

  * **Intuition:** To build a *balanced* BST from a *sorted* structure, the middle element must be the root. The left half forms the left subtree, and the right half forms the right subtree. This is a recursive definition.
  * **Strategy (Slow/Fast Pointers):**
    1.  **Base Case:** If `head` is `nullptr`, return `nullptr`.
    2.  Find the middle node of the list. Use the **slow and fast pointer** technique. We also need a `prev` pointer to `slow` to "cut" the list in half.
    3.  The `slow` pointer's value becomes the `root` of the new `TreeNode`.
    4.  The left half of the list (from `head` to `prev`) forms the left subtree. Set `prev->next = nullptr`.
    5.  The right half of the list (from `slow->next` to the end) forms the right subtree.
    6.  Recursively call the function: `root->left = sortedListToBST(head)` and `root->right = sortedListToBST(slow->next)`.
  * **Pattern:** **Divide and Conquer** / **Slow & Fast Pointers**.

**3. Solution (C++)**

```cpp
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 'slow' is now the middle element
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildBST(head, slow);
        root->right = buildBST(slow->next, tail);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N \log N)$. Finding the middle takes $O(N)$, and we do this at each level of recursion. $T(N) = 2T(N/2) + O(N)$.
  * **Space:** $O(\log N)$ for the recursion stack depth (since the resulting tree is balanced).

-----

### Populating Next Right Pointers in Each Node (\#116)

**1. Question & Constraints**

  * **Question:** You are given a **perfect binary tree**. Populate each `next` pointer to point to its next right node. If there is no next right node, set the `next` pointer to `NULL`.
  * **Constraints:**
      * The tree is **perfect**: all leaves are at the same level, and every non-leaf node has two children.
      * The `Node` structure has `left`, `right`, and `next` pointers.

**2. Intuition & Pattern**

  * **Intuition:** Since the tree is perfect, we can process it level by level (BFS). Or, we can use the `next` pointers we've *already* set on a parent level to connect the children.
  * **Strategy (Level-by-Level):**
    1.  Start with `leftmost = root`. This pointer will move down the left edge of the tree.
    2.  While `leftmost->left` exists (i.e., we are not at the leaf level):
        a.  Set `head = leftmost` to be a "runner" for the current level.
        b.  While `head` is not null:
        i.   Connect `head->left` to `head->right`.
        ii.  If `head->next` exists, connect `head->right` to `head->next->left`.
        iii. Move the runner: `head = head->next`.
        c.  Move to the next level: `leftmost = leftmost->left`.
  * **Pattern:** **Tree Traversal (Level-by-Level)**. This is a $O(1)$ space solution. A $O(N)$ space solution would use a standard BFS queue.

**3. Solution (C++)**

```cpp
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    // ... constructors
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* leftmost = root;

        // Loop for each level
        while (leftmost->left) {
            Node* head = leftmost; // Runner for the current level
            
            // Loop across the current level
            while (head) {
                // Connection 1: Connect left child to right child
                head->left->next = head->right;

                // Connection 2: Connect right child to next parent's left child
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                // Move runner to the next node on the same level
                head = head->next;
            }
            // Move to the start of the next level
            leftmost = leftmost->left;
        }
        
        return root;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We visit each node exactly once.
  * **Space:** $O(1)$. This is the key benefit of this approach over a standard BFS.

-----

### LRU Cache (\#146)

**1. Question & Constraints**

  * **Question:** Design and implement a data structure for a Least Recently Used (LRU) cache.
  * **Constraints:**
      * It must support two operations: `get(key)` and `put(key, value)`.
      * `get(key)`: Get the value (if key exists), otherwise return -1. This operation must mark the key as *recently used*.
      * `put(key, value)`: Update or insert the key/value. If adding a new key causes the cache to exceed its `capacity`, evict the **least recently used** key before inserting.
      * All operations must be in **$O(1)$ average time**.

**2. Intuition & Pattern**

  * **Intuition:**
    1.  To get $O(1)$ lookup (`get`), we need a **Hash Map** (`std::unordered_map`).
    2.  To get $O(1)$ eviction and reordering (move-to-front), we need a **Doubly Linked List**.
  * **Strategy:**
      * The `unordered_map<int, Node*>` maps a `key` to its `Node` in the list.
      * The `Node` in the list will store `key`, `value`, `prev`, and `next`.
      * The list is ordered from most-recently-used (MRU) at the head to least-recently-used (LRU) at the tail.
      * **`get(key)`:**
        1.  Look up `key` in the map. If not found, return -1.
        2.  If found, get the `node`.
        3.  Move `node` to the front (head) of the list.
        4.  Return `node->value`.
      * **`put(key, value)`:**
        1.  Check if `key` is in the map.
        2.  If **yes**: update `node->value` and move `node` to the front.
        3.  If **no**:
            a.  Check if `size == capacity`.
            b.  If **yes**: Evict the LRU item (remove from `tail`, remove from `map`).
            c.  Create a new `node` with `(key, value)`.
            d.  Add the new `node` to the front (head).
            e.  Add `(key, new_node)` to the map.
  * **Pattern:** **Hash Map + Doubly Linked List**.

**3. Solution (C++)**

```cpp
#include <unordered_map>
#include <list> // Using std::list is simpler

class LRUCache {
private:
    int capacity;
    // list stores {key, value} pairs
    std::list<std::pair<int, int>> lruList; 
    // map stores key -> iterator to the list node
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;

    // Helper to move a node to the front (most recent)
    void moveToFront(int key, int value) {
        lruList.erase(cache[key]);
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }

public:
    LRUCache(int cap) : capacity(cap) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        // Get value and move to front
        int value = cache[key]->second;
        moveToFront(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update existing
            moveToFront(key, value);
        } else {
            // Add new
            lruList.push_front({key, value});
            cache[key] = lruList.begin();
            
            // Check capacity
            if (lruList.size() > capacity) {
                // Evict LRU (last element)
                int lruKey = lruList.back().first;
                cache.erase(lruKey);
                lruList.pop_back();
            }
        }
    }
};
```

**4. Time Complexities**

  * **`get(key)`:** $O(1)$ average. $O(1)$ map lookup + $O(1)$ list manipulation.
  * **`put(key, value)`:** $O(1)$ average. $O(1)$ map lookup/insert + $O(1)$ list manipulation.
  * **Space:** $O(\text{capacity})$. We store up to `capacity` key-value pairs in the map and list.

-----

### Min Stack (\#155)

**1. Question & Constraints**

  * **Question:** Design a stack that supports `push(val)`, `pop()`, `top()`, and `getMin()` in constant time.
  * **Constraints:** All four operations must have an average time complexity of **$O(1)$**.

**2. Intuition & Pattern**

  * **Intuition:** A standard stack gives $O(1)$ `push`, `pop`, and `top`. The challenge is `getMin`. If we just store a single `min_val` variable, it will be incorrect when we `pop` the minimum element. We need to know the minimum *at every state* of the stack.
  * **Strategy:** We can use two stacks. One is the main `dataStack`, and the other is a `minStack`. When we `push(x)` to `dataStack`, we push `min(x, minStack.top())` to `minStack`. When we `pop`, we pop from *both* stacks. This way, `minStack.top()` always holds the minimum of all elements currently in `dataStack`.
  * **Pattern:** **Augmented Data Structure**. We add an auxiliary structure (the `minStack`) to track an extra property ($O(1)$ minimum) alongside the primary data structure.

**3. Solution (C++)**

```cpp
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack() {
        // Initialize minStack with a max value to simplify logic
        minStack.push(numeric_limits<int>::max());
    }
    
    void push(int val) {
        dataStack.push(val);
        // Push the new minimum (either val or the old minimum)
        minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        dataStack.pop();
        minStack.pop(); // Pop from both to keep them in sync
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
```

**4. Time Complexities**

  * **`push`, `pop`, `top`, `getMin`:** All are **$O(1)$**.
  * **Space:** **$O(N)$**, where $N$ is the number of elements in the stack. We use two stacks.

-----

### Number of Islands (\#200)

**1. Question & Constraints**

  * **Question:** Given an `m x n` 2D binary grid of `'1'`s (land) and `'0'`s (water), return the number of islands. An island is surrounded by water and formed by connecting adjacent `'1'`s horizontally or vertically.
  * **Constraints:** `1 <= m, n <= 300`.

**2. Intuition & Pattern**

  * **Intuition:** We need to find all "connected components" of `'1'`s. We can scan the grid. When we find a `'1'`, we know we've found a new island. We must then find *all* parts of that island and "sink" them (e.g., change to `'0'`) so we don't count them again.
  * **Strategy:**
    1.  Initialize `count = 0`.
    2.  Iterate through every cell `(r, c)` in the grid.
    3.  If `grid[r][c] == '1'`:
        a.  We found a new island: `count++`.
        b.  Call a "sink" function, `dfs(grid, r, c)`, to find all adjacent `'1'`s and change them to `'0'`.
  * **Pattern:** **Graph Traversal (DFS or BFS)**. The grid is treated as an implicit graph.

**3. Solution (C++)**

```cpp
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base cases for stopping: out of bounds or water
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }
        
        // "Sink" the land cell by marking it as visited ('0')
        grid[r][c] = '0';
        
        // Visit all 4 neighbors
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    islandCount++;
                    dfs(grid, r, c);
                }
            }
        }
        return islandCount;
    }
};
```

**4. Time Complexities**

  * **Time:** **$O(M \cdot N)$**. We visit each cell in the grid at most once.
  * **Space:** **$O(M \cdot N)$** in the worst case (a single, large, snaking island) for the DFS recursion stack.

-----

### Course Schedule (\#207)

**1. Question & Constraints**

  * **Question:** Given `numCourses` and a list of `prerequisites` (pairs `[a, b]`, meaning "to take course `a`, you must first take `b`"), determine if it is possible to finish all courses.
  * **Constraints:** `1 <= numCourses <= 2000`. `0 <= prerequisites.length <= 5000`.

**2. Intuition & Pattern**

  * **Intuition:** This describes a dependency graph, where an edge `b -> a` exists for each prerequisite. The question is: "Does this directed graph contain a cycle?" If a cycle exists (e.g., A needs B, B needs A), it's impossible to finish.
  * **Strategy (Kahn's Algorithm):** This is a **Topological Sort** algorithm that uses BFS.
    1.  Build an adjacency list (`adj`) and an `inDegree` array (counts incoming edges).
    2.  Add all courses with an `inDegree` of 0 to a queue.
    3.  Keep a `count` of visited (completed) courses.
    4.  While the queue is not empty, pop a `course`. Increment `count`.
    5.  For each `neighbor` of that `course`, decrement its `inDegree`. If `inDegree[neighbor]` becomes 0, add it to the queue.
    6.  If `count == numCourses`, no cycle exists.
  * **Pattern:** **Topological Sort (Graph)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);

        // 1. Build adjacency list and inDegree array
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // 2. Add all 0-inDegree nodes to queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;
        // 3. Process the queue
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            // 4. "Remove" edges and update neighbors
            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 5. Check if all courses were taken
        return coursesTaken == numCourses;
    }
};
```

**4. Time Complexities**

  * **Time:** **$O(V + E)$**, where $V$ is `numCourses` and $E$ is `prerequisites.length`.
  * **Space:** **$O(V + E)$** to store the adjacency list and in-degree array.

-----

### Course Schedule II (\#210)

**1. Question & Constraints**

  * **Question:** Same as \#207, but now return a valid *order* in which to take the courses. If impossible, return an empty array.
  * **Constraints:** Same as \#207.

**2. Intuition & Pattern**

  * **Intuition:** This is a direct extension of `Course Schedule I`. The order in which we pop nodes from the queue in Kahn's algorithm *is* a valid topological sort.
  * **Strategy:**
    1.  Implement Kahn's algorithm exactly as in \#207.
    2.  Create a `result` vector.
    3.  Every time you pop a `course` from the queue, add it to the `result` vector.
    4.  At the end, if `result.size() == numCourses`, return `result`. Otherwise (a cycle was detected), return `{}`.
  * **Pattern:** **Topological Sort (Graph)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        vector<int> result;

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course); // Add the course to the order

            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() == numCourses) {
            return result;
        } else {
            return {}; // Cycle detected
        }
    }
};
```

**4. Time Complexities**

  * **Time:** **$O(V + E)$**.
  * **Space:** **$O(V + E)$**.

-----

### Add and Search Word - Data structure design (\#211)

**1. Question & Constraints**

  * **Question:** Design a `WordDictionary` class with `addWord(word)` and `search(word)`. `search(word)` supports the wildcard `.` which can match any single letter.
  * **Constraints:** `1 <= word.length <= 25`. At most $10^4$ calls to `addWord` and `search`.

**2. Intuition & Pattern**

  * **Intuition:** The `addWord` and prefix-matching nature points directly to a **Trie (Prefix Tree)**. The wildcard `.` means our `search` function can't just follow one path; it must explore *all* paths if it encounters a `.`.
  * **Strategy:**
    1.  `TrieNode`: A struct with `children[26]` (pointers) and `isEndOfWord` (bool).
    2.  `addWord(word)`: Standard Trie insertion.
    3.  `search(word)`: Call a recursive DFS helper, `searchHelper(word, index, node)`.
    4.  `searchHelper` Logic:
          * If `index == word.length()`, return `node->isEndOfWord`.
          * If `word[index] == '.'`: Iterate through all 26 children. If any `child` is not null, recursively call `searchHelper(word, index + 1, child)`. If *any* of those return `true`, return `true`.
          * If `word[index]` is a letter: Check if `node->children[word[index] - 'a']` exists. If so, recurse: `searchHelper(word, index + 1, node->children[...])`.
  * **Pattern:** **Trie (Prefix Tree)** with **Backtracking (DFS)** search.

**3. Solution (C++)**

```cpp
#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(string& word, int index, TrieNode* node) {
        if (index == word.length()) {
            return node->isEndOfWord;
        }

        char c = word[index];

        if (c == '.') {
            // Wildcard: try all children
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            // Normal letter
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[i]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
```

**4. Time Complexities**

  * **`addWord` Time:** **$O(L)$**, where $L$ is word length.
  * **`search` Time:** **$O(L)$** (no wildcards). **$O(N \cdot 26^L)$** in the worst case (all wildcards, full trie), but more practically $O(M)$ where $M$ is the total number of nodes in the trie.
  * **Space:** **$O(K \cdot L)$**, where $K$ is number of words and $L$ is average length.

-----

### Game of Life (\#289)

**1. Question & Constraints**

  * **Question:** Simulate one generation of Conway's Game of Life on an `m x n` board (`1`=alive, `0`=dead).
  * **Rules:**
    1.  Live cell \< 2 live neighbors -\> dies (underpopulation).
    2.  Live cell == 2 or 3 live neighbors -\> lives.
    3.  Live cell \> 3 live neighbors -\> dies (overpopulation).
    4.  Dead cell == 3 live neighbors -\> becomes alive (reproduction).
  * **Constraints:** Must be done **in-place**.

**2. Intuition & Pattern**

  * **Intuition:** The "in-place" rule is the main challenge. If we change `board[i][j]`, it will affect the neighbor count for cells we haven't processed. We need to store *two* states (original and next) in a *single* cell.
  * **Strategy:** Use temporary state codes.
      * `0`: dead -\> dead
      * `1`: alive -\> alive
      * `2`: alive -\> dead (a new state)
      * `3`: dead -\> alive (a new state)
    <!-- end list -->
    1.  **Pass 1:** Iterate `(i, j)`. For each cell, count its 8 neighbors. **Crucially**, if a neighbor is `1` *or* `2`, it was *originally alive*, so count it. Apply the rules using the original state and set the *new* state (`2` or `3`) if it changes.
    2.  **Pass 2:** Iterate `(i, j)` again. "Finalize" the states: change `2` to `0` and `3` to `1`.
  * **Pattern:** **In-place State Transition**.

**3. Solution (C++)**

```cpp
#include <vector>
using namespace std;

class Solution {
private:
    int countLiveNeighbors(vector<vector<int>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        
        for (int i = r - 1; i <= r + 1; ++i) {
            for (int j = c - 1; j <= c + 1; ++j) {
                if (i == r && j == c) continue; // Skip self
                if (i >= 0 && i < m && j >= 0 && j < n) {
                    // Count 1 (alive) and 2 (alive->dead)
                    if (board[i][j] == 1 || board[i][j] == 2) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Pass 1: Mark transitions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbors = countLiveNeighbors(board, i, j);
                
                if (board[i][j] == 1) { // Was alive
                    if (neighbors < 2 || neighbors > 3) {
                        board[i][j] = 2; // alive -> dead
                    }
                } else { // Was dead
                    if (neighbors == 3) {
                        board[i][j] = 3; // dead -> alive
                    }
                }
            }
        }

        // Pass 2: Finalize states
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};
```

**4. Time Complexities**

  * **Time:** **$O(M \cdot N)$**. We do two passes, and neighbor counting is constant ($O(8)$).
  * **Space:** **$O(1)$** (in-place).

-----

### Longest Increasing Subsequence (\#300)

**1. Question & Constraints**

  * **Question:** Given an array `nums`, find the *length* of the longest strictly increasing subsequence (LIS). A subsequence does not have to be contiguous.
  * **Constraints:** `1 <= nums.length <= 2500`.

**2. Intuition & Pattern**

  * **Intuition (O(N log N)):** A $O(N^2)$ DP solution exists, but a faster $O(N \log N)$ solution is preferred. This solution maintains an "active" list `tails` (or `sub`). `tails[i]` stores the smallest possible ending element of an increasing subsequence of length `i+1`.
  * **Strategy:**
    1.  Initialize an empty `tails` vector.
    2.  Iterate through `num` in `nums`:
    3.  If `num` is larger than `tails.back()`, it extends the longest subsequence, so `tails.push_back(num)`.
    4.  If `num` is *not* larger, it might be a *better* (smaller) ending for a shorter subsequence. We find the *first* element in `tails` that is $\ge$ `num` (using binary search / `lower_bound`) and replace it. This creates a new potential for a longer sequence later.
    5.  The `tails` array does *not* store the LIS itself, but its **length** is always correct.
  * **Pattern:** **Dynamic Programming (with Binary Search optimization)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            // Find the first element in tails that is >= num
            auto it = lower_bound(tails.begin(), tails.end(), num);
            
            if (it == tails.end()) {
                // num is larger than all elements, extend the LIS
                tails.push_back(num);
            } else {
                // num can replace *it to make a
                // shorter (or same-length) subsequence end with a smaller number
                *it = num;
            }
        }
        
        // The length of tails is the length of the LIS
        return tails.size();
    }
};
```

**4. Time Complexities**

  * **Time:** **$O(N \log N)$**. We iterate $N$ times, and each `lower_bound` takes $O(\log N)$.
  * **Space:** **$O(N)$** for the `tails` vector.

-----

### Design Tic-Tac-Toe (\#348)

**1. Question & Constraints**

  * **Question:** Design a Tic-Tac-Toe game on an `n x n` grid. Implement a `move(row, col, player)` function that returns `0` (no winner), `1` (Player 1 wins), or `2` (Player 2 wins).
  * **Constraints:** `n` can be large (e.g., $n=100$). A naive $O(N^2)$ check is too slow. The `move` function must be fast.

**2. Intuition & Pattern**

  * **Intuition:** We cannot afford to check the whole board on every move. We need an $O(1)$ way to determine a winner.
  * **Strategy:** We can track the "score" of each row, column, and the two diagonals.
    1.  Player 1 adds `+1` to a score. Player 2 adds `-1`.
    2.  A win is achieved when any row, column, or diagonal score reaches `+n` or `-n`.
    3.  We need `rows[n]`, `cols[n]`, `diag1`, and `diag2` to store these scores.
    4.  `move(r, c, p)`:
        a.  Set `val = (p == 1) ? 1 : -1`.
        b.  `rows[r] += val`, `cols[c] += val`.
        c.  If `r == c`, `diag1 += val`.
        d.  If `r + c == n - 1`, `diag2 += val`.
        e.  Check `if (abs(rows[r]) == n || abs(cols[c]) == n || ...)` and return `p` if true.
        f.  Else, return `0`.
  * **Pattern:** **Data-Driven Design** / **$O(1)$ Check**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <cmath> // for abs
using namespace std;

class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diag1;
    int diag2;
    int n;

public:
    TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0), diag1(0), diag2(0) {}
    
    int move(int row, int col, int player) {
        int val = (player == 1) ? 1 : -1;
        
        rows[row] += val;
        cols[col] += val;
        
        if (row == col) {
            diag1 += val;
        }
        if (row + col == n - 1) {
            diag2 += val;
        }
        
        // Check for win
        if (abs(rows[row]) == n || 
            abs(cols[col]) == n || 
            abs(diag1) == n || 
            abs(diag2) == n) {
            return player;
        }
        
        return 0; // No winner yet
    }
};
```

**4. Time Complexities**

  * **Constructor:** **$O(N)$** to initialize the arrays.
  * **`move` Time:** **$O(1)$**.
  * **Space:** **$O(N)$** to store the `rows` and `cols` arrays.

-----

### Pacific Atlantic Water Flow (\#417)

**1. Question & Constraints**

  * **Question:** You are given an `m x n` integer matrix `heights` representing a 2D land mass. Water can flow 4-directionally (up, down, left, right) from a cell to an adjacent cell if the neighbor's height is **less than or equal** to the current cell's height. Find and return a list of all grid coordinates `(r, c)` from which water can flow to *both* the Pacific Ocean (top and left edges) and the Atlantic Ocean (bottom and right edges).
  * **Constraints:**
      * `1 <= m, n <= 200`
      * `0 <= heights[r][c] <= 100,000`

**2. Intuition & Pattern**

  * **Intuition:** A naive approach would be to start a DFS/BFS from *every* cell to see if it can reach both oceans. This is very slow ($O((MN)^2)$).
  * The key is to reverse the problem: **Start from the oceans and flow inland.**
  * Find all cells that can reach the Pacific by starting a DFS/BFS from the Pacific border (top and left edges). Water can flow "uphill" from `(r, c)` to a neighbor `(nr, nc)` if `heights[nr][nc] >= heights[r][c]`.
  * Find all cells that can reach the Atlantic by starting from the Atlantic border (bottom and right edges) and flowing "uphill".
  * The answer is the **intersection** of these two sets of cells.
  * **Pattern:** **Graph Traversal (DFS or BFS)**, starting from multiple sources (the borders).

**3. Solution (C++)**

```cpp
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    int m, n;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // DFS to find all reachable cells from an ocean
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int r, int c) {
        if (reachable[r][c]) {
            return;
        }
        reachable[r][c] = true;
        
        for (auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            
            // Check bounds and the "flow uphill" condition
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                heights[nr][nc] >= heights[r][c]) {
                dfs(heights, reachable, nr, nc);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 1. Start DFS from Pacific border
        for (int c = 0; c < n; ++c) {
            dfs(heights, pacific, 0, c);   // Top edge
            dfs(heights, atlantic, m - 1, c); // Bottom edge
        }
        for (int r = 0; r < m; ++r) {
            dfs(heights, pacific, r, 0);   // Left edge
            dfs(heights, atlantic, r, n - 1); // Right edge
        }

        // 2. Find the intersection
        vector<vector<int>> result;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(M \cdot N)$. We run two separate DFS traversals. Each DFS visits every cell at most once. The final intersection check is also $O(M \cdot N)$.
  * **Space:** $O(M \cdot N)$ for the `pacific` and `atlantic` visited matrices, and for the DFS recursion stack in the worst case.

-----

### Minesweeper (\#529)

**1. Question & Constraints**

  * **Question:** Implement the "reveal" logic for a Minesweeper click. You are given a `board` and a `click` coordinate.
  * **Rules:**
    1.  If you click a mine (`'M'`), it becomes `'X'`. Game over.
    2.  If you click an empty square (`'E'`) with at least one adjacent mine, it's revealed with a digit (`'1'`-`'8'`) representing the mine count. The reveal stops.
    3.  If you click an empty square (`'E'`) with *no* adjacent mines, it becomes a blank (`'B'`) and *all* adjacent squares are recursively revealed.
  * **Constraints:**
      * `1 <= m, n <= 50`
      * `board[i][j]` is `'M'`, `'E'`, `'B'`, or `'1'`-`'8'`.

**2. Intuition & Pattern**

  * **Intuition:** This is a direct simulation. Rule 1 is a simple base case. Rule 3, the "recursive reveal," is a classic **Graph Traversal** problem. When a blank `B` is revealed, it's like a flood-fill.
  * We can use either **DFS** or **BFS**.
  * **Strategy (DFS):**
    1.  Handle the mine (`'M'`) click first.
    2.  Define a `dfs(board, r, c)` function.
    3.  In `dfs`:
        a.  Check bounds and if the cell is already revealed (not `'E'`).
        b.  Count adjacent mines for `(r, c)`.
        c.  If `mine_count > 0`, set `board[r][c]` to the digit and stop.
        d.  If `mine_count == 0`, set `board[r][c] = 'B'` and call `dfs` on all 8 neighbors.
  * **Pattern:** **Graph Traversal (DFS or BFS) / Flood Fill**.

**3. Solution (C++)**

```cpp
#include <vector>
using namespace std;

class Solution {
private:
    int m, n;
    // 8 directions for neighbors
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    // Helper to count adjacent mines
    int countMines(vector<vector<char>>& board, int r, int c) {
        int count = 0;
        for (auto& dir : dirs) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                count++;
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        // Base case: out of bounds or already revealed
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') {
            return;
        }

        int mines = countMines(board, r, c);

        if (mines > 0) {
            // Rule 2: Reveal digit and stop
            board[r][c] = '0' + mines;
        } else {
            // Rule 3: Reveal 'B' and recurse
            board[r][c] = 'B';
            for (auto& dir : dirs) {
                dfs(board, r + dir.first, c + dir.second);
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int r = click[0];
        int c = click[1];

        // Rule 1: Clicked on a mine
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        // Start DFS for Rules 2 & 3
        dfs(board, r, c);
        return board;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(M \cdot N)$. In the worst case (e.g., a board with no mines), we visit every cell once.
  * **Space:** $O(M \cdot N)$ for the recursion stack in the worst case (a long, snaking path).

-----

### Reorganize String (\#767)

**1. Question & Constraints**

  * **Question:** Given a string `s`, rearrange its characters so that no two adjacent characters are the same. If a valid rearrangement is impossible, return `""`.
  * **Constraints:**
      * `1 <= s.length <= 500`
      * `s` consists of lowercase English letters.
      * **Impossibility Condition:** It's impossible if any single character appears more than `(n + 1) / 2` times.

**2. Intuition & Pattern**

  * **Intuition:** This is a **Greedy** problem. To avoid adjacent duplicates, we should always try to append the most frequent character that is *not* the same as the last one we added.
  * A **Max-Heap (Priority Queue)** is the perfect data structure for this. We can store `(frequency, char)` and always have access to the most frequent characters.
  * **Strategy:**
    1.  Count the frequency of each character.
    2.  Check the impossibility condition: `if (any_count > (s.length() + 1) / 2) return "";`.
    3.  Push all `(count, char)` pairs into a max-heap.
    4.  Build the `result` string:
        a.  Keep a `prev` (or `blocked`) entry.
        b.  While the heap is not empty:
        i.   Pop the top `current` entry.
        ii.  Append `current.char` to `result`.
        iii. If `prev` is valid (count \> 0), push `prev` back onto the heap.
        iv.  Decrement `current.count` and set `prev = current`.
  * **Pattern:** **Greedy** with a **Max-Heap**.

**3. Solution (C++)**

```cpp
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        // Use a pair {frequency, char} for the heap
        priority_queue<pair<int, char>> maxHeap;
        for (auto const& [key, val] : counts) {
            // Check impossibility condition
            if (val > (s.length() + 1) / 2) {
                return "";
            }
            maxHeap.push({val, key});
        }

        string result = "";
        pair<int, char> prev = {0, ' '}; // {count, char} of the last used char

        while (!maxHeap.empty()) {
            pair<int, char> current = maxHeap.top();
            maxHeap.pop();

            result += current.second;
            current.first--; // Decrement count

            // Push the *previous* char back, so we don't use it twice in a row
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            
            // The current char becomes the "blocked" previous char
            prev = current;
        }
        
        return result;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N \log K)$, where $N$ is the length of the string and $K$ is the number of unique characters. Since $K$ is fixed at 26 (alphabet size), this is effectively **$O(N)$**.
      * $O(N)$ to build the count map.
      * $O(K \log K)$ to build the heap.
      * $O(N \log K)$ for the `while` loop, as we do $N$ pushes/pops.
  * **Space:** $O(K)$ or **$O(1)$** (since $K=26$) for the map and heap.