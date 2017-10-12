// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sum;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if(!len1 && !len2)
            return 0;
        double result = 0;
        for(int i = 0; i < len1; i++)
            sum.push_back(nums1[i]);
        for(int i = 0; i < len2; i++)
            sum.push_back(nums2[i]);
        sort(sum.begin(), sum.end());
        

        int len = len1 + len2;
        
        if(len%2){
            result = sum[len/2];
        }
        else{
            result = (sum[len/2-1] + sum[len/2])/2.0;
        }
        
        return result;
    }
};