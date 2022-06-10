# LeetCode
Solution to problems from https://leetcode.com/

# Dynamic Programming Hints

1. Express everything as index.
2. Find out what parameters you need to carry during recursion. To find that out, stand on that index and think what decisions you need to make and to make those decisions
what will you need?
3. Find the max / min / count or whatever the question is asking.
4. Base case? How will the recursion finish and not go forward?

# Tabulation / Botton Up

A) Transfer the base case.
Sometimes you will need to use "shifting of index" technique if the base case is for negative indexes.

-1, 0, 1, 2, 3, 4, 5, .......... n - 1
f (n, m)
transformation f(x) => f(x - 1)
n = n - 1
1 = 0
0 = -1

For LCS recursion base case can be written as if i == 0 || j == 0 then return 0
To convert this into tabulation, in the 2D array dp, assign dp[0][j] to 0 as this will handle i == 0 and assign dp[i][0] = 0 as this will handle j == 0

B) Write down the changing parameters in the opposite fashion. [i = , j = ]
in case of recursion i was going from n to 0 and j was going from m to 0
so for tabulation, i -> 1 to m and j -> 1 to n

C) Copy the recurrence.
