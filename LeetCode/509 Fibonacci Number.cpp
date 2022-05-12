class Solution {
public:
    int fib(int n) {        
        vector<int> fib(32, 0);
        fib[0] = 0;
        fib[1] = 1;
        
        for(int i = 2; i < 32; i++){            
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        return fib[n];
    }
};