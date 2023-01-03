//216 on leetcode
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void helper(int num, int tar, int k){
        cout<<tar << " " << k << endl;
        if(tar < 0) return;
        else if(tar == 0 && temp.size() == num){
            res.push_back(temp);
            return;
        }
        for(int i = k+1; i <= 9; ++i){
            temp.push_back(i);
            helper(num, tar - i, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(k, n, 0);
        return res;
    }
};