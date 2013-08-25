class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> all;
        
        for_each(A, A+n, [&all](int t){
            all.insert(t);
        });
        
        for (int i = 1; i <= INT_MAX; i++) {
            if (all.find(i) == all.end()) {
                return i;
            }
        }
        
        return INT_MAX;
    }
};