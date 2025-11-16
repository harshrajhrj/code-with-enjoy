# Amazon SDE Interview Questions - Complete Solutions Guide

## 📋 Document Overview

This comprehensive guide contains **11 curated Amazon SDE interview questions** with complete C++ solutions, detailed explanations, complexity analysis, and patterns for each problem.

---

## 📊 Problem Distribution

| Difficulty | Count | Problems |
|------------|-------|----------|
| **Easy** | 4 | Two Sum, Contains Duplicate, Valid Palindrome, Climbing Stairs |
| **Medium** | 5 | Two Sum II, 3Sum, Reverse String, Maximum Subarray, Search Rotated Array |
| **Hard** | 2 | Merge K Sorted Lists, Word Break II |
| **TOTAL** | **11** | **Representative sample** |

---

## 🎯 Problem List with Patterns

### EASY PROBLEMS

#### 1️⃣ **Two Sum** [Hash Map]
- **Difficulty**: Easy
- **Question**: Given array and target, find indices of two numbers that add up to target
- **Constraints**: Each element used only once, exactly one solution exists
- **Time**: O(n) | **Space**: O(n)
- **Pattern**: Hash Map - store complement, check if exists
- **Key Insight**: For each number, check if (target - number) already seen

#### 2️⃣ **Contains Duplicate** [Hash Set]
- **Difficulty**: Easy
- **Question**: Return true if any value appears at least twice in array
- **Constraints**: Array of integers, -10^9 to 10^9 range
- **Time**: O(n) | **Space**: O(n)
- **Pattern**: Hash Set - track seen elements
- **Key Insight**: O(1) lookup prevents duplicates in set

#### 3️⃣ **Valid Palindrome** [Two Pointer]
- **Difficulty**: Easy
- **Question**: Check if string is palindrome (alphanumeric only, case-insensitive)
- **Constraints**: Handle special chars, spaces, mixed case
- **Time**: O(n) | **Space**: O(1)
- **Pattern**: Two Pointer - compare from both ends
- **Key Insight**: Skip non-alphanumeric, compare lowercase versions

#### 4️⃣ **Climbing Stairs** [Dynamic Programming]
- **Difficulty**: Easy
- **Question**: n stairs, can take 1 or 2 steps each time. How many ways?
- **Constraints**: 1 ≤ n ≤ 45
- **Time**: O(n) | **Space**: O(1)
- **Pattern**: Fibonacci/DP - dp[i] = dp[i-1] + dp[i-2]
- **Key Insight**: Optimize space from O(n) to O(1) using two variables

---

### MEDIUM PROBLEMS

#### 5️⃣ **Two Sum II - Input Array Is Sorted** [Two Pointer]
- **Difficulty**: Medium
- **Question**: Sorted array + target, return 1-indexed indices
- **Constraints**: Sorted array guaranteed, exactly one solution
- **Time**: O(n) | **Space**: O(1)
- **Pattern**: Two Pointer - start from both ends
- **Key Insight**: If sum too small, increase left pointer; if too large, decrease right

#### 6️⃣ **3Sum** [Sort + Two Pointer]
- **Difficulty**: Medium
- **Question**: Find all unique triplets in array that sum to 0
- **Constraints**: Return unique triplets (no duplicates), -10^5 to 10^5 range
- **Time**: O(n²) | **Space**: O(1)
- **Pattern**: Sort array first, fix one element, use two pointers for other two
- **Key Insight**: Sort enables efficient duplicate skipping

#### 7️⃣ **Reverse String** [Two Pointer]
- **Difficulty**: Easy
- **Question**: Reverse character array in-place
- **Constraints**: Modify array in-place, 1 ≤ length ≤ 10^5
- **Time**: O(n) | **Space**: O(1)
- **Pattern**: Two Pointer - swap from both ends moving inward
- **Key Insight**: Simple and elegant - traverse exactly n/2 positions

#### 8️⃣ **Maximum Subarray** [Kadane's Algorithm]
- **Difficulty**: Medium
- **Question**: Find contiguous subarray with largest sum
- **Constraints**: At least one number, -10^4 to 10^4 range
- **Time**: O(n) | **Space**: O(1)
- **Pattern**: Dynamic Programming - Kadane's Algorithm
- **Key Insight**: At each position, decide: extend subarray or start new?

**Kadane's Algorithm Explanation**:
```
For each element, track:
- maxCurrent: Maximum sum ending at current index
- maxGlobal: Overall maximum found so far

At each position i:
  maxCurrent = max(nums[i], maxCurrent + nums[i])
  maxGlobal = max(maxGlobal, maxCurrent)

Example: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Result: 6 (subarray [4, -1, 2, 1])
```

