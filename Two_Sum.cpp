// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

//遍历数组，在当前元素之后的数组元素内查找需要的数

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i, j;
        vector<int> result;
        for(i = 0; i < len; i++){
            int tmp = target - nums[i];
            for(j = i + 1; j < len; j++){
                if(nums[j] == tmp){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        
        return result;
    }
};