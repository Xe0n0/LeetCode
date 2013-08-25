class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        if (start == end) return 0;

        queue<pair<string, int> > q;
        
        q.push(make_pair(start, 1));
        
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            
            string temp = p.first;
            
            if (temp == end)
                return p.second;
                                        
            for (int i = 0; i < temp.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    
                    char t_c = temp[i];
                    if (t_c != c) {
                        temp[i] = c;
                        if (dict.find(temp) != dict.end()) {
                            q.push(make_pair(temp, p.second+1));
                            dict.erase(temp);
                        }
                        temp[i] = t_c;
                    }
                    
                }
            }
            
        }
        
        return 0;
        
    }
};