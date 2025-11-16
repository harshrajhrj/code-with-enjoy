### Two Sum (\#1)

**1. Question & Constraints**

  * **Question:** Given an array of integers `nums` and an integer `target`, return the *indices* of the two numbers in the array that add up to `target`.
  * **Constraints:**
      * You can assume there is **exactly one solution**.
      * You may **not** use the same element twice.
      * `2 <= nums.length <= 10^4`

**2. Intuition & Pattern**

  * **Intuition:** A naive $O(N^2)$ solution uses two nested loops. To optimize, we need a faster way to look up the "complement" (`target - current_number`). A hash map provides an $O(1)$ lookup time.
  * We can iterate the array once. For each number `nums[i]`, we check if its complement (`target - nums[i]`) is already in the map.
      * If yes, we've found our pair.
      * If no, we add the *current* number `nums[i]` and its index `i` to the map for future lookups.
  * **Pattern:** **Hash Map (One-pass)**

**3. Solution (C++)**

```cpp
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map stores: value -> index
        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement we need is already in the map
            if (seen.count(complement)) {
                // Found it
                return {seen[complement], i};
            }

            // Not found, add the current number to the map
            seen[nums[i]] = i;
        }

        return {}; // Should not be reached, per constraints
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We iterate the list once. Hash map operations (insertion and lookup) are $O(1)$ on average.
  * **Space:** $O(N)$ to store the hash map, which could contain up to $N$ elements.

-----

### Roman to Integer (\#13)

**1. Question & Constraints**

  * **Question:** Given a string `s` representing a Roman numeral, convert it to its integer value.
  * **Constraints:**
      * `1 <= s.length <= 15`
      * The input is guaranteed to be a valid Roman numeral in the range `[1, 3999]`.

**2. Intuition & Pattern**

  * **Intuition:** Roman numerals are typically additive (`VI` = 5 + 1 = 6). The only exception is for subtraction, when a smaller value precedes a larger one (`IV` = 5 - 1 = 4).
  * The easiest way to handle this is to iterate from **right to left**. We keep track of the `last` value seen.
      * If the `current` value is $\ge$ `last` value, we add it (`VI` $\rightarrow$ add 1, then add 5).
      * If the `current` value is $<$ `last` value, we subtract it (`IV` $\rightarrow$ add 5, then subtract 1).
  * **Pattern:** **String Simulation (Right-to-Left)**

**3. Solution (C++)**

```cpp
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int lastValue = 0;
        
        // Iterate from right to left
        for (int i = s.length() - 1; i >= 0; --i) {
            int currentValue = values[s[i]];
            
            if (currentValue < lastValue) {
                // Subtraction case (e.g., 'I' in "IV")
                total -= currentValue;
            } else {
                // Addition case (e.g., 'V' in "IV" or "VI")
                total += currentValue;
            }
            lastValue = currentValue;
        }
        return total;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We iterate the string once. Since the max length is 15, this is effectively $O(1)$.
  * **Space:** $O(1)$. The hash map size is constant.

-----

### Valid Parentheses (\#20)

**1. Question & Constraints**

  * **Question:** Given a string `s` containing only `(`, `)`, `{`, `}`, `[`, `]`, determine if the string is valid.
  * **Constraints:**
      * An input string is valid if:
        1.  Open brackets are closed by the same type of bracket.
        2.  Open brackets are closed in the correct order.
      * `1 <= s.length <= 10^4`

**2. Intuition & Pattern**

  * **Intuition:** This is a classic "Last-In, First-Out" problem. When we see an open bracket, we "owe" a matching close bracket. When we see a close bracket, it must match the *most recent* open bracket.
  * A **Stack** is the perfect tool.
      * If we see an *open* bracket, push it onto the stack.
      * If we see a *close* bracket, check the top of the stack. If the stack is empty or the top doesn't match, the string is invalid.
  * **Pattern:** **Stack**

**3. Solution (C++)**

```cpp
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> openStack;
        // Map closing brackets to their open counterparts
        std::unordered_map<char, char> matches = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (matches.count(c)) {
                // This is a closing bracket
                if (openStack.empty() || openStack.top() != matches[c]) {
                    return false; // No matching open bracket
                }
                openStack.pop();
            } else {
                // This is an opening bracket
                openStack.push(c);
            }
        }
        
        // A valid string means all open brackets were closed
        return openStack.empty();
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We iterate the string once, and all stack operations are $O(1)$.
  * **Space:** $O(N)$ in the worst case (e.g., `((((...))))`).

-----

### Same Tree (\#100)

**1. Question & Constraints**

  * **Question:** Given the roots of two binary trees, `p` and `q`, check if they are identical. Two trees are identical if they have the same structure and the same node values.
  * **Constraints:**
      * `0 <= Number of nodes <= 100`

**2. Intuition & Pattern**

  * **Intuition:** This problem is naturally recursive. Two trees `p` and `q` are identical if:
    1.  Their root values are the same (`p->val == q->val`).
    2.  `p`'s left subtree is identical to `q`'s left subtree.
    3.  `p`'s right subtree is identical to `q`'s right subtree.
  * We must also handle the base cases where nodes are `nullptr`.
  * **Pattern:** **Tree Traversal (DFS/Recursion)**

**3. Solution (C++)**

```cpp
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. Base Case: Both are null, they are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // 2. Base Case: One is null or values differ, not the same
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        // 3. Recursive Step: Check left and right subtrees
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$, where $N$ is the number of nodes in the smaller tree. We must visit each node.
  * **Space:** $O(H)$, where $H$ is the height of the tree, for the recursion stack. $O(\log N)$ on average, $O(N)$ in the worst case (skewed tree).

