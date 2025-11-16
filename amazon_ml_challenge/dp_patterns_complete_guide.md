# Dynamic Programming Patterns: Complete Reference Guide

## 📊 Overview: 37 Problems Across 11 Patterns

---

## Pattern 1: Fibonacci / Simple Recurrence
**Core Concept:** State depends on previous 1-2 states | **Complexity:** O(n) time, O(1) space optimized

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Climbing Stairs | Easy | O(n) | O(1) | dp[i] = dp[i-1] + dp[i-2] |
| Min Cost Climbing Stairs | Easy | O(n) | O(1) | dp[i] = cost[i] + min(dp[i-1], dp[i-2]) |
| Dice Combinations | Medium | O(n) | O(n) | Sum ways from previous 6 positions |
| Range Sum Query | Easy | O(1) query | O(n) | Prefix sum: prefix[i] = prefix[i-1] + nums[i] |

---

## Pattern 2: 0/1 Knapsack
**Core Concept:** Include or exclude each item once | **Complexity:** O(n * W) time, O(W) space optimized

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Target Sum | Medium | O(n * sum) | O(sum) | Convert to subset sum: (total-target)/2 |
| Partition Equal Subset Sum | Medium | O(n * sum) | O(sum) | Can make subset with sum = total/2? |
| 0/1 Knapsack | Medium | O(n * W) | O(W) | dp[i][w] = max(exclude, include) |
| Combination Sum IV | Medium | O(target * n) | O(target) | Order matters - try all at each step |

---

## Pattern 3: Unbounded Knapsack
**Core Concept:** Can use items unlimited times | **Complexity:** O(n * W) time, O(W) space

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Coin Change | Medium | O(amount * coins) | O(amount) | dp[i] = min coins to make amount i |
| Coin Combinations I | Medium | O(n * sum) | O(sum) | Iterate coins first (avoid permutations) |
| Cutting Rod | Medium | O(n²) | O(n) | Try all cuts; maximize revenue |

---

## Pattern 4: Longest Common Subsequence (LCS)
**Core Concept:** Match or skip in two sequences | **Complexity:** O(m * n) time, O(m * n) space

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Uncrossed Lines | Medium | O(m * n) | O(n) opt | Same as LCS matching problem |
| Edit Distance | Hard | O(m * n) | O(m * n) | Insert, delete, or replace operations |
| Longest Common Subsequence | Medium | O(m * n) | O(m * n) | Match: 1+dp[i-1][j-1], else: max |
| Word Break | Medium | O(n² * m) | O(n) | Check if substring in dictionary |

---

## Pattern 5: Longest Increasing Subsequence (LIS)
**Core Concept:** Track increasing sequences | **Complexity:** O(n log n) optimized with binary search

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Longest Increasing Subsequence | Medium | O(n log n) | O(n) | Binary search + patience sort |
| Number of LIS | Medium | O(n²) | O(n) | Track length + count arrays |
| Vacation | Medium | O(n * k) | O(k) | State DP: can't repeat activity |

---

## Pattern 6: Grid-Based DP
**Core Concept:** Navigate grid with constraints | **Complexity:** O(m * n) time, O(n) space optimized

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Unique Paths | Medium | O(m * n) | O(n) | dp[i][j] = dp[i-1][j] + dp[i][j-1] |
| Grid Paths | Medium | O(m * n) | O(m * n) | Handle obstacles: mark as 0 |
| Minimum Path Sum | Medium | O(m * n) | O(n) | grid[i][j] + min(top, left) |

---

## Pattern 7: Interval DP
**Core Concept:** Process intervals of varying sizes | **Complexity:** O(n³) time, O(n²) space

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Burst Balloons | Hard | O(n³) | O(n²) | Think backwards: which bursts last? |
| Palindrome Partitioning II | Hard | O(n²) | O(n²) | Min cuts + palindrome table |
| Longest Palindromic Substring | Medium | O(n²) | O(1) expand | Expand around each center |

---

## Pattern 8: Tree DP
**Core Concept:** DP on tree structures | **Complexity:** O(n) time, O(h) space

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| House Robber III | Medium | O(n) | O(h) | Return {rob_root, skip_root} |
| Tree Matching | Hard | O(n) | O(n) | Max matching in tree structure |
| House Robber | Medium | O(n) | O(1) | dp[i] = max(rob+dp[i-2], dp[i-1]) |
| House Robber II | Medium | O(n) | O(1) | Circular: solve twice |

---

