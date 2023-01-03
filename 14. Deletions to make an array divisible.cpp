//2344 on leetcode
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsD) {
        
        int gcd = numsD[0];
        for(auto it: numsD){
            gcd = __gcd(gcd, it);
        }
        int count = 0, mi = -1, res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(gcd % nums[i] == 0){
                if(mi == -1) mi = nums[i];
                else mi = min(mi, nums[i]);
            }
            if(nums[i] == 1) return 0;
        }

        if(mi == -1) return -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < mi) res++;
        }
        return res;
    }
};