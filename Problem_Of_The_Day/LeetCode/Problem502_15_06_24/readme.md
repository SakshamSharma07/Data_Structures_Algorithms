# Maximizing Capital with Project Selection

## Problem Description

You are given `n` projects where each project `i` has a pure profit `profits[i]` and requires a minimum capital `capital[i]` to start. Initially, you have `w` capital. When you finish a project, you obtain its pure profit, which is added to your total capital. The goal is to pick a list of at most `k` distinct projects from the given projects to maximize your final capital.

### Example

#### Example 1:

Input:
- k = 2
- w = 0
- profits = [1, 2, 3]
- capital = [0, 1, 1]

Output:
- 4

Explanation:
- Initially, with capital 0, you can only start project indexed 0, yielding a profit of 1.
- After finishing project 0, your capital becomes 1.
- With capital 1, you can choose between starting project indexed 1 or project indexed 2.
- Choosing project indexed 2 (capital requirement 1, profit 3) maximizes your capital. Final capital = 0 + 1 + 3 = 4.

#### Example 2:

Input:
- k = 3
- w = 0
- profits = [1, 2, 3]
- capital = [0, 1, 2]

Output:
- 6

Explanation:
- With capital 0, start project indexed 0, yielding a profit of 1 (capital becomes 1).
- With capital 1, start project indexed 1, yielding a profit of 2 (capital becomes 3).
- With capital 3, start project indexed 2, yielding a profit of 3 (capital becomes 6).
- The final maximized capital is 6.

### Constraints

- 1 ≤ k ≤ 100,000
- 0 ≤ w ≤ 1,000,000,000
- 1 ≤ n ≤ 100,000
- 0 ≤ profits[i] ≤ 10,000
- 0 ≤ capital[i] ≤ 1,000,000,000

## Approach

To solve the problem efficiently:

### Approach Overview

1. **Sort Projects**: First, sort all projects based on their minimum capital required (`capital` array). This allows us to consider projects in increasing order of capital requirement.
  
2. **Max Heap (Priority Queue)**: Use a max heap to keep track of available projects that can be started based on current capital (`w`). This allows us to always select the project with the maximum profit that we can afford.
  
3. **Greedy Selection**: Iterate over projects while maintaining a max heap of profits of available projects that can be started (`maxHeap`). For each project, if its capital requirement is less than or equal to `w`, add its profit to `maxHeap`. Then, repeatedly select the project with the maximum profit from `maxHeap` until we either run out of projects or can no longer afford more projects.

4. **Repeat Selection**: Repeat the selection process up to `k` times or until no more projects can be started. Accumulate profits from selected projects to update `w`.

5. **Output**: After selecting up to `k` projects or as many as possible, `w` will contain the maximum capital achievable.

### Time Complexity

- Sorting projects: O(n log n)
- Each project selection (using heap): O(k log n)

The overall time complexity is dominated by the sorting step, i.e., O(n log n).

### Space Complexity

- O(n) for storing projects and the max heap.

This approach ensures that we efficiently maximize capital using a combination of sorting and greedy selection with a max heap.

