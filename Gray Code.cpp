//be careful of << and + priority
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        
        if (n <= 0) {
            r.push_back(0);
            return r;
        }
        
        vector<int> t1 = grayCode(n-1);
        vector<int> t2 = t1;
        
        reverse(t2.begin(), t2.end());
        
        r.resize(t1.size());
        
        copy(t1.begin(), t1.end(), r.begin());
        
        for (int i = 0; i < t2.size(); i++) {
            
            r.push_back(t2[i] + (1 << (n-1)));
        }
        
        return r;
    }
};