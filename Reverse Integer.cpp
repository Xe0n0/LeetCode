//Fuck! I wrote t.size() - i!!!
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return -reverse(-x);
        
        string t = to_string(x);
        
        for (int i = 0; i < t.size() / 2; i++) {
            char temp = t[i];
            t[i] = t[t.size() - i - 1];
            t[t.size() - i - 1] = temp;
        }
        return stoi(t);
    }
};