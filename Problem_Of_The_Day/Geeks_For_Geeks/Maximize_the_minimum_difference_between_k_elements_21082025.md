## **Problem of the day: 21-08-2025** 

![Search in fully rotated sorted 2D matrix](https://raw.githubusercontent.com/SakshamSharma07/Data_Structures_Algorithms/main/Problem_Of_The_Day/Images/GKG_POD_21082025.png)

## **Intuition**  
We want to select `k` elements such that the **minimum absolute difference between any two chosen elements is as large as possible**.  

If the array is **unsorted**, it’s difficult to reason about the distances between elements. So, the first step is to **sort the array**. Once sorted, the optimal subset of elements will always come from this order because the gaps become structured and predictable.  

Now the problem reduces to:  
**"What is the largest possible minimum distance `d` such that we can pick `k` elements from the sorted array, each at least `d` apart?"**  

To check if a particular distance `d` is feasible:
- Start with the first element.
- Greedily pick the next element that is at least `d` away from the last chosen element.
- Continue this process:
  - If we manage to select at least `k` elements → `d` is possible.
  - If we cannot select `k` elements → `d` is too large.

This greedy method works because always choosing the next available element gives the best chance of placing all `k` elements while maintaining the spacing `d`.  

To find the maximum possible `d`, we apply **Binary Search on the answer**:
- The smallest possible minimum distance = `0`.
- The largest possible minimum distance = `(arr[n-1] - arr[0])` (difference between the smallest and largest elements).
- For each mid-value in this range:
  - Check feasibility using the greedy approach.
  - If feasible → try a bigger distance.
  - Else → try a smaller distance.

This approach is efficient because it combines:
- **Sorting** → to arrange elements in order.
- **Binary Search** → to optimize the search for `d`.
- **Greedy selection** → to check feasibility quickly.

---

## **Approach**  
1. **Sort** the array.  
2. Use **Binary Search** on the possible minimum distance `d`:  
   - Lower bound = `1`  
   - Upper bound = `arr[n-1] - arr[0]`  
3. For each `mid` in binary search:  
   - Check feasibility by **greedily picking elements** with at least `mid` spacing.  
   - If we can select at least `k` elements → `mid` is feasible → try bigger `d`.  
   - Else → try smaller `d`.  
4. Return the **largest feasible distance**.  

---

### **Time Complexity**  
- Sorting: `O(n log n)`  
- Binary Search: `O(log(maxDiff))`  
- Feasibility Check: `O(n)` per step  
- **Overall:** `O(n log n)`  

---

## **C++ Code Implementation**  
```cpp
class Solution {
    bool elementsWithGivenDiff(vector<int>& arr, int d, int k){
        int cnt = 1, j = 0, n = arr.size();
        for(int i=1; i<n; i++){
            if((arr[i] - arr[j]) >= d){
                cnt++;
                j = i;
            }
        }
        return cnt >= k;
    }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), l = 1, h = (arr[n-1] - arr[0]), res = 0;
        while(l<=h){
            int m = l + ((h-l+1)/2);
            if(elementsWithGivenDiff(arr, m, k)){
                res = m;
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return res;
    }
};
