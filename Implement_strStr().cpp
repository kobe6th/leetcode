// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_len = haystack.length();
        int n_len = needle.length();
        
        if(!n_len)
            return 0;
        
        for(int i = 0; i <= h_len- n_len; i++){
            int j = 0;
            for(; j < n_len; j++){
                if(haystack[i+j] != needle[j])
                    break;
            }

            if(j == n_len)
                return i;
        }

        return -1;
    }
};