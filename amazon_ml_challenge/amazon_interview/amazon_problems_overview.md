# Amazon SDE Interview Questions - Complete Solutions Guide

## Overview

This document provides comprehensive solutions for Amazon's most frequently asked coding interview questions across Easy, Medium, and Hard difficulty levels.

### Problem Distribution
- **Easy**: 4 problems
- **Medium**: 5 problems  
- **Hard**: 2 problems
- **Total**: 11 problems (representative sample)

---


## EASY Problems (4 questions)

### Problem 1: Two Sum

**Difficulty:** Easy

**Constraints:** Array of integers, target sum. Find indices of two numbers that add up to target.

**Pattern:** Hash Map / Two Pointer

**Intuition:** Store first number in hashmap, check if complement exists for next number

---

### Problem 2: Contains Duplicate

**Difficulty:** Easy

**Constraints:** Array of integers. Return true if any value appears at least twice.

**Pattern:** Hash Set

**Intuition:** Track seen elements in set; duplicate found if element already exists

---

### Problem 3: Valid Palindrome

**Difficulty:** Easy

**Constraints:** String with alphanumeric and special characters. Check if palindrome.

**Pattern:** Two Pointer

**Intuition:** Compare characters from both ends moving inward, skip non-alphanumeric

---

### Problem 4: Climbing Stairs

**Difficulty:** Easy

**Constraints:** n stairs, can climb 1 or 2 at a time. Ways to reach top?

**Pattern:** Dynamic Programming / Fibonacci

**Intuition:** dp[i] = dp[i-1] + dp[i-2]; each step reachable from previous 1 or 2

---


## MEDIUM Problems (5 questions)

### Problem 1: Two Sum II - Input Array Is Sorted

**Difficulty:** Medium

**Constraints:** Sorted array, find two indices with specific sum

**Pattern:** Two Pointer

**Intuition:** Start from both ends; if sum too large move right pointer left, else move left pointer right

---

### Problem 2: 3Sum

**Difficulty:** Medium

**Constraints:** Array, find all unique triplets summing to zero

**Pattern:** Two Pointer + Sorting

**Intuition:** Sort array, fix one element, use two pointer for remaining two

---

### Problem 3: Reverse String

**Difficulty:** Easy

**Constraints:** Reverse character array in-place

**Pattern:** Two Pointer

**Intuition:** Swap characters from both ends moving inward

---

### Problem 4: Maximum Subarray

**Difficulty:** Medium

**Constraints:** Find contiguous subarray with largest sum

**Pattern:** Dynamic Programming / Kadane's Algorithm

**Intuition:** Track max ending here; if becomes negative, start fresh

---

### Problem 5: Search in Rotated Sorted Array

**Difficulty:** Medium

**Constraints:** Rotated sorted array, find target value

**Pattern:** Binary Search

**Intuition:** Determine which half is sorted, search accordingly

---


## HARD Problems (2 questions)

### Problem 1: Merge K Sorted Lists

**Difficulty:** Hard

**Constraints:** k sorted linked lists, merge into one sorted list

**Pattern:** Heap / Divide & Conquer

**Intuition:** Use min heap for efficient merging

---

### Problem 2: Word Break II

**Difficulty:** Hard

**Constraints:** String + word dict, find all possible sentence combinations

**Pattern:** DP + DFS + Memoization

**Intuition:** Backtrack with memoization to avoid recomputing

---

