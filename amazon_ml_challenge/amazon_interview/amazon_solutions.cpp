
// ============================================================================
// AMAZON SDE INTERVIEW QUESTIONS - C++ SOLUTIONS
// ============================================================================
// This document contains complete, production-quality solutions for top Amazon
// interview questions across all difficulty levels.
// ============================================================================

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <climits>
#include <memory>

using namespace std;

// ============================================================================
// EASY PROBLEMS
// ============================================================================

// ============================================================================
// PROBLEM 1: TWO SUM
// ============================================================================
// Question: Given array of integers and target, return indices of two numbers 
//           that add up to target. Each element used only once.
//
// Constraints:
//   - 2 <= nums.size() <= 10^4
//   - -10^9 <= nums[i] <= 10^9
//   - -10^9 <= target <= 10^9
//   - Exactly one solution exists
//
// Examples:
//   Input: nums = [2,7,11,15], target = 9
//   Output: [0,1] (because 2 + 7 = 9)
//
//   Input: nums = [3,3], target = 6
//   Output: [0,1]

// Approach 1: Hash Map (Optimal)
// Intuition: Store first element, check if complement exists
// Time: O(n), Space: O(n)
class TwoSumSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if complement exists in map
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }

            // Store current number and its index
            seen[nums[i]] = i;
        }

        return {};  // Should not reach here if guaranteed solution
    }
};

// Time Complexity: O(n) - single pass with O(1) hashmap operations
// Space Complexity: O(n) - hashmap can store up to n elements

// ============================================================================
// PROBLEM 2: CONTAINS DUPLICATE
// ============================================================================
// Question: Given array, return true if value appears at least twice
//
// Constraints:
//   - 1 <= nums.size() <= 10^5
//   - -10^9 <= nums[i] <= 10^9
//
// Examples:
//   Input: [1,2,3,1] -> true
//   Input: [1,2,3,4] -> false
//   Input: [99,99] -> true

// Approach: Hash Set
// Intuition: Track seen elements; if element in set, it's duplicate
// Time: O(n), Space: O(n)
class ContainsDuplicateSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;  // Duplicate found
            }
            seen.insert(num);
        }

        return false;
    }
};

// Time Complexity: O(n) - single pass with O(1) insert/lookup
// Space Complexity: O(n) - set stores unique elements

// ============================================================================
// PROBLEM 3: VALID PALINDROME
// ============================================================================
// Question: String with alphanumeric and special chars. Is it palindrome?
//           (Consider only alphanumeric characters, ignore case)
//
// Constraints:
//   - 1 <= s.length() <= 2*10^5
//   - s contains ASCII characters
//
// Examples:
//   Input: "A man, a plan, a canal: Panama" -> true
//   Input: "race a car" -> false
//   Input: " " -> true

// Approach: Two Pointer
// Intuition: Compare characters from ends, skip non-alphanumeric
// Time: O(n), Space: O(1)
class ValidPalindromeSolution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

// Time Complexity: O(n) - each character visited once
// Space Complexity: O(1) - only two pointers

// ============================================================================
// PROBLEM 4: CLIMBING STAIRS
// ============================================================================
// Question: Climbing n stairs, can take 1 or 2 steps each time.
//           How many distinct ways to climb?
//
// Constraints:
//   - 1 <= n <= 45
//
// Examples:
//   Input: n = 2 -> 2 (1+1 or 2)
//   Input: n = 3 -> 3 (1+1+1 or 1+2 or 2+1)
//   Input: n = 4 -> 5 (combinations of above)

// Approach 1: Dynamic Programming (Optimal)
// Intuition: dp[i] = dp[i-1] + dp[i-2] (Fibonacci!)
// Time: O(n), Space: O(1) optimized
class ClimbingStairsSolution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1;  // dp[0]
        int prev1 = 2;  // dp[1]

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

// Time Complexity: O(n) - single pass through n stairs
// Space Complexity: O(1) - only storing two previous values

// ============================================================================
// MEDIUM PROBLEMS
// ============================================================================

// ============================================================================
// PROBLEM 5: TWO SUM II - INPUT ARRAY IS SORTED
// ============================================================================
// Question: Sorted array + target, return indices [index1, index2]
//           index1 < index2, 1-indexed, exactly one solution
//
// Constraints:
//   - Array is sorted in non-decreasing order
//   - 2 <= numbers.length <= 3*10^4
//   - -10^9 <= numbers[i] <= 10^9
//   - -10^9 <= target <= 10^9
//
// Examples:
//   Input: [2,7,11,15], target=9 -> [1,2] (1-indexed)
//   Input: [2,3,4], target=6 -> [1,3]

// Approach: Two Pointer
// Intuition: Start from ends; sum too large? move right pointer left
// Time: O(n), Space: O(1)
class TwoSumII_Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};  // 1-indexed
            }
            else if (sum < target) {
                left++;  // Need larger sum
            }
            else {
                right--;  // Need smaller sum
            }
        }

        return {};  // Should not reach if solution guaranteed
    }
};

