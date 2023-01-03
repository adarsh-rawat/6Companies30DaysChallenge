//No. 150 on leetcode
class Solution {
public:
    int calc(int aa, int bb, string sign){
        // int aa = a - '0';
        // int bb = b - '0';
        int res;
        
        if(sign == "+") res = aa + bb;
        else if(sign == "-") res = aa - bb;
        else if(sign == "*") res = aa * bb;
        else res = aa / bb;
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int t = st.top();
                st.pop();
                int u = st.top();
                st.pop();
                st.push(calc(u, t, it));
                cout<< "push..." << st.top() << endl;
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};