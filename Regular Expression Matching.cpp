// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        if(!s_len && !p_len)
            return true;
        else if(!p_len || !s_len)
            return false;

        if(p[0] == '*')
            return false;

        int i = 0, j = 0;
        for(; i < s_len && j < p_len;){
            if(s[i] == p[j] || p[j] == '.'){
                j++;
                i++;
                continue;
            }
            else if(p[j] == '*' && (s[i] == p[j-1] || p[j-1] == '.')){
                i++;
                continue;
            }
            else if((j+2) < p_len && p[j+1] == '*'){
                j += 2;
                continue;
            }

            return false;
        }

        if(i == s_len && j <= p_len)
            return true;
        else
            return false;
    }
};