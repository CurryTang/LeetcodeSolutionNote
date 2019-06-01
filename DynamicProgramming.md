The collection focus on problems solved by dynamic Programming.

## Problem 70
```
//f(n) = f(n-1) + f(n-2)
//f(1) = 1
//f(2) = 2
class Solution {
public:
    int climbStairs(int n) {
        int *state = new int[n+2];
        state[0] = 1;
        state[1] = 2;
        if (n <= 2) return state[n - 1];
        for(int i = 2;i < n;i++){
            state[i] = state[i - 1] + state[i - 2];
        }
        return state[n - 1];
    }
};
```
