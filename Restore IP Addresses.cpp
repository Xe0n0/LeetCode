class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        restoreAt(s, 0, 4, string(""), r);
        return r;
    }
private:
    void restoreAt(string &s, int idx, int count,
        string temp, vector<string> &r){
            
            if (count == 0 and idx >= s.size()) {
                r.push_back(temp);
                return;
            }
            
            if (s.size() - idx > count * 3 || s.size() - idx < count) return;
            
            if (temp.size() > 0)
                temp.push_back('.');
                
            for (int i = 0; i < 3; i++) {
                if (idx+i+1 > s.size()) break;
                
                if (i > 0 && s[idx] == '0') break;
                
                string t = s.substr(idx, i+1);
                
                int num = stoi(t);
                
                if (0 <= num and num <= 255){
                    string temp2 = temp;
                    temp2.append(t);
                    restoreAt(s, idx+i+1, count-1, temp2, r);
                }
                
            }            
    }
};