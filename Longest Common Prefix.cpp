class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int prefix_until = 0;
        
        if (strs.size() <= 0) return string("");
        
        bool should_stop = false;
        
        while (!should_stop) {
            if (strs[0].size() <= prefix_until) {
                should_stop = true;
                break;
            }
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= prefix_until)
                {
                    should_stop = true;
                    break;                
                };
                    
                if (strs[i][prefix_until] == strs[0][prefix_until])
                    continue;
                else {
                    should_stop = true;
                    break;
                }
            }
            if (!should_stop)
                prefix_until++;
        }
        
        return strs[0].substr(0, prefix_until);
    }
};