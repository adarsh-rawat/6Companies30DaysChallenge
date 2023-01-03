//Q.15, No. 1358 on leetcode
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, count = 0;

        unordered_map<char, int> m;

        for(int i = 0; i < s.size(); ++i){
            m[s[i]]++;
            while(m['a'] && m['b'] && m['c']){
                m[s[left++]]--;
            }
            count += left;
        }
        return count;
        
    }
};