## **Problem of the Day: 21-08-2025**  
![Minimum days to make M bouquets](https://raw.githubusercontent.com/SakshamSharma07/Data_Structures_Algorithms/main/Problem_Of_The_Day/Images/GKG_POD_24082025.png)

---

## **Intuition**
The feasibility “Can we make `m` bouquets by day `D`?” is **monotonic**:
- If we **can** make them on day `D`, then we can also make them on any day `> D`.
- If we **cannot** on day `D`, we cannot on any day `< D`.

This monotonic property allows **Binary Search on the answer (days)**.  
To test a single day `D`, scan the array and greedily count how many bouquets can be formed from **consecutive** flowers with bloom day `≤ D`.

---

## **Approach**
1. **Early fail:** If `m * k > n` (total flowers), return `-1`.
2. **Binary search** on days:
   - `low = 1`, `high = 1e9` (or `max(arr)`), search for the smallest day `D` that works.
3. **Feasibility check** for a fixed `D`:
   - Traverse `arr`, maintain a counter of **consecutive bloomed** flowers (`arr[i] ≤ D`).
   - Each time the counter hits `k`, increment bouquet count and reset the counter.
   - If total bouquets `≥ m`, `D` is feasible.

---

## **Time & Space Complexity**
- Feasibility check: `O(n)`  
- Binary search steps: `O(log(1e9)) ≈ 30`  
- **Overall:** `O(n log 1e9)`  
- **Space:** `O(1)`

---

## **C++ Implementation**
```cpp
class Solution {
  public:
    // Returns true if we can make at least m bouquets by 'days'
    bool canMake(vector<int>& arr, int k, int m, int days) {
        int consecutive = 0, made = 0;
        for (int x : arr) {
            if (x <= days) {
                consecutive++;
                if (consecutive == k) {  // one bouquet formed
                    made++;
                    consecutive = 0;     // reset to enforce non-overlapping
                    if (made >= m) return true;
                }
            } else {
                consecutive = 0;         // break in adjacency
            }
        }
        return made >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long need = 1LL * m * k;
        if (need > (long long)arr.size()) return -1; // not enough flowers

        int low = 1, high = 1e9; // or *max_element(arr.begin(), arr.end())
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(arr, k, m, mid)) {
                ans = mid;        // feasible, try smaller day
                high = mid - 1;
            } else {
                low = mid + 1;    // infeasible, need more days
            }
        }
        return ans;
    }
};
  
