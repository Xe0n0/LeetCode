class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> flags(n, false);
        
        return getPermutationAt(n, k, flags);
    }
private:
    int numSequences(int n) {
        if (n <= 0) return 0;
        
        if (n == 1) return 1;
        
        return n * numSequences(n-1);
    }
    
    string getPermutationAt(int n, int k, vector<bool> &flags) {
        
        if (n == 0) return string("");
        
        int num = numSequences(n-1);
        
        for (int i = 0; i < flags.size(); i++) {
            
            if (flags[i]) continue;
            
            char c = '1' + i;
            
            if (num > 0 && k > num) {
                k -= num;
            }
            else {
                flags[i] = true;
                string r = getPermutationAt(n-1, k, flags);
                r.insert(r.begin(), c);
                return r;
            }
        }
        return string("");
    }
};