#### 9️⃣ **Search in Rotated Sorted Array** [Binary Search]
- **Difficulty**: Medium
- **Question**: Find target in rotated sorted array
- **Constraints**: Must run in O(log n), no duplicates, array rotated at unknown pivot
- **Time**: O(log n) | **Space**: O(1)
- **Pattern**: Modified Binary Search - determine sorted half, search appropriately
- **Key Insight**: Always one half is sorted; use this to eliminate possibilities

**Algorithm Logic**:
```
1. Find middle element
2. Determine which half (left/right) is sorted
3. If target in sorted half, search there
4. Otherwise, search other half
5. Repeat until found or search space exhausted
```

---

### HARD PROBLEMS

#### 🔟 **Merge K Sorted Lists** [Heap / Divide & Conquer]
- **Difficulty**: Hard
- **Question**: Merge k sorted linked lists into one sorted list
- **Constraints**: 0 ≤ k ≤ 10^4, 0 ≤ total nodes ≤ 10^4
- **Time**: O(n log k) | **Space**: O(k)
- **Pattern**: Min Heap - always pick smallest from k lists
- **Key Insight**: Use heap to efficiently track minimum across k lists

**Two Approaches**:
1. **Heap (Optimal for large k)**: O(n log k) time
   - Add first node from each list to min heap
   - Repeatedly extract min, add next node from that list
   - Better when k is large

2. **Divide & Conquer**: O(n log k) time, O(log k) space
   - Recursively merge pairs of lists
   - Merge results together
   - Better for cache locality

#### 1️⃣1️⃣ **Word Break II** [DFS + Memoization]
- **Difficulty**: Hard
- **Question**: Find all possible sentences by breaking string with dictionary words
- **Constraints**: s.length ≤ 20, wordDict ≤ 1000 words, output order matters
- **Time**: O(n^n) worst case | **Space**: O(n²)
- **Pattern**: Backtracking with Memoization
- **Key Insight**: Memoize subproblem results to avoid recomputation

**Algorithm**:
```
1. Memoize results for each substring
2. For each word in dictionary:
   - If string starts with word:
     - Recursively break remaining string
     - Combine word with results from remaining
3. Base case: empty string returns [""]
```

---

## 📈 Complexity Cheat Sheet

| Problem | Time | Space | Pattern | Difficulty |
|---------|------|-------|---------|------------|
| Two Sum | O(n) | O(n) | Hash Map | Easy |
| Contains Duplicate | O(n) | O(n) | Hash Set | Easy |
| Valid Palindrome | O(n) | O(1) | Two Pointer | Easy |
| Climbing Stairs | O(n) | O(1) | DP | Easy |
| Two Sum II | O(n) | O(1) | Two Pointer | Medium |
| 3Sum | O(n²) | O(1) | Sort + Two Ptr | Medium |
| Reverse String | O(n) | O(1) | Two Pointer | Easy |
| Maximum Subarray | O(n) | O(1) | Kadane's | Medium |
| Search Rotated | O(log n) | O(1) | Binary Search | Medium |
| Merge K Lists | O(n log k) | O(k) | Heap | Hard |
| Word Break II | O(n^n) | O(n²) | DFS + Memo | Hard |

---

## 🎓 Key Patterns & Techniques

### 1. **Hash Set/Map Pattern**
**When to use**: Need to check existence, find pairs/complements, count frequencies
**Pros**: O(1) average lookup, insertion
**Cons**: Extra space, hash collisions possible
**Problems**: Two Sum, Contains Duplicate, Group Anagrams

### 2. **Two Pointer Pattern**
**When to use**: Sorted arrays, palindromes, opposite ends
**Pros**: O(1) space, elegant logic
**Cons**: Only works for sorted or specific structures
**Problems**: Valid Palindrome, Two Sum II, Reverse String

### 3. **Binary Search Pattern**
**When to use**: Sorted arrays, monotonic functions, O(log n) requirement
**Pros**: Very efficient O(log n), even on large datasets
**Cons**: Requires sorted data or monotonic property
**Problems**: Search Rotated Array, Find First/Last Position

### 4. **Dynamic Programming Pattern**
**When to use**: Optimal substructure, overlapping subproblems
**Pros**: Optimal solutions for complex problems
**Cons**: Higher space complexity, harder to implement
**Problems**: Climbing Stairs, Maximum Subarray, Word Break II

### 5. **Heap Pattern**
**When to use**: K-way merge, top-K problems, priority processing
**Pros**: Efficient extraction of min/max
**Cons**: O(log n) operations, extra space
**Problems**: Merge K Lists, Top K Frequent Elements

### 6. **Backtracking + Memoization**
**When to use**: Find all solutions, combinations, permutations
**Pros**: Explores all possibilities efficiently
**Cons**: Can be exponential, needs careful pruning
**Problems**: Word Break II, Permutations, Combinations

---

## 💡 Pro Tips for Interviews

### Before Coding
1. **Clarify constraints** - Ask about edge cases, range of values
2. **Work through examples** - Manually trace 2-3 examples
3. **State your approach** - Explain intuition before coding
4. **Discuss trade-offs** - Time vs space, clarity vs optimization

