Here is a breakdown of those Dynamic Programming patterns in a tabular format, including their core ideas, common data structures, and typical time complexities.

---

## Pattern 1: Fibonacci / Simple Recurrence

These problems are the simplest form of DP, where the solution for the current state $dp[i]$ depends only on a fixed number of previous states (e.g., $dp[i-1]$ or $dp[i-2]$).

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Climbing Stairs | $dp[i] = dp[i-1] + dp[i-2]$. The number of ways to reach step $i$ is the sum of ways to reach $i-1$ and $i-2$. | 1D Array `dp[n]`. Can be optimized to $O(1)$ space. | $O(N)$ |
| Min Cost Climbing Stairs | $dp[i] = \text{cost}[i] + \min(dp[i-1], dp[i-2])$. The min cost to reach step $i$ is its cost plus the min cost of the previous two steps. | 1D Array `dp[n]`. Can be optimized to $O(1)$ space. | $O(N)$ |
| Dice Combinations | $dp[i] = \sum_{k=1}^6 dp[i-k]$. The number of ways to sum to $i$ is the sum of ways to reach $i$ from the 6 possible previous dice rolls. | 1D Array `dp[n]`. | $O(N \cdot K)$ (Here $K=6$) |
| Range Sum Query - Immutable | $dp[i] = dp[i-1] + \text{nums}[i]$. $dp$ is a prefix sum array. $\text{Sum}(i, j) = dp[j] - dp[i-1]$. | 1D Array (Prefix Sum Array). | $O(N)$ for precomputation, $O(1)$ per query. |

---

## Pattern 2: 0/1 Knapsack

For each item, you have two mutually exclusive choices: **take it** (once) or **leave it**. This pattern is used for problems involving subset selection to optimize a value under some constraint.

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Target Sum | $dp[i][j]$ = number of ways to get sum $j$ using first $i$ items. Recurrence: $dp[i-1][j]$ (leave) $+ dp[i-1][j - \text{val}]$ (take). | 2D Array `dp[N][Sum]`, often optimized to 1D `dp[Sum]`. | $O(N \cdot \text{Sum})$ |
| Partition Equal Subset Sum | $dp[j]$ = boolean, can a sum of $j$ be made? Iterate items, $dp[j] = dp[j] \text{ OR } dp[j - \text{val}]$. Final check: $dp[\text{TotalSum} / 2]$. | 1D Array (boolean or int) `dp[Sum]`. | $O(N \cdot \text{Sum})$ |
| Knapsack | $dp[w]$ = max value for a knapsack of capacity $w$. Iterate items, then $w$ from max to 0: $dp[w] = \max(dp[w], dp[w - \text{weight}] + \text{value})$. | 1D Array `dp[Capacity]`. | $O(N \cdot W)$ |

---

## Pattern 3: Unbounded Knapsack

Similar to 0/1 Knapsack, but you can use each item an **unlimited** number of times.

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Coin Change | $dp[i]$ = min coins to make amount $i$. $dp[i] = 1 + \min(dp[i - \text{coin}])$ for all coins. | 1D Array `dp[Amount]`. | $O(N \cdot \text{Amount})$ |
| Coin Combinations I | $dp[i]$ = num ways to make amount $i$. $dp[i] = \sum(dp[i - \text{coin}])$ for all coins. | 1D Array `dp[Amount]`. | $O(N \cdot \text{Amount})$ |
| Cutting Rod | $dp[i]$ = max value for a rod of length $i$. $dp[i] = \max(dp[i], \text{price}[j] + dp[i-j])$ for all possible cut lengths $j$. | 1D Array `dp[Length]`. | $O(N^2)$ |

---

## Pattern 4: Longest Common Subsequence (LCS)