-----

### Symmetric Tree (\#101)

**1. Question & Constraints**

  * **Question:** Given the `root` of a binary tree, check if it is a mirror image of itself (symmetric around its center).
  * **Constraints:**
      * `1 <= Number of nodes <= 1000`

**2. Intuition & Pattern**

  * **Intuition:** This is similar to "Same Tree" but with a twist. We can't just check `root->left` and `root->right` are "the same". We need to check if they are *mirrors* of each other.
  * We need a helper function `isMirror(t1, t2)` that checks if two trees are mirror images.
  * A tree is symmetric if `root->left` is a mirror of `root->right`.
  * `isMirror(t1, t2)` is true if:
    1.  `t1->val == t2->val`
    2.  `t1->left` is a mirror of `t2->right`
    3.  `t1->right` is a mirror of `t2->left`
  * **Pattern:** **Tree Traversal (DFS/Recursion)**

**3. Solution (C++)**

```cpp
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Base case: Both are null
        if (t1 == nullptr && t2 == nullptr) return true;
        
        // Base case: One is null or values differ
        if (t1 == nullptr || t2 == nullptr || t1->val != t2->val) return false;
        
        // Recursive step: Check outer vs. inner
        return isMirror(t1->left, t2->right) && 
               isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We visit each node once.
  * **Space:** $O(H)$ for the recursion stack. $O(\log N)$ average, $O(N)$ worst case.

-----

### Best Time to Buy and Sell Stock (\#121)

**1. Question & Constraints**

  * **Question:** Given an array `prices` where `prices[i]` is the price of a stock on day `i`, find the maximum profit you can make. You can only buy once and sell once. You must buy *before* you sell.
  * **Constraints:**
      * `1 <= prices.length <= 10^5`
      * `0 <= prices[i] <= 10^4`

**2. Intuition & Pattern**

  * **Intuition:** We want to find the largest difference `prices[j] - prices[i]` where `j > i`.
  * We can do this in a single pass. As we iterate through the prices, we keep track of two things:
    1.  `minPrice`: The lowest stock price seen so far.
    2.  `maxProfit`: The maximum profit seen so far.
  * For each `price`, we first update `minPrice`. Then, we check if selling at the current `price` would give us a new `maxProfit`.
  * **Pattern:** **One-pass Greedy**

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = std::numeric_limits<int>::max();
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < minPrice) {
                // New lowest price to buy
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                // A new best day to sell
                maxProfit = price - minPrice;
            }
        }
        
        return maxProfit;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We iterate the array once.
  * **Space:** $O(1)$. We only use two variables.

-----

### Diameter of Binary Tree (\#543)

**1. Question & Constraints**

  * **Question:** Find the length of the *diameter* of a binary tree. The diameter is the longest path between any two nodes. This path may or may not pass through the root.
  * **Constraints:**
      * `1 <= Number of nodes <= 10^4`
      * The path length is the number of *edges* between nodes.

**2. Intuition & Pattern**

  * **Intuition:** For any node, the longest path that *passes through it* is `(depth of left subtree) + (depth of right subtree)`.
  * The diameter of the whole tree is the *maximum* of these paths, calculated for *every node*.
  * We can use a single **DFS** (recursion) to find this. We need a helper function that does two things:
    1.  **Returns** the depth of the current node (max of left/right depth + 1).
    2.  **Updates** a global `maxDiameter` variable using the `left + right` path.
  * **Pattern:** **Tree Traversal (DFS)** with **Global Max Update**

**3. Solution (C++)**

```cpp
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
private:
    int diameter = 0;

    /**
     * Helper function returns the *depth* of this node.
     * It also updates the global 'diameter' variable.
     */
    int get_depth(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Depth of a null node is 0
        }
        
        // Get depths of children
        int leftDepth = get_depth(node->left);
        int rightDepth = get_depth(node->right);
        
        // Update diameter: the path *through* this node
        // is leftDepth + rightDepth
        diameter = std::max(diameter, leftDepth + rightDepth);
        
        // Return the depth *from* this node
        // (for the parent's calculation)
        return 1 + std::max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        get_depth(root);
        return diameter;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(N)$. We visit each node exactly once.
  * **Space:** $O(H)$ for the recursion stack. $O(\log N)$ on average, $O(N)$ worst case.