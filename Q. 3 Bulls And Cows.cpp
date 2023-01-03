class Solution {
public:
    //Q.299 on leetcode
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        unordered_multiset<char> s;
        
        for(int i = 0; i <secret.size(); ++i){
            if(secret[i] == guess[i]){
                ++A;
                secret[i] = 'a';
            }
            else{
                s.insert(secret[i]);
            }
        }
        for(int i = 0; i< secret.size(); ++i){
            if(secret[i] != 'a' && s.find(guess[i]) != s.end()){
                ++B;
                cout<<guess[i];
                s.erase(s.find(guess[i]));
            }
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
};