These problems involve two sequences (strings or arrays). The state $dp[i][j]$ typically represents the solution for the prefixes $\text{seq1}[0...i]$ and $\text{seq2}[0...j]$.

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| LCS / Uncrossed Lines | $dp[i][j]$ = LCS of $A[0..i]$ and $B[0..j]$. If $A[i] == B[j]$, $dp[i][j] = 1 + dp[i-1][j-1]$. Else, $dp[i][j] = \max(dp[i-1][j], dp[i][j-1])$. | 2D Array `dp[M][N]`. | $O(M \cdot N)$ |
| Edit Distance | $dp[i][j]$ = min ops to convert $S1[0..i]$ to $S2[0..j]$. Ops: $\min(\text{insert}, \text{delete}, \text{replace})$. | 2D Array `dp[M][N]`. | $O(M \cdot N)$ |
| Word Break | $dp[i]$ = boolean, can $S[0..i]$ be segmented? $dp[i] = \text{True}$ if $dp[j]$ is $\text{True}$ and $S[j..i]$ is in the dictionary, for any $j < i$. | 1D Array `dp[N]` and a HashSet (for dictionary). | $O(N^2 \cdot L)$ or $O(N^3)$ |

---

## Pattern 5: Longest Increasing Subsequence (LIS)

These problems find the longest (or count of) subsequences that follow a certain property (e.g., increasing).

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| LIS | $dp[i]$ = length of LIS *ending at* index $i$. $dp[i] = 1 + \max(dp[j])$ for all $j < i$ where $A[j] < A[i]$. | 1D Array `dp[N]`. | $O(N^2)$ (or $O(N \log N)$ with binary search) |
| Number of LIS | Two arrays: $len[i]$ = length of LIS ending at $i$, $count[i]$ = count of LIS ending at $i$. | Two 1D Arrays `len[N]`, `count[N]`. | $O(N^2)$ |
| Vacation | $dp[i][j]$ = max happiness on day $i$ choosing activity $j$. $dp[i][j] = A[i][j] + \max(dp[i-1][k])$ for $k \ne j$. | 2D Array `dp[Days][3]`. | $O(N)$ (since $K=3$ is constant) |

---

## Pattern 6: Grid-Based DP

The state $dp[i][j]$ represents the solution for the cell at $(i, j)$ in a matrix. The solution is built from adjacent cells (e.g., top, left).

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Unique Paths | $dp[i][j]$ = num paths to reach $(i, j)$. $dp[i][j] = dp[i-1][j] + dp[i][j-1]$. | 2D Array `dp[M][N]`, can be optimized to 1D `dp[N]`. | $O(M \cdot N)$ |
| Grid Paths / Grid 1 | $dp[i][j]$ = num paths to reach $(i, j)$ (with obstacles). Same as Unique Paths, but $dp[i][j] = 0$ if $(i, j)$ is an obstacle. | 2D Array `dp[M][N]`. | $O(M \cdot N)$ |

---

## Pattern 7: Interval DP

The state $dp[i][j]$ represents the solution for the sub-interval from index $i$ to $j$. The solution is built by iterating over all possible split points $k$ within the interval.

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Burst Balloons | $dp[i][j]$ = max coins from bursting balloons in $(i, j)$. Iterate $k$ as the *last* balloon to burst in $(i, j)$. $dp[i][j] = \max(dp[i][k] + \text{val} + dp[k][j])$. | 2D Array `dp[N][N]`. | $O(N^3)$ |
| Palindrome Partitioning II | $dp[i]$ = min cuts for $S[i..N]$. Precompute all palindromes $isPal[i][j]$. $dp[i] = \min(1 + dp[j+1])$ for all $j$ where $isPal[i][j]$ is $\text{True}$. | 1D Array `dp[N]` and 2D Array `isPal[N][N]`. | $O(N^2)$ |
| Longest Palindromic Substring | $dp[i][j]$ = boolean, is $S[i..j]$ a palindrome? $dp[i][j] = (S[i] == S[j]) \text{ AND } dp[i+1][j-1]$. | 2D Array (boolean) `dp[N][N]`. | $O(N^2)$ |

---

## Pattern 8: Tree DP

