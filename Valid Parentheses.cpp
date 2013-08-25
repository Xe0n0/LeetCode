class Solution {
private:
    bool isMatch(char a, char b) {
        return b == ')' && a == '(' or
            b == '}' && a == '{' or
            b == ']' && a == '[';
    }
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && isMatch(st.top(), s[i])) {
                st.pop();
            }
            else
                st.push(s[i]);
        }
        
        if (st.empty()) return true;
        
        return false;
    }
};