### While Coding
1. **Write clean code** - Good variable names, proper indentation
2. **Handle edge cases** - Empty arrays, single elements, negatives
3. **Test as you go** - Don't wait until end to test
4. **Avoid clever tricks** - Readability over cleverness

### After Coding
1. **Trace through example** - Verify logic with real input
2. **Discuss complexity** - Clearly explain both time and space
3. **Optimize if asked** - Show you can improve solution
4. **Ask for feedback** - "Would you like me to optimize further?"

---

## 🔗 Interview Strategy

### Pattern Recognition Flowchart

```
Problem Statement
    |
    ├─ "Two/multiple targets?" → Hash Map / Two Pointer
    ├─ "Find in sorted array?" → Binary Search
    ├─ "Subarray/subsequence?" → DP / Sliding Window
    ├─ "All combinations/permutations?" → Backtracking
    ├─ "Merge K streams?" → Heap
    ├─ "Palindrome/reverse?" → Two Pointer
    ├─ "Tree/graph traversal?" → DFS / BFS
    └─ "Optimal path/value?" → DP / Greedy
```

### Time Management
- **First 5 minutes**: Clarify problem, work through examples
- **Next 10 minutes**: Code the solution
- **Next 5 minutes**: Test with examples
- **Last 5 minutes**: Discuss optimizations, handle edge cases

---

## 📚 Learning Resources

### For Practice
1. **LeetCode** - Most comprehensive problem database
   - Solve easy problems first (master fundamentals)
   - Then medium (reinforce patterns)
   - Hard problems show advanced techniques
   
2. **Pattern-based learning**
   - Group similar problems by pattern
   - Solve all variations of one pattern
   - Build muscle memory

### Master These Patterns First
1. Two Pointers (10 problems)
2. Hash Map/Set (15 problems)
3. Binary Search (10 problems)
4. Dynamic Programming (20 problems)
5. Trees & Graphs (30 problems)

---

## ✅ Pre-Interview Checklist

- [ ] Review all 11 problems and solutions
- [ ] Practice implementing from memory (no looking)
- [ ] Time yourself (aim for 30-40 min per medium problem)
- [ ] Explain solutions out loud (practice communication)
- [ ] Identify patterns in each solution
- [ ] Understand why each complexity analysis is correct
- [ ] Know multiple approaches (time vs space tradeoff)
- [ ] Be comfortable with C++ syntax (if that's your language)

---

## 🚀 Expected Performance

### For Job Offers
- **Easy problems**: Should solve 100% correctly
- **Medium problems**: Should solve 80%+ correctly  
- **Hard problems**: Should solve 50%+ correctly
- **Plus**: Ask clarifying questions, discuss approaches, handle edge cases

### What Interviewers Look For
1. ✅ Can you break down complex problems?
2. ✅ Do you know relevant data structures?
3. ✅ Can you write clean, bug-free code?
4. ✅ Do you understand complexity analysis?
5. ✅ Can you optimize your solution?
6. ✅ Communication and problem-solving approach

---

## 🎯 Next Steps

1. **Master easy problems** - Understand fundamentals
2. **Practice medium problems** - Build problem-solving skills
3. **Challenge yourself with hard** - Learn advanced techniques
4. **Practice under time pressure** - Simulate interview conditions
5. **Teach others** - Reinforces your understanding
6. **Review common mistakes** - Don't repeat them

---

## 📞 Common Interview Questions

**Q: What's the most common mistake candidates make?**
A: Not clarifying constraints and jumping straight to coding.

**Q: How important is code optimization?**
A: Getting working solution matters more initially, optimization if asked.

**Q: Should I use STL/standard library?**
A: Yes! Interviewers expect you to use available tools efficiently.

**Q: How many problems should I solve before interviewing?**
A: 150-200 problems covering all major patterns.

**Q: Is it OK to debug during interview?**
A: Yes, but do it methodically. Trace through your logic.

---

## 📝 Final Thoughts

> "It's not about memorizing solutions. It's about understanding patterns,
> knowing when to apply them, and being able to adapt them to new problems."

Focus on:
1. **Understanding**, not memorizing
2. **Patterns**, not individual problems
3. **Communication**, not just code
4. **Practice**, not just reading

**Good luck with your Amazon interview! 🚀**

---

## 📄 File Structure

```
amazon_interview_prep/
├── amazon_solutions.cpp          # Complete C++ implementations
├── AMAZON_SOLUTIONS_README.md    # This file
├── dp_patterns_comprehensive.csv # DP pattern reference
└── complexity_cheatsheet.txt     # Quick complexity lookup
```

---

**Last Updated**: November 2025
**Format**: Production-ready C++ with detailed explanations
**Total Problems**: 11 curated Amazon interview questions
**Difficulty Range**: Easy to Hard