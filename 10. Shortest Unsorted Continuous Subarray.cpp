//No. 581 on leetcode

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

        stack<int> st;
        int left = nums.size(), right = nums.size()-1, ma = nums[0];
        st.push(0);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1] || nums[i] < ma){
                while(!st.empty() && nums[st.top()] > nums[i]){
                    if(st.top() < left) left = st.top();
                    st.pop();
                }
                right = i;
            }
            else if(nums[i] == nums[i-1]){
                if(right == i-1)right++;
            }
            else{
                st.push(i);
                ma = max(ma, nums[st.top()]);
            }
            
        }
        return right -left +1;
    }
};