#include <bits/stdc++.h>
using namespace std;

// Approach 1: Memoization + Recursion
long countSequences(int length, int digit, vector<vector<long long>> allowedMoves, vector<vector<long long>> &dp)
{
    // Base case: if length is 1, there's only one sequence for each digit
    if (length == 1)
        return 1;

    // Check if the result is already computed
    if (dp[length][digit] != -1)
        return dp[length][digit];

    // Compute the result
    long total = 0;
    for (int move : allowedMoves[digit])
    {
        total += countSequences(length - 1, move, allowedMoves, dp);
    }

    dp[length][digit] = total;

    return total;
}

long getCount(int n)
{
     vector<vector<long long>> allowedMoves = {
        {0, 8},          // from 0 to 0, 8
        {1, 2, 4},       // from 1 to 1, 2, 4
        {2, 1, 5, 3},    // from 2 to 2, 1, 3, 5
        {3, 2, 6},       // from 3 to 3, 2, 6
        {4, 1, 7, 5},    // from 4 to 4, 1, 5, 7
        {5, 2, 4, 6, 8}, // from 5 to 5, 2, 4, 6, 8
        {6, 3, 5, 9},    // from 6 to 6, 3, 5, 9
        {7, 4, 8},       // from 7 to 7, 4, 8
        {8, 0, 9, 7, 5}, // from 8 to 8, 0, 5, 7, 9
        {9, 6, 8}        // from 9 to 9, 6, 8
    };

    // Memoization table: dp[length][digit] = number of sequences of 'length' ending in 'digit'
     vector<vector<long long>> dp(n + 1, vector<long long>(10, -1));
    long ans = 0;

    // Calculate the number of sequences of length 'n' for each digit
    for (int i = 0; i <= 9; ++i)
    {
        ans += countSequences(n, i, allowedMoves, dp);
    }

    return ans;
}


// Approach 2: Tabulation (Bottom-up Dynamic Programming)
long long getCount_2(int n)
{
    vector<vector<long long>> allowedMoves = {
        {0, 8},          // from 0 to 0, 8
        {1, 2, 4},       // from 1 to 1, 2, 4
        {2, 1, 5, 3},    // from 2 to 2, 1, 3, 5
        {3, 2, 6},       // from 3 to 3, 2, 6
        {4, 1, 7, 5},    // from 4 to 4, 1, 5, 7
        {5, 2, 4, 6, 8}, // from 5 to 5, 2, 4, 6, 8
        {6, 3, 5, 9},    // from 6 to 6, 3, 5, 9
        {7, 4, 8},       // from 7 to 7, 4, 8
        {8, 0, 9, 7, 5}, // from 8 to 8, 0, 5, 7, 9
        {9, 6, 8}        // from 9 to 9, 6, 8
    };

    // Base Condition
    if (n == 1)
        return 10;

    // creating dp array
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (auto x : allowedMoves[j])
            {
                dp[i][j] += dp[i - 1][x];
            }
        }
    }

    // calculating final answer
    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dp[n][i];
    }
    return ans;
}