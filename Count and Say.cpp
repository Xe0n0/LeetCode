class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return string("1");
        
        string t = countAndSay(n - 1);
        string r;
        
        char c = t[0];
        char pre = c;
        int count = 1;
        
        for (int i = 1; i < t.size(); i++) {
            c = t[i];
            if (c == pre)
                count++;
            else {
                r.append(to_string(count)).push_back(pre);
                count = 1;
                pre = c;
            }
        }
        
        r.append(to_string(count)).push_back(pre);
        
        return r;
    }
};