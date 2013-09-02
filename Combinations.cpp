//rev.2
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        
        if (k > n) {
            return r;
        }
        
        if (k <= 0) {
            r.push_back(vector<int>());
            return r;
        }
        
        
        
        vector<vector<int> > t1 = combine(n-1, k);
        vector<vector<int> > t2 = combine(n-1, k-1);
        
        r.resize(t1.size());
        copy(t1.begin(), t1.end(), r.begin());
        
        for (int i = 0; i < t2.size(); i++) {
            
            vector<int> temp = t2[i];
            temp.push_back(n);
            r.push_back(temp);
            
        }
        
        return r;
    }
};

//rev.1
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