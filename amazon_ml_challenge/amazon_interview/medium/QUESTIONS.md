Based on the "Hard Problems" listed in the image, here is a complete breakdown for each one, including the question, constraints, intuition, C++ solution, and time complexity.

-----

### Median of Two Sorted Arrays (\#4)

**1. Question & Constraints**

  * **Question:** Given two sorted arrays, `nums1` and `nums2`, of size `m` and `n` respectively, find the median of the two combined sorted arrays.
  * **Constraints:**
      * `nums1.length == m`, `nums2.length == n`
      * `0 <= m, n <= 1000`
      * `1 <= m + n <= 2000`
      * The values are typically within $-10^6$ and $10^6$.
      * **Key Constraint:** The overall time complexity must be $O(\log(m+n))$.

**2. Intuition & Pattern**

  * **Intuition:** A naive $O(m+n)$ solution is to merge the arrays. The $O(\log(m+n))$ constraint strongly implies a **Binary Search**.
  * The median is the value that partitions the combined set into two equal halves. We can binary search for the correct *partition* in the smaller array (`nums1`) and deduce the corresponding partition in `nums2`.
  * We're looking for a `partition1` (in `nums1`) and `partition2` (in `nums2`) such that:
    1.  All elements in the "left half" are $\le$ all elements in the "right half".
    2.  The total number of elements in the left halves is $(m+n+1)/2$.
  * We check the partition by comparing the boundary elements: `maxLeft1 <= minRight2` and `maxLeft2 <= minRight1`. If the condition isn't met, we adjust the binary search.
  * **Pattern:** **Binary Search on Answer** (specifically, on the partition index).

**3. Solution (C++)**

```cpp
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for binary search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        int totalLeft = (n1 + n2 + 1) / 2; // Total elements in the combined left half

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = totalLeft - partition1;

            // Get boundary elements, handling edge cases
            int maxLeft1 = (partition1 == 0) ? numeric_limits<int>::min() : nums1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? numeric_limits<int>::max() : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? numeric_limits<int>::min() : nums2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? numeric_limits<int>::max() : nums2[partition2];

            // Check if partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found the median
                if ((n1 + n2) % 2 == 0) { // Even total length
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else { // Odd total length
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // partition1 is too large, move left
                high = partition1 - 1;
            } else {
                // partition1 is too small, move right
                low = partition1 + 1;
            }
        }
        return 0.0; // Should not be reached
    }
};
```

**4. Time Complexities**

  * **Time:** $O(\log(\min(m, n)))$. We perform a binary search on the *smaller* of the two arrays.
  * **Space:** $O(1)$.

-----

### Merge K Sorted Lists (\#23)

**1. Question & Constraints**

  * **Question:** You are given an array of `k` sorted linked lists. Merge all the linked lists into one sorted linked list and return its head.
  * **Constraints:**
      * `k == lists.length`
      * `0 <= k <= 10^4`
      * `0 <= lists[i].length <= 500`
      * Total number of nodes will not exceed $10^4$.

**2. Intuition & Pattern**

  * **Intuition:** We always need the *smallest* node from the current heads of all `k` lists. This problem is a classic **K-way Merge**.
  * The most efficient way to repeatedly find the minimum element from `k` sources is to use a **Min-Heap (Priority Queue)**.
  * **Strategy:**
    1.  Create a min-heap that stores `ListNode*`.
    2.  Insert the head node of all `k` lists into the heap.
    3.  Create a `dummy` node to build the new list.
    4.  While the heap is not empty:
        a.  Extract the smallest node (`minNode`) from the heap.
        b.  Append `minNode` to the result list.
        c.  If `minNode->next` is not null, insert it into the heap.
  * **Pattern:** **K-way Merge** using a **Min-Heap**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for the priority queue
struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        // 1. Push the head of each list into the min-heap
        for (ListNode* head : lists) {
            if (head) {
                minHeap.push(head);
            }
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;

        // 2. Process the heap
        while (!minHeap.empty()) {
            // 3a. Extract the smallest node
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            // 3b. Append to result
            tail->next = minNode;
            tail = tail->next;

            // 3c. Push next element (if exists)
            if (minNode->next) {
                minHeap.push(minNode->next);
            }
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
```

**4. Time Complexities**

  * $N$ = total number of nodes in all lists.
  * $k$ = number of lists.
  * **Time:** $O(N \log k)$. Every node is pushed and popped from the heap once ($N$ operations). Each heap operation costs $O(\log k)$.
  * **Space:** $O(k)$ to store at most `k` nodes in the min-heap.

-----

### Word Ladder (\#127)

**1. Question & Constraints**

  * **Question:** Given a `beginWord`, an `endWord`, and a `wordList`, find the length of the *shortest* transformation sequence from `beginWord` to `endWord`.
      * Only one letter can be changed at a time.
      * Each transformed word must exist in the `wordList`.
  * **Constraints:**
      * `1 <= beginWord.length <= 10`
      * `wordList.length <= 5000`
      * Words are all the same length.
      * `beginWord != endWord`.

**2. Intuition & Pattern**

  * **Intuition:** "Shortest path" in an unweighted graph suggests **Breadth-First Search (BFS)**.
  * We can think of each word as a node in a graph. An edge exists between two words if they are one letter different.
  * **Strategy:**
    1.  Start a BFS from `beginWord`.
    2.  Keep a `visited` set to avoid cycles.
    3.  Store the `wordList` in a hash set for $O(1)$ lookup.
    4.  In each BFS level, take a word, generate all its 1-letter-different "neighbors" by iterating `a-z` for each character position.
    5.  If a neighbor is in the `wordList` and not `visited`, add it to the queue and the `visited` set.
    6.  The first time we find `endWord`, the current level is the shortest path length.
  * **Pattern:** **Graph Traversal (BFS)** for shortest path.

**3. Solution (C++)**

```cpp
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return 0; // endWord is not in the list
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // {word, level}

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            string currentWord = q.front().first;
            int level = q.front().second;
            q.pop();

            if (currentWord == endWord) {
                return level;
            }

            // Find neighbors
            for (int i = 0; i < currentWord.length(); ++i) {
                string tempWord = currentWord;
                for (char c = 'a'; c <= 'z'; ++c) {
                    tempWord[i] = c;
                    
                    if (dict.find(tempWord) != dict.end() && visited.find(tempWord) == visited.end()) {
                        q.push({tempWord, level + 1});
                        visited.insert(tempWord);
                    }
                }
            }
        }
        return 0; // No path found
    }
};
```

**4. Time Complexities**

  * $N$ = number of words in `wordList`.
  * $L$ = length of each word.
  * **Time:** $O(N \cdot L^2)$. In the worst case, we visit all $N$ words. For each word, we generate neighbors, which takes $L$ (positions) \* 26 (chars) \* $L$ (string creation/hashing) = $O(L^2)$.
  * **Space:** $O(N)$ for the queue and `visited` set.

-----

### Word Ladder II (\#126)

**1. Question & Constraints**

  * **Question:** Same as Word Ladder I, but now you must return *all* shortest transformation sequences.
  * **Constraints:** Similar to Word Ladder I, but often with smaller $N$ (e.g., $N \le 1000$) because the number of paths can be large.

**2. Intuition & Pattern**

  * **Intuition:** We still need a **BFS** to find the shortest path *length*. A simple BFS won't work, as we need *all* paths.
  * **Strategy:**
    1.  **BFS:** Run a BFS to build a "parent" map (`adj`) and find the minimum distance to each word. The `adj` map should store `adj[child] -> {parent1, parent2, ...}`. We only add a parent if the path to the child is part of *a* shortest path (i.e., `dist[parent] + 1 == dist[child]`). We must use a level-by-level BFS to ensure we find all parents at the same (shortest) distance.
    2.  **DFS:** Once the BFS is complete and we know the shortest path to `endWord` exists, we run a **DFS (Backtracking)** starting from `endWord`. We walk *backward* through the `adj` map to `beginWord` to reconstruct all the shortest paths.
  * **Pattern:** **BFS (for shortest path/graph building) + DFS (for path reconstruction)**.

**3. Solution (C++)**

```cpp
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> adj; // Stores graph: child -> {parents}
    vector<vector<string>> allPaths;
    vector<string> currentPath;

    // DFS to find paths by backtracking from endWord
    void findPaths(string& word, string& beginWord) {
        currentPath.push_back(word);
        
        if (word == beginWord) {
            // Base case: reached start
            vector<string> path = currentPath;
            reverse(path.begin(), path.end());
            allPaths.push_back(path);
        } else {
            // Recurse on parents
            for (string& parent : adj[word]) {
                findPaths(parent, beginWord);
            }
        }
        
        currentPath.pop_back(); // Backtrack
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};

        queue<string> q;
        q.push(beginWord);
        
        unordered_map<string, int> dist; // Distance from beginWord
        dist[beginWord] = 1;
        
        bool found = false;

        // BFS to build distance map and adjacency list
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string word = q.front();
                q.pop();

                if (word == endWord) found = true;

                string tempWord = word;
                for (int j = 0; j < word.length(); ++j) {
                    char originalChar = tempWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tempWord[j] = c;
                        if (dict.count(tempWord)) {
                            if (!dist.count(tempWord)) {
                                // First time visiting
                                dist[tempWord] = dist[word] + 1;
                                adj[tempWord].push_back(word);
                                q.push(tempWord);
                            } else if (dist[tempWord] == dist[word] + 1) {
                                // Found another path of the same shortest length
                                adj[tempWord].push_back(word);
                            }
                        }
                    }
                    tempWord[j] = originalChar; // Reset
                }
            }
            if (found) break; // Stop BFS once shortest level is found
        }

        // Step 2: DFS Backtracking
        if (found) {
            findPaths(endWord, beginWord);
        }
        return allPaths;
    }
};
```

**4. Time Complexities**

  * $N$ = number of words, $L$ = length of words.
  * **Time:** $O(N \cdot L^2)$ for the BFS part. The DFS part can be exponential in the worst case, $O(N!)$, if the graph of shortest paths is dense.
  * **Space:** $O(N \cdot N)$ in the worst case for the `adj` map, plus space for the paths.

-----

### Word Search II (\#212)

**1. Question & Constraints**

  * **Question:** Given a 2D `board` of characters and a list of `words`, find all words from the list that can be formed by a sequence of adjacent (horizontal or vertical) cells. A cell cannot be used more than once in the same word.
  * **Constraints:**
      * `1 <= m, n <= 12`
      * `1 <= words.length <= 3 * 10^4`
      * `1 <= words[i].length <= 10`

**2. Intuition & Pattern**

  * **Intuition:** A naive solution would be to run a "Word Search I" (DFS) for *every* word in the list. This is $O(K \cdot (M \cdot N) \cdot 4^L)$ (where $K$ is num words), which is too slow.
  * We need to search for all words *simultaneously*. A **Trie (Prefix Tree)** is perfect for this.
  * **Strategy:**
    1.  Insert all `words` into a Trie. Store the full word at the end node.
    2.  Start a **Backtracking DFS** from *every* cell of the `board`.
    3.  As we move on the `board`, we also move down the Trie.
    4.  If the current path on the board doesn't match a path in the Trie, we can **prune** the search (backtrack).
    5.  If we reach a Trie node that marks the end of a word, add that word to our result set.
  * **Pattern:** **Trie (Prefix Tree) + Backtracking (DFS)**.

**3. Solution (C++)**

```cpp
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 1. Trie Node Structure
struct TrieNode {
    TrieNode* children[26];
    string word; // Store the full word at the end node