// Time Complexity: O(n) - each element visited at most once
// Space Complexity: O(1) - only two pointers, no extra space

// ============================================================================
// PROBLEM 6: 3SUM
// ============================================================================
// Question: Find all unique triplets summing to 0
//
// Constraints:
//   - 3 <= nums.length <= 3000
//   - -10^5 <= nums[i] <= 10^5
//   - Return unique triplets
//
// Examples:
//   Input: [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]
//   Input: [-2,0,1,1,2] -> [[-2,0,2],[-2,1,1]]

// Approach: Sort + Two Pointer
// Intuition: Fix one element, use two pointer for remaining two
// Time: O(n²), Space: O(1) if not counting output
class ThreeSumSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3) return result;

        // Sort for two-pointer approach and easy duplicate handling
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // If nums[i] > 0, no triplets sum to 0
            if (nums[i] > 0) break;

            // Two pointer approach for remaining two numbers
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};

// Time Complexity: O(n²) - O(n log n) sorting + O(n²) nested loops
// Space Complexity: O(1) or O(n) if counting output/sorting space

// ============================================================================
// PROBLEM 7: REVERSE STRING
// ============================================================================
// Question: Reverse character array in-place
//
// Constraints:
//   - 1 <= s.length <= 10^5
//   - s[i] is printable ASCII character
//
// Examples:
//   Input: ["h","e","l","l","o"] -> ["o","l","l","e","h"]

// Approach: Two Pointer Swap
// Intuition: Swap from both ends moving inward
// Time: O(n), Space: O(1)
class ReverseStringSolution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

// Time Complexity: O(n) - n/2 swaps
// Space Complexity: O(1) - no extra space except for swaps

// ============================================================================
// PROBLEM 8: MAXIMUM SUBARRAY (Kadane's Algorithm)
// ============================================================================
// Question: Find contiguous subarray with largest sum
//
// Constraints:
//   - 1 <= nums.length <= 10^5
//   - -10^4 <= nums[i] <= 10^4
//
// Examples:
//   Input: [-2,1,-3,4,-1,2,1,-5,4] -> 6 (subarray [4,-1,2,1])
//   Input: [5,4,-1,7,8] -> 23 (entire array)
//   Input: [-2] -> -2

// Approach: Kadane's Algorithm (DP)
// Intuition: Track max ending at current position and global max
// Time: O(n), Space: O(1)
class MaximumSubarraySolution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurrent = nums[0];  // Max sum ending at current index
        int maxGlobal = nums[0];   // Overall maximum

        for (int i = 1; i < nums.size(); i++) {
            // Either extend current subarray or start new
            maxCurrent = max(nums[i], maxCurrent + nums[i]);

            // Update global maximum
            maxGlobal = max(maxGlobal, maxCurrent);
        }

        return maxGlobal;
    }
};

// Time Complexity: O(n) - single pass with constant operations
// Space Complexity: O(1) - only two variables

// Explanation of Kadane's Algorithm:
// At each position, we decide: should we include current element in existing
// subarray or start a new subarray? We choose whichever gives larger sum.
// Example: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//   i=0: maxCur=-2, maxGlo=-2
//   i=1: maxCur=max(1,-2+1)=1, maxGlo=1
//   i=2: maxCur=max(-3,1-3)=-2, maxGlo=1
//   i=3: maxCur=max(4,-2+4)=4, maxGlo=4
//   i=4: maxCur=max(-1,4-1)=3, maxGlo=4
//   i=5: maxCur=max(2,3+2)=5, maxGlo=5
//   i=6: maxCur=max(1,5+1)=6, maxGlo=6
//   i=7: maxCur=max(-5,6-5)=1, maxGlo=6
//   i=8: maxCur=max(4,1+4)=5, maxGlo=6

// ============================================================================
// PROBLEM 9: SEARCH IN ROTATED SORTED ARRAY
// ============================================================================
// Question: Rotated sorted array, find target. If found return index, else -1.
//           Array originally sorted, rotated at some unknown pivot.
//
// Constraints:
//   - 1 <= nums.length <= 5000
//   - -10^4 <= nums[i] <= 10^4
//   - No duplicates
//   - nums is guaranteed to be rotated
//   - Must run in O(log n) time
//
// Examples:
//   Input: nums=[4,5,6,7,0,1,2], target=0 -> 4
//   Input: nums=[4,5,6,7,0,1,2], target=3 -> -1

// Approach: Binary Search (Modified)
// Intuition: Determine which half is sorted, search in appropriate half
// Time: O(log n), Space: O(1)
class SearchRotatedSortedArraySolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Determine which half is sorted
            if (nums[left] <= nums[mid]) {
                // Left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    // Target in sorted left half
                    right = mid - 1;
                }
                else {
                    // Target in right half
                    left = mid + 1;
                }
            }
            else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    // Target in sorted right half
                    left = mid + 1;
                }
                else {
                    // Target in left half
                    right = mid - 1;
                }
            }
        }

        return -1;  // Target not found
    }
};

