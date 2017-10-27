// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 0)
            return "";
        else if(numRows == 1)
            return s;

        std::vector<string> v;
        for(int i = 0; i < numRows; i++){
            string str = "";
            v.push_back(str);
        }


        for(int i = 0, rows = 0, offset = 1; i < s.length(); i++){
            v[rows].push_back(s[i]);
            if(rows == 0)
                offset = 1;
            else if(rows == numRows - 1)
                offset = -1;

            rows += offset;
        }

        string res;
        for(int i = 0; i < numRows; i++)
            res += v[i];

        return res;
    }
};