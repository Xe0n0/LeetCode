//rev.1 non-recursive version
class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string r;
        
        if (k <= 0) return r;

        vector<int> base(n+1, 0);
        
        base[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            
            base[i] = base[i-1] * i;
        }
        
        if (k > base[n]) return r;
        
        vector<bool> used(n+1, false);
        
        int t = n;

        while (t > 0) {
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    if (k > base[t-1]) {
                        k -= base[t-1];
                    }
                    else {
                        r.push_back(i + '1');
                        used[i] = true;
                        t--;
                        break;
                    }
                }
            }
        }
        
        return r;
        
    }
};
//rev.2
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