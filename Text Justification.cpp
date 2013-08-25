class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        vector<string> temp;
        int len = 0;
        if (words.size() == 0) return r;
        
        int first_space;
        
        for (int i = 0; i < words.size(); i++) {
            
            if (len == 0 && words[i].size() > L) return r;
            
            if (len == 0) {
                temp.push_back(words[i]);
                len += words[i].size();
            }
            
            else if (len + words[i].size() + 1 <= L) {
                temp.back().push_back(' ');
                temp.push_back(words[i]);
                len += 1 + words[i].size();
            }
            else {
                int idx = 0;
                while (len < L) {
                    
                    if (temp.size() > 1)
                        idx %= (temp.size() - 1);
                    else
                        idx = 0;
                    
                    temp[idx].push_back(' ');
                    idx++;
                    len++;
                }
                string t;
                for (int i = 0; i < temp.size(); i++) {
                    t.append(temp[i]);
                }
                r.push_back(t);
                temp.clear();
                len = 0;
                i--;
            }
        }
        
        if (temp.size() > 0) {
            int idx = 0;
            while (len < L) {
                temp.back().push_back(' ');
                len++;
            }
            string t;
            for (int i = 0; i < temp.size(); i++) {
                t.append(temp[i]);
            }
            r.push_back(t);
        }
        
        return r;
    }
};