DP state is computed from the children of a node during a traversal (usually DFS). The state $dp[u]$ often stores multiple values (e.g., max value if $u$ is taken vs. not taken).

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| House Robber III | $dp[u]$ = a pair $(\text{with}, \text{without})$, max money from $u$'s subtree if we *rob* $u$ vs. *don't rob* $u$. | Graph (Adjacency List), Recursion (DFS), Memoization (Map/Array). | $O(N)$ |
| Tree Matching | $dp[u][0]$ = max matching in $u$'s subtree if $u$ is not matched. $dp[u][1]$ = max matching if $u$ is matched. | Graph, Recursion (DFS), Memoization. | $O(N)$ |
| House Robber / II | (These are 1D DP, not Tree DP). $dp[i] = \max(dp[i-1], dp[i-2] + \text{nums}[i])$. House Robber II is solved by running this twice (on $0..N-2$ and $1..N-1$). | 1D Array `dp[N]`. | $O(N)$ |

---

## Pattern 9: Bitmasking / State Compression

Used when $N$ is very small (e.g., $N \le 20$). An integer (the "bitmask") is used to represent a subset of used items, visited nodes, etc. $dp[\text{mask}]$ stores the solution for that subset.

| Problem | Solving Pattern / Core Idea | Common DataStructures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Campus Bikes II | $dp[\text{mask}]$ = min cost to assign bikes to workers represented by mask. $k$-th bit = 1 if $k$-th worker is assigned. | 1D Array `dp[1 << N]`. | $O(2^N \cdot M)$ |
| Partition to K Equal Sum Subsets | $dp[\text{mask}]$ = sum of items used in $\text{mask}$. Check if $dp[(1 \ll N) - 1]$ is possible. | 1D Array `dp[1 << N]`. | $O(2^N \cdot N)$ |
| Traveling Salesman (TSP) | $dp[\text{mask}][i]$ = min cost to visit all nodes in $\text{mask}$, ending at node $i$. | 2D Array `dp[1 << N][N]`. | $O(2^N \cdot N^2)$ |

---

## Pattern 10: Digit DP

Used to count numbers in a range $[A, B]$ that satisfy a given property (e.g., "no repeated digits"). Solved by $\text{count}(B) - \text{count}(A-1)$.

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Numbers With Repeated Digits | $dp(\text{index}, \text{mask}, \text{isTight})$ = num valid numbers from $\text{index}$ on, given digits used in $\text{mask}$, and $\text{isTight}$ (are we bounded by $N$'s digits?). | Memoization Table (e.g., 3D Array), Recursion. | $O(D \cdot 2^{10} \cdot 2)$ (where $D \approx 10$) |
| Removing Digits | $dp[n]$ = min steps to reduce $n$ to 0. $dp[n] = 1 + \min(dp[n - d])$ for all digits $d$ in $n$. (This is a 1D DP, not Digit DP). | 1D Array `dp[N]`. | $O(N \log N)$ |

---

## Pattern 11: Probability / Expectation DP

The state $dp[i]$ represents the *probability* or *expected value* of a certain state. The recurrence relation is based on probability rules.

| Problem | Solving Pattern / Core Idea | Common Data Structures | Typical Time Complexity |
| :--- | :--- | :--- | :--- |
| Dice Roll Simulation | $dp[i][j]$ = num sequences of length $i$ ending with face $j$. Transition based on $rollMax$ constraints. | 2D Array `dp[N][6]`. | $O(N)$ |
| Coins | $dp[i][j]$ = probability of $j$ heads after $i$ coin tosses. $dp[i][j] = P(i) \cdot dp[i-1][j-1] + (1 - P(i)) \cdot dp[i-1][j]$. | 2D Array `dp[N][N]`. | $O(N^2)$ |
| Sushi | $dp[i][j][k]$ = expected rolls to 0, given $i$ 1-count, $j$ 2-count, $k$ 3-count sushis. Solved with E-value recurrence. | 3D Array `dp[N][N][N]`. | $O(N^3)$ |