class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> pathes;
        string r;
        
        if (path.size() <= 1) {
            r.push_back('/');
            return r;
        }
        
        int i = 0;
        
        string temp;
        
        while (i < path.size()) {
            if (path[i] == '/') {
                if (temp.size() > 0) {
                    
                    if (temp == "..") {
                        if (!pathes.empty()) pathes.pop_back();
                    }
                    else if (temp != ".") {
                        pathes.push_back(temp);
                    }
                    
                    temp.clear();
                }
            }
            else
                temp.push_back(path[i]);
                
            i++;
        }
        
        if (temp.size() > 0) {
                    if (temp == "..") {
                        if (!pathes.empty()) pathes.pop_back();
                    }
                    else if (temp != ".") {
                        pathes.push_back(temp);
                    }
        };
        
        for (int i = 0; i < pathes.size(); i++) {
            string t = pathes[i];
            r.push_back('/');
            r += t;
        }
        
        if (r.size() == 0) r.push_back('/');
        
        return r;
    }
};