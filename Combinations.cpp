class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return combineAt(1, n, k);
       
    }
private:
    vector<vector<int> > combineAt(int a, int n, int k) {
        
        vector<vector<int> > vs;
        
        if (k > n) return vs;
        
        if (k <= 0) {
            vs.push_back(vector<int>());
            return vs;
        }
        
        for (int i = a; i <= n; i++) {
            
            vector<vector<int> > temp = combineAt(i+1, n, k-1);
            
            for (int j = 0; j < temp.size(); j++) {
                
                temp[j].insert(temp[j].begin(), i);
                vs.push_back(temp[j]);
                
            }
        }
        
        return vs;
        
    }
};