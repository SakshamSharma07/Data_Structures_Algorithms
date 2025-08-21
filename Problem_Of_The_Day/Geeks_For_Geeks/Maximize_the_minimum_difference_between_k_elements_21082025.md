![Search in fully rotated sorted 2D matrix](https://github.com/SakshamSharma07/Data_Structures_Algorithms/tree/main/Problem_Of_The_Day/Images/GKG_POD_21082025.png?raw=true)



## **Intuition**  
To maximize the minimum difference, the chosen elements should be as far apart as possible.  
If the array is unsorted, it’s hard to reason about distances. Sorting the array makes it easier because any optimal selection will follow the sorted order.  

The problem becomes:  
**"What is the largest possible minimum distance `d` such that we can pick `k` elements from the sorted array, each at least `d` apart?"**  

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
