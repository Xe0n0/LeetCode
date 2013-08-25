//1. please recheck after modify
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        vector<int> levels;
        levels.resize(s.size(), 0);
        
        int best = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            
            else if (s[i] == ')') {
                
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    
                    if (i - 1 >= 0)
                        levels[i] = levels[i-1] + 2;
                    else
                        levels[i] = 2;
                        
                    if (i - levels[i] >= 0 && levels[i - levels[i]]) {
                        levels[i] += levels[i - levels[i]];
                    }
                    best = max(best, levels[i]);
                }
            }
        }
        
        return best;
    }
};