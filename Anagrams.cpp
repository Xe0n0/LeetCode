//1. be careful while loop continue may drop loop-variable increase
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, vector<string>> groups;
        
        for_each(strs.begin(),
            strs.end(),
            [&groups](const string& str){
                    string key = str;
                    sort(key.begin(), key.end());
                    groups[key].push_back(str);
                
            });
            
        auto it = groups.begin();
        
        vector<string> r;
        
        while (it != groups.end()) {
            
            if (it->second.size() > 1) {
                r.resize(r.size() + (it->second).size());
                copy((it->second).begin(), (it->second).end(), r.end() - (it->second).size());
            
            }
            
            it++;
            
        }
        
        return r;
    }
private:
    string keyOfString(string &str) {
        
        string key = str;
        sort(key.begin(), key.end());
        
        return key;
    }
};