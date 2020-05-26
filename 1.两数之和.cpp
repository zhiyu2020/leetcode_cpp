/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    // exp: nums [2,7,11,15] target: 9
    // hash-> idx [2,7,11,15] val:[0,1,2,3] 防止hash一致性
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        //first version
		// for (int i = 0;i < nums.size(); i++){ 
        //     // 首先hash一遍 idx存指针 val存
		// 	m[nums[i]] = i;
		// }

		// for (int i = 0;i < nums.size(); i++){ 
        //     // 关键点 我写错了！ m.find() != m.end() hash中找到该值 
		// 	if (m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i) // 找到
		// 		return {i,m[target-nums[i]]};
		//}

        // second version 1 hash iteration
        // for (int i = 0 ; i < nums.size() ; i++) {
        //     m[nums[i]] = i ;
        //     if (m.find(target - nums[i]) != m.end()) {
        //         return {m[target - nums[i]], i};
        //     }
        // }

        // 3rd version : BF alg
        int count = nums.size();
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
		return {};
    }
};
// @lc code=end
/*
class Solution(object):
    def twoSum(self, nums, target):
        if len(nums) <= 1:
            return False
        buff_dict = {}
        for i in range(len(nums)):
            if nums[i] in buff_dict:
                return [buff_dict[nums[i]], i]
            else:
                buff_dict[target - nums[i]] = i
*/