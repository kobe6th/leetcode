// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

// click to show spoilers.

// Note:
// The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

class Solution {
public:
    int reverse(int x) {
        int offest = 0;
        long tmp, result = 0;
        if(x < 0){
            offest = 1;
            tmp = 0 - x;
        }
        else
            tmp = x;

        while(tmp){
            int i = tmp % 10;
            result *= 10;
            result += i;
            tmp = (tmp - i)/10;
        }

        if(offest)
            result = 0 - result;

        if(result < INT_MIN || result > INT_MAX)
            return 0;
        return result;
    }
};

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};