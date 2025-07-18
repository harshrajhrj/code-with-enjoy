# Introduction
```cpp
int x = 13;
```
Computer stores `int` as `32` bits. So, remaining bits are appended with zeroes. Like `0000....01101`.<br>
`printf()` does the reverse conversion from bits to integer.<br>
`long long` stores `64` bits.<br>
#### Ones complement
1. Find the number of bits in the given integer 
2. XOR the given integer with $2^n$-1, where $n$ is the number of bits

Time Complexity: $O(\log_2 n)$<br>
Space Complexity: $O(1)$