//WTF, I wrote j++ at first in sencond iner loop!
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vs;
        vs.resize(nRows, "");

        for (int i = 0; i < s.size();) {
            for (int j = 0; j < nRows && i < s.size(); j++) {
                vs[j].push_back(s[i++]);
            }
            
            for (int j = nRows - 2; j > 0 && i < s.size(); j--) {
                vs[j].push_back(s[i++]);
            }

        }

        string r("");
        
        for (int i = 0; i < nRows; i++) {
            r += vs[i];
        }
        
        return r;
    }
};