    TrieNode() : word("") {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;
    vector<string> result;
    int rows, cols;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // 2. Build Trie
    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->word = word; // Store the word
    }

    // 3. DFS on Board
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];
        int i = ch - 'a';

        // Pruning: char is visited ('#') or path doesn't exist in trie
        if (ch == '#' || node->children[i] == nullptr) {
            return;
        }

        node = node->children[i];

        // Found a word
        if (node->word != "") {
            result.push_back(node->word);
            node->word = ""; // Avoid adding the same word multiple times
        }

        // Mark visited
        board[r][c] = '#';

        // Explore neighbors
        for (int k = 0; k < 4; ++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                dfs(board, nr, nc, node);
            }
        }

        // Backtrack
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string& word : words) {
            insert(word);
        }

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};
```

**4. Time Complexities**

  * $M \cdot N$ = board size.
  * $K$ = number of words.
  * $L$ = max length of a word.
  * **Time:** $O(K \cdot L + M \cdot N \cdot 4^L)$.
      * $O(K \cdot L)$ to build the Trie.
      * $O(M \cdot N \cdot 4^L)$ for the DFS. $M \cdot N$ is the starting points, $4^L$ is the worst-case exploration. This is heavily pruned by the Trie.
  * **Space:** $O(K \cdot L)$ for the Trie.

-----

### Integer to English Words (\#273)

**1. Question & Constraints**

  * **Question:** Convert a non-negative integer to its English words representation.
  * **Constraints:**
      * `0 <= num <= 2^31 - 1` (standard 32-bit signed integer).

**2. Intuition & Pattern**

  * **Intuition:** This is a **Simulation / String Manipulation** problem, not a complex algorithm.
  * The number can be broken into repeating chunks of three (hundreds, tens, ones).
  * **Strategy:**
    1.  Create maps for `1-19`, `20-90` (tens).
    2.  Create a helper function `chunkToWords(int n)` that converts any number from 0-999 into words.
    3.  In the main function, process the input `num` by repeatedly taking `num % 1000`.
    4.  Call `chunkToWords()` on this chunk and append the correct suffix ("Thousand", "Million", "Billion") based on which chunk it is.
    5.  Handle spaces and zero-chunks carefully.
  * **Pattern:** **Recursive Decomposition** / **Simulation**.

**3. Solution (C++)**

```cpp
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    // Helper for 0-999
    string chunkToWords(int n) {
        if (n == 0) return "";
        
        string res = "";
        if (n < 20) {
            res = ones[n];
        } else if (n < 100) {
            res = tens[n / 10] + (n % 10 == 0 ? "" : " " + ones[n % 10]);
        } else {
            res = ones[n / 100] + " Hundred" + (n % 100 == 0 ? "" : " " + chunkToWords(n % 100));
        }
        return res;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result = "";
        int i = 0; // Index for thousands array

        while (num > 0) {
            int chunk = num % 1000;
            if (chunk != 0) {
                string chunkWords = chunkToWords(chunk);
                result = chunkWords + (thousands[i] == "" ? "" : " " + thousands[i]) + (result == "" ? "" : " " + result);
            }
            num /= 1000;
            i++;
        }
        return result;
    }
};
```

**4. Time Complexities**

  * **Time:** $O(1)$. The input is bounded. The number of digits $\log_{10}(N)$ is at most $\sim 10$. The number of chunks is constant (max 4).
  * **Space:** $O(1)$. The output string length is bounded.

-----

### Find Median from Data Stream (\#295)

**1. Question & Constraints**

  * **Question:** Design a class `MedianFinder` with two methods:
    1.  `addNum(int num)`: Adds an integer to the data structure.
    2.  `findMedian()`: Returns the median of all elements added so far.
  * **Constraints:**
      * `addNum` and `findMedian` will be called many times (e.g., up to $5 \cdot 10^4$ calls).

**2. Intuition & Pattern**

  * **Intuition:** We need to efficiently find the middle element(s). We don't need the whole stream to be sorted, just to know where the split is.
  * We can maintain two halves of the data:
    1.  A **Max-Heap** (`lowHalf`) to store the smaller half of the numbers.
    2.  A **Min-Heap** (`highHalf`) to store the larger half of the numbers.
  * **Invariants:**
    1.  `lowHalf.max() <= highHalf.min()`.
    2.  `lowHalf.size()` is either equal to `highHalf.size()` or one larger.
  * **`addNum(num)`:**
    1.  Add `num` to `lowHalf`.
    2.  To maintain invariant \#1, pop the largest from `lowHalf` and push it to `highHalf`.
    3.  To maintain invariant \#2, if `highHalf` is now larger, pop its smallest and push it to `lowHalf`.
  * **`findMedian()`:**
      * If sizes are equal (even total), median is `(lowHalf.top() + highHalf.top()) / 2.0`.
      * If `lowHalf` is larger (odd total), median is `lowHalf.top()`.
  * **Pattern:** **Two Heaps (Max-Heap + Min-Heap)**.

**3. Solution (C++)**

```cpp
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    // lowHalf: Max-heap for the smaller half of numbers
    priority_queue<int> lowHalf; 
    
    // highHalf: Min-heap for the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> highHalf;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // 1. Add to max-heap (low half)
        lowHalf.push(num);

        // 2. Balance Invariant 1: lowHalf.max <= highHalf.min
        // Move the largest from lowHalf to highHalf
        highHalf.push(lowHalf.top());
        lowHalf.pop();

        // 3. Re-balance Invariant 2: |lowHalf| >= |highHalf|
        // If highHalf has more elements, move one back to lowHalf
        if (highHalf.size() > lowHalf.size()) {
            lowHalf.push(highHalf.top());
            highHalf.pop();
        }
    }
    
    double findMedian() {
        if (lowHalf.size() > highHalf.size()) {
            // Odd number of elements
            return lowHalf.top();
        } else {
            // Even number of elements
            return (lowHalf.top() + highHalf.top()) / 2.0;
        }
    }
};
```

**4. Time Complexities**

  * $N$ = number of elements added so far.
  * **`addNum(num)`:** $O(\log N)$. We perform 2-3 heap insertions/deletions, each $O(\log N)$.
  * **`findMedian()`:** $O(1)$. We just peek at the top element(s) of the heaps.
  * **Space:** $O(N)$ to store all the numbers in the heaps.