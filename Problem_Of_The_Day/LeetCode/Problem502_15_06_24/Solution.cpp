#include <bits/stdc++.h>
using namespace std;

/**
 * Function to find the maximum capital after selecting at most k projects,
 * starting with initial capital w, from given profits and capital requirements.
 *
 * @param k Number of projects we can select
 * @param w Initial capital
 * @param profits Vector of profits for each project
 * @param capital Vector of capital requirements for each project
 * @return Maximum capital after selecting at most k projects
 */
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    int n = profits.size();
    
    // Combine profits and capital into a vector of pairs for easier sorting
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        projects[i] = {capital[i], profits[i]};
    }
    
    // Sort projects by their capital requirements in ascending order
    sort(projects.begin(), projects.end());
    
    int i = 0;
    priority_queue<int> maxHeap; // Max heap to store profits of available projects
    
    while (k > 0) {
        // Add all projects whose capital requirements are less than or equal to current capital
        while (i < n && projects[i].first <= w) {
            maxHeap.push(projects[i].second);
            i++;
        }
        
        // If no projects can be selected (maxHeap is empty), break out of the loop
        if (maxHeap.empty()) break;
        
        // Select the project with the maximum profit from the heap
        w += maxHeap.top();
        maxHeap.pop();
        
        // Decrement the count of projects we can still select
        k--;
    }
    
    return w;
}