## Pattern 9: Bitmasking / State Compression
**Core Concept:** Use bitmask to represent state | **Complexity:** O(2^n * n) time, O(2^n) space

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Campus Bikes II | Medium | O(2^n * n) | O(2^n) | dp[mask] = min distance |
| Partition K Equal Subsets | Medium | O(2^n * n) | O(2^n) | Bitmask tracks used elements |
| Traveling Salesman | Hard | O(2^n * n²) | O(2^n * n) | dp[mask][city] = min cost |

---

## Pattern 10: Digit DP
**Core Concept:** Process numbers digit by digit | **Complexity:** Varies with constraints

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Numbers With Repeated Digits | Hard | O(digits * 2^10) | O(digits * 2^10) | Track used digits + tight bound |
| Removing Digits | Medium | O(n * log n) | O(n) | Subtract each digit; find min steps |
| Sushi | Hard | O(n⁴) | O(n³) | Probabilistic DP + state compression |

---

## Pattern 11: Probability / Expectation DP
**Core Concept:** Calculate expected values | **Complexity:** Depends on state dimensions

| Problem | Difficulty | Time | Space | Key Approach |
|---------|------------|------|-------|--------------|
| Dice Roll Simulation | Hard | O(n * 6 * max) | O(n * 6 * max) | Track last digit + consecutive count |
| Candy Lottery | Medium | O(n * k) | O(n) | Expected max of k dice |
| Coins (Probability) | Hard | O(n²) | O(n²) | dp[i][j] = prob of j heads in i flips |

---

## 🎯 Complexity Quick Reference

| Complexity Class | Patterns | Typical Problems |
|-----------------|----------|------------------|
| **O(n)** Linear | Fibonacci, Tree DP | Climbing Stairs, House Robber |
| **O(n²)** Quadratic | LCS, LIS, Palindrome | Edit Distance, LIS (standard) |
| **O(n * W)** Knapsack | 0/1 & Unbounded | Coin Change, Subset Sum |
| **O(m * n)** Grid | Grid DP, LCS | Unique Paths, LCS |
| **O(n³)** Cubic | Interval DP | Burst Balloons, Matrix Chain |
| **O(2^n * n)** Exponential | Bitmask DP | TSP, Assignment Problems |

---

## 💡 Pattern Recognition Tips

1. **Fibonacci Pattern**: "Ways to reach", "count combinations", depends on previous 1-2 states
2. **Knapsack**: "Choose items", "subset with sum", "maximize value with capacity"
3. **LCS**: "Two sequences", "match/skip", "common substring/subsequence"
4. **LIS**: "Increasing/decreasing sequence", "longest chain"
5. **Grid**: "Path in matrix", "reach destination", constrained movement
6. **Interval**: "Optimal cost for subrange", "last operation in range"
7. **Tree**: "Maximize on tree", "can't choose adjacent nodes"
8. **Bitmask**: "Assignment", "visit all", "subset selection" with small n (≤20)
9. **Digit DP**: "Count numbers with property", process digits
10. **Probability**: "Expected value", "probability of outcome"

---

## 🚀 Optimization Strategies

### Space Optimization
- **1D → 0D**: When only previous 1-2 values needed (Fibonacci)
- **2D → 1D**: When row depends only on previous row (Knapsack, LCS)
- **Sliding window**: For rolling computations

### Time Optimization
- **Binary search**: LIS O(n²) → O(n log n)
- **Memoization**: Avoid recomputing overlapping subproblems
- **State compression**: Reduce state dimensions with bitmasking

### Common Tricks
- **Add dummy elements**: Simplify boundary conditions (Burst Balloons)
- **Process in reverse**: Sometimes easier to think backwards
- **Transform problem**: Target Sum → Subset Sum
- **Precompute**: Palindrome table, prefix sums

---

## 📚 Study Roadmap

### Beginner (Start here)
1. Fibonacci / Simple Recurrence (4 problems)
2. Grid-Based DP (3 problems)
3. Tree DP - House Robber variants (3 problems)

### Intermediate
4. 0/1 Knapsack (4 problems)
5. Unbounded Knapsack (3 problems)
6. Longest Increasing Subsequence (3 problems)

### Advanced
7. Longest Common Subsequence (4 problems)
8. Interval DP (3 problems)
9. Bitmasking / State Compression (3 problems)

### Expert
10. Digit DP (3 problems)
11. Probability / Expectation DP (3 problems)

---

**Total: 37 carefully curated problems covering every DP interview pattern**

*Master these patterns and you'll be able to solve 90%+ of DP problems in coding interviews!*
