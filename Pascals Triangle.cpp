class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        
        if (numRows == 0) return r;
        
        if (numRows == 1) {
            r.push_back(vector<int>(1,1));
            return r;
        }
        
        r = generate(numRows - 1);
        
        vector<int> last = r[numRows-2];
        
        vector<int> newRow(numRows, 1);
        
        for (int i = 1; i < numRows - 1; i++) {
            
            newRow[i] = last[i-1] + last[i];
        }
        
        r.push_back(newRow);
        
        return r;
    }
};