// Time Complexity: O(log n) - binary search halves search space
// Space Complexity: O(1) - no extra space

// ============================================================================
// HARD PROBLEMS
// ============================================================================

// Definition for singly-linked list node (for Merge K Sorted Lists)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// ============================================================================
// PROBLEM 10: MERGE K SORTED LISTS
// ============================================================================
// Question: Given k sorted linked lists, merge into one sorted list
//
// Constraints:
//   - 0 <= k <= 10^4
//   - 0 <= sum of nodes <= 10^4
//   - -10^4 <= val <= 10^4
//
// Examples:
//   Input: [[1,4,5],[1,3,4],[2,6]] 
//   Output: [1,1,2,1,3,4,4,5,6]

// Approach 1: Min Heap (Optimal for large k)
// Intuition: Always pick smallest node from all k lists using heap
// Time: O(n log k) where n = total nodes, Space: O(k)
class MergeKSortedListsSolution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Min heap: {val, list_index, node}
        auto comp = [](pair<int, pair<int, ListNode*>>& a, 
                       pair<int, pair<int, ListNode*>>& b) {
            return a.first > b.first;  // Min heap
        };

        priority_queue<pair<int, pair<int, ListNode*>>, 
                      vector<pair<int, pair<int, ListNode*>>>,
                      decltype(comp)> minHeap(comp);

        // Add first node from each list to heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                minHeap.push({lists[i]->val, {i, lists[i]}});
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (!minHeap.empty()) {
            auto [val, idx_node] = minHeap.top();
            minHeap.pop();
            auto [listIdx, node] = idx_node;

            current->next = node;
            current = current->next;

            // Add next node from same list
            if (node->next) {
                minHeap.push({node->next->val, {listIdx, node->next}});
            }
        }

        return dummy->next;
    }
};

// Time Complexity: O(n log k) - n total nodes, each inserted/deleted from heap of size k
// Space Complexity: O(k) - heap stores at most k nodes

// Approach 2: Divide & Conquer (Alternative, cleaner)
// Time: O(n log k), Space: O(log k) recursion depth
class MergeKSortedLists_DivideConquerSolution {
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeKLists(lists, left, mid);
        ListNode* l2 = mergeKLists(lists, mid + 1, right);

        return merge2Lists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};

// ============================================================================
// PROBLEM 11: WORD BREAK II
// ============================================================================
// Question: Given string and word dictionary, return all possible sentences
//
// Constraints:
//   - 1 <= s.length <= 20
//   - 1 <= wordDict.length <= 1000
//   - 1 <= wordDict[i].length <= 10
//   - All strings unique
//
// Examples:
//   Input: s="pineapplepenapple", wordDict=["apple","pen","applepen","pine","pineapple"]
//   Output: ["pine apple pen apple","pineapple pen apple"]

// Approach: DFS + Memoization (Backtracking)
// Intuition: Build word breaks recursively with memoization
// Time: O(n^n) worst case, Space: O(n^2)
class WordBreakII_Solution {
private:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return backtrack(s);
    }

private:
    vector<string> backtrack(string s) {
        if (memo.count(s)) {
            return memo[s];
        }

        vector<string> result;

        // Base case: empty string
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        // Try each word in dictionary
        for (const string& word : wordSet) {
            if (s.find(word) == 0) {  // String starts with word
                vector<string> subproblems = backtrack(s.substr(word.length()));

                for (const string& sub : subproblems) {
                    string combined = word + (sub.empty() ? "" : " " + sub);
                    result.push_back(combined);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};

// Time Complexity: O(n^n) worst case when all substrings are valid words
// Space Complexity: O(n^2) for memoization storage

// ============================================================================
// COMPLEXITY SUMMARY
// ============================================================================
/*
PROBLEM                          TIME              SPACE             PATTERN
1. Two Sum                       O(n)              O(n)              Hash Map
2. Contains Duplicate            O(n)              O(n)              Hash Set
3. Valid Palindrome              O(n)              O(1)              Two Pointer
4. Climbing Stairs               O(n)              O(1)              DP/Fibonacci
5. Two Sum II (Sorted)           O(n)              O(1)              Two Pointer
6. 3Sum                          O(n²)             O(1)              Sort + Two Ptr
7. Reverse String                O(n)              O(1)              Two Pointer
8. Maximum Subarray              O(n)              O(1)              Kadane's DP
9. Search Rotated Array          O(log n)          O(1)              Binary Search
10. Merge K Sorted Lists         O(n log k)        O(k)              Heap / D&C
11. Word Break II                O(n^n)            O(n²)             DFS + Memo

KEY PATTERNS:
- Hash Set/Map: Duplicate detection, complement finding
- Two Pointers: Palindrome, sorted array, target matching
- Binary Search: Sorted arrays, O(log n) requirement
- DP: Optimal substructure, overlapping subproblems
- Heap: K-way merge, top-K problems
- DFS + Memo: Backtracking with repeated subproblems
*/

