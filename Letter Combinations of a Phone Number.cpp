class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, string> dict ({
                {1, ""}, 
                {2, "abc"},
                {3, "def"},
                {4, "ghi"},
                {5, "jkl"},
                {6, "mno"},
                {7, "pqrs"},
                {8, "tuv"},
                {9, "wxyz"},
                {0, " "}
        });
        
        vector<string> r;
        
        
        r.push_back(string(""));
        
        if (digits.size() == 0) return r;

        
        for_each(digits.begin(), digits.end(), [&dict, &r](const char &c){
        
            string value = dict[c - '0'];
            int size = r.size();
            
            for (int i = 0; i < size; i++) {
                
                string t = r[i];
                
                for (int j = 0; j < value.size(); j++) {
                    
                    t.push_back(value[j]);
                    r.push_back(t);
                    t.pop_back();
                }
                
            }
            while (size--) {
                r.erase(r.begin());
            }
            
        });
        
        return r;
    }
};