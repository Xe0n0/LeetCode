//rev.1
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        
        while (i < n) {
            //should not swap same elements
            if (A[i] <= n && A[i] > 0 && A[i] != i+1 && A[A[i]-1] != A[i]) {
                
                swap(A[i], A[A[i]-1]);
                
            }
            else i++;
        }
        
        i = 0;
        
        while (i < n) {
            
            if (A[i] != i+1)
                return i+1;
                
            i++;
        }
        
        return n+1;
    }
};

//